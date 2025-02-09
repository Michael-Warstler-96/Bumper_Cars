/**
   @file rider.h
   @author Michael Warstler (mwwarstl)
   File holds information regarding a Rider's functionality. A rider walks around, gets in line,
   rides a bumper car, then returns the car.
*/  

/**
   Contains behavior for what a Rider (thread) will do.
   Rider walks around, then gets in line, then rides the bumper car, then returns the car.
*/
void rider( int riderId );