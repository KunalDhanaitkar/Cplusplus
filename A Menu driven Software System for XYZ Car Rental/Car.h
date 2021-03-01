#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

// Header files for the Car class.
#include "enums.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Car{
// Protected variables
protected:
    string plateNumber;
    string make;
    string model;
    vehicleType VType;
    double pricePerDay;
    bool isAvailable = false;

// Public variables
public:
    Car():plateNumber{" "}, make{" "}, model{" "}, VType(), pricePerDay{0}, isAvailable(true){}
    Car(string pNum, string make, string model, vehicleType VType, double ppd, bool isAvail);
    ostream& print(ostream& out);
    string getplateNumber(){return plateNumber;}
    string getMake(){return make;}
    string getModel(){return model;}
    vehicleType getType(){return VType;}
    double getppd(){return pricePerDay;}
    void setAvailable(bool available){isAvailable = available;}
    bool getAvailable(){return isAvailable;}
    ostream& printAvailable(ostream& out);
    Relation compareTo(Car other){
        if(plateNumber<other.getplateNumber())
            return Relation::lessThan;
        else if(plateNumber == other.getplateNumber())
            return Relation::equalTO;
        return Relation::greaterThan;
    }
};

ostream& operator << (ostream& out, Car c);


#endif // CAR_H_INCLUDED
