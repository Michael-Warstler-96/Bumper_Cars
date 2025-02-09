/**
   @file coordinator.c
   @author Michael Warstler (mwwarstl)
   File handles coordination of multiple riders in process of riding bumper cars or 
   waiting around in a park. 
   
   ***********************************************
   ***********************************************
   COMPILE COMMAND: Using remote linux machine, my shell command was:           gcc -Wall -std=c99 coordinator.c rider.c sleeper.c -o coordinator -lpthread
   RUN COMMAND:     ./coordinator 5 10 30
   Files in the execution folder includes sleeper.h, sleeper.c, coordinator.h, coordinator.c, rider.h, and rider.c
   ***********************************************
   ***********************************************
*/   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include "rider.h"
#include "coordinator.h"

/** Buffer used to store number of cars available */
int *buffer;
/** Represents the input index for the buffer */
int in;
/** Represents the output index for the buffer */
int out;
/** Represents the buffer size. Number of cars + 1. */
int buffer_size;

/** Thread function. Will designate to rider class */
void * riderAction( void * id );

/**
   Main function starts program of multiple riders waiting for and riding bumper cars.
   @param argc is number of command line arguments.
   @param *argv[] is array of string pointers for command line arguments.
   @return is exit status.
*/
int main( int argc, char *argv[] ) 
{
    // Get the number of cars, riders, and duration for simulation from command line arguments.
    buffer_size = atoi( argv[1] ) + 1; // # of cars + 1 is true buffer size.
    buffer = ( int * )malloc( buffer_size * sizeof( int ) );   // buffer holding enough space for N + 1 cars.
    int numRiders = atoi( argv[2] );
    int duration = atoi( argv[3] );
    
    // Initialize buffer input/output indices.
    in = 0;
    out = 0;
    
    // Produce enough cars to fill the buffer with correct car ids.
    for ( int j = 1; j <= buffer_size - 1; j++ ) {
        returnCar( j );
    }
    printf( "\n\n" );
    
    // Create threads for riders
    pthread_t riders[ numRiders ];
    pthread_attr_t attr; 
    pthread_attr_init(&attr); 
    for ( int i = 1; i <= numRiders; i++ ) {
       pthread_create( &riders[i], &attr, riderAction, &i ); // parameter is the rider's id (1 thru N number of riders)
    }
    
    // JOIN THREADS? - Not needed as the simulation time determines when to stop program.

    // Create thread (or use main) where its purpose is to only sleep for argv[3] seconds then exit.
    sleep( duration );
    return EXIT_SUCCESS;
}

/**
   Called each time a rider wants to get in line. Contains critical section that determines if 
   a car is available (i.e. there is a car identifier currently in buffer). If not, the thread
   is blocked. If there is a car, the car id is returned for the rider thread.
   @return is a car id if a car is available.
*/
int getInLine() 
{
    // CONSUMER
    // Block when no car available (buffer empty - no cars returned)
    while ( in == out ) {
        // do nothing when input = output, when there are no cars available.
    }
    // "Consume" a car from the buffer.
    int carId = buffer[out];
    out = ( out + 1 ) % buffer_size;
    
    return carId;
}

/**
   Returns the car with carId to the queue of available cars. Called once a rider is done with
   the ride/car. Unblocks a rider thread that was waiting inline for a car.
   @param carId is the id for the car being returned.
*/
void returnCar( int carId )
{
    // PRODUCER
    // Place carId in buffer. Using a cars + 1 term instead of cars to more accurately count size of buffer.
    while ( ((in + 1) % buffer_size) == out ) {
        // Do nothing if buffer is currently full. Can't return any more cars.
    }
    // Produce/place current carId into the buffer.
    buffer[in] = carId;
    in = ( in + 1 ) % buffer_size; // increment input index.
}


/**
   Contains behavior for what a Rider (thread) will do.
   Converts parameter to int to represent rider id. Passes this information to rider function.
   @param id is a void pointer (should be an int representing the rider's id) 
*/
void * riderAction( void * id )
{
    // Cast parameter to int.
    int riderId = *( int * ) id - 1;    // added -1 since rider id was going beyond rider count by 1 for some reason.
    
    rider( riderId );
    pthread_exit( NULL );
}