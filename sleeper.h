/**
   @file sleeper.h
   @author Michael Warstler (mwwarstl)
   File provides 2 methods for displaying output statements for riders walking around in a theme
   park or actively riding bumper cars.
*/

/**
   Message displayed for a rider currently riding a car.
   @param riderId is id for current rider.
   @param carId is id for car used by current rider.
*/
void rideTime(  int riderId, int carId );

/**
   Message displayed for a rider walking around the park.
   @param riderId is id for the current rider.
*/
void walkAroundTime( int riderId );