#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

// Header files for the Reservation class.
#include <iostream>
#include <string>
#include "enums.h"

using namespace std;

class Reservation{
private:
    string name;
    string carRented;

public:
    Reservation():name(" "), carRented(" "){};
    Reservation(string name, string cRented);
    string getName(){return name;}
    string getRentedCar(){return carRented;}
    Relation compareTo(Reservation other){
    if (carRented < other.getRentedCar())
        return Relation::lessThan;
    else if (carRented == other.getRentedCar())
        return Relation::equalTO;
    return Relation::greaterThan;
    }
};

ostream& operator << (ostream& out, Reservation r);

#endif // RESERVATION_H_INCLUDED
