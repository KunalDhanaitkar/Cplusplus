#ifndef RESERVATIONARRAYLIST_H_INCLUDED
#define RESERVATIONARRAYLIST_H_INCLUDED

// Defining max item in the list to be 100.
#define MAX_ELEM 100
#include "Reservation.h"
#include "Car.h"

class ArrayList{
private:
    int currentPos;
    int length;
    Reservation data[MAX_ELEM];

public:
    ArrayList():currentPos(0), length(0){}
    void rMakeEmpty();
    void rPutItem(Reservation res);
    Reservation rGetItem(Reservation res, bool& found);
    void rDeleteItem(Reservation res);
    void rResetList();
    Reservation rGetNextItem();
    int rGetLength();
};

ostream& operator << (ostream& out, ArrayList& a);

#endif // RESERVATIONARRAYLIST_H_INCLUDED
