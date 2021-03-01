#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// Declaring a Relation in order to operate on the Reservation list.
enum class Relation {lessThan, equalTO, greaterThan};

// Declaring vehicle types.
enum vehicleType {Sedan, SUV, Exotic};

// Function to perform an explicit type conversion.
inline istream& operator >> (istream& in, vehicleType &t)
{
    int val;
    if (in >> val){
        t = static_cast<vehicleType>(val);
    }
    return in;
}

#endif // ENUMS_H_INCLUDED
