/**
   @file sleeper.c
   @author Michael Warstler (mwwarstl)
   File implements 2 methods for displaying output statements for riders walking around in a theme
   park or actively riding bumper cars.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sleeper.h"

/**
   Message displayed for a rider currently riding a car.
   @param riderId is id for current rider.
   @param carId is id for car used by current rider.
*/
void rideTime( int riderId, int carId )
{
   int seconds = ( rand() % 10 ) + 1 ;
   printf ( "Rider %d is now riding in car %d. \n", riderId, carId );
   sleep (seconds); 
}

/**
   Message displayed for a rider walking around the park.
   @param riderId is id for the current rider.
*/
void walkAroundTime( int riderId )
{
   int seconds = (rand() % 10) + 1 ;
   printf ( "Rider %d is walking around the park. \n", riderId );
   sleep (seconds);
}