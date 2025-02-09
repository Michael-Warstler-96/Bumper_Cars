/**
   @file coordinator.h
   @author Michael Warstler (mwwarstl)
   File handles coordination of multiple riders in process of riding bumper cars or 
   waiting around in a park. 
*/   

/**
   Called each time a rider wants to get in line. Contains critical section that determines if 
   a car is available (i.e. there is a car identifier currently in buffer). If not, the thread
   is blocked. If there is a car, the car id is returned for the rider thread.
   @return is a car id if a car is available.
*/
int getInLine(); 

/**
   Returns the car with carId to the queue of available cars. Called once a rider is done with
   the ride/car. Unblocks a rider thread that was waiting inline for a car.
   @param carId is the id for the car being returned.
*/
void returnCar( int carId );