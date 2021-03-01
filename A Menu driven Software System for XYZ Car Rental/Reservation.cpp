#include "Reservation.h"

// Function to display the added Reservation to the user.
Reservation::Reservation(string name, string cRented):name(name), carRented(cRented){}
ostream& operator << (ostream& out, Reservation r){
out << "\nName under Reservation: " << r.getName() << endl;
out << "Rented Vehicle Plate Number: " << r.getRentedCar() << endl;
return out;
}
