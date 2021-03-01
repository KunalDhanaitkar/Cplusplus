#ifndef CARLINKEDLIST_H_INCLUDED
#define CARLINKEDLIST_H_INCLUDED

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

// Declaring a struct for the Linked list.
struct Node{
Car data;
Node * next;
};

class Linkedlist{
private:
    int length;
    Node * currentPos;
    Node * head;

public:
    ~Linkedlist();
    void makeEmpty();
    void putCar(Car Car);
    Car& getCar(Car Car, bool& found);
    void deleteCar(Car Car);
    void resetList();
    Car getNextCar();
    Car& getCarAtIndex(int index);
    int getLength();
    int printAvailCar(ostream& out);
};

ostream& operator << (ostream& out, Linkedlist& l);

#endif // CARLINKEDLIST_H_INCLUDED
