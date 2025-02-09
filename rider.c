/**
   @file rider.c
   @author Michael Warstler (mwwarstl)
   File holds information regarding a Rider's functionality. A rider walks around, gets in line,
   rides a bumper car, then returns the car.
*/   
#include <stdlib.h>
#include <stdio.h>
#include "rider.h"
#include "sleeper.h"
#include "coordinator.h"

/**
   Contains behavior for what a Rider (thread) will do.
   Rider walks around, then gets in line, then rides the bumper car, then returns the car.
   @param id is a void pointer (should be an int representing the rider's id) 
*/
void rider( int riderId )
{    
    // Runs continuosly so rider is walking around after returning the car and then entering the line again.
    // Ends when simulation time in coordinator.c runs out.
    while ( 1 ) {
        walkAroundTime( riderId );   // rider is walking around.
        int carId = getInLine();    // rider gets in line - car assigned to them.
        rideTime( riderId, carId ); // rider is currently riding.
        
        // Return car
        printf( "Rider %d returned car %d \n", riderId, carId );
        returnCar( carId ); // return carId once rider is finished.
    }
}

