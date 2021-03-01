#include "Car.h"

//Constructor for the Car class.
Car::Car(string pNum, string make, string model, vehicleType VType, double ppd, bool isAvail){
    this -> plateNumber = pNum;
    this -> make = make;
    this -> model = model;
    this -> VType = VType;
    this -> pricePerDay = ppd;
    this -> isAvailable = isAvail;
}

// Function to provide format in which the Cars are displayed.
ostream& operator << (ostream& out, Car c){
vehicleType VType = c.getType();
out << "\nCar Plate No.: " << c.getplateNumber() << endl;
out << "Car Make: " << c.getMake() << endl;
out << "Car Model: " << c.getModel() << endl;
out << "Car Type (0 = Sedan, 1 = SUV, 2 = Exotic): " << VType << endl;
out << "Car Price per day: $" << c.getppd() << endl;
out << "Available: " << c.getAvailable() << endl << endl;
return out;
}

// Function to prove format in which the available Cars are printed.
ostream& Car::
    printAvailable(ostream& out){
    vehicleType VType = getType();
    out << "\nCar Plate No.: " << getplateNumber() << endl;
    out << "Car Make: " << getMake() << endl;
    out << "Car Model: " << getModel() << endl;
    out << "Car Type (0 = Sedan, 1 = SUV, 2 = Exotic): " << VType << endl;
    out << "Car Price per day: $ " << getppd()  << endl;
    out << "Available: " << getAvailable() << endl << endl;
    return out;
    }
