#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/* Header files for the menu class. */
#include "Car.h"
#include "CarLinkedList.h"
#include "Reservation.h"
#include "ReservationArrayList.h"

class Menu{
// Public Variables
public:
    void runMenu();
    void printMenu();
    void listCars();
    void addCar();
    void removeCar();
    void listRes();
    void addRes();
    void cancelRes();
};


#endif // MENU_H_INCLUDED
