#include "ReservationArrayList.h"

// Function which displays the Reservation list to the user one by one.
ostream& operator << (ostream& out, ArrayList& a){
a.rResetList();
out << "\nReservation List: \n";
for(int i = 0; i < a.rGetLength(); ++i){
    int index = 1;
    out << index + i << " " << a.rGetNextItem();
}
out << endl;
return out;
}

// Function to empty the Reservation Array list.
void ArrayList::rMakeEmpty(){
length = 0;
}

// Function to add a Reservation to the Reservation Array list.
void ArrayList::
    rPutItem(Reservation res){
    data[length++] = res;
    }

// Function to get a Reservation from the Reservation Array list.
Reservation ArrayList::rGetItem(Reservation res, bool& found){
found = false;
for (int i = 0; i < length; ++i){
    if (data[i].compareTo(res) == Relation::equalTO){
        res = data[i];
        found = true;
        break;
    }
}
return res;
}

// Function to remove a reservation from the Reservation Array list.
void ArrayList::
    rDeleteItem(Reservation res){
    for (int i = 0; i < length ; ++i){
        if (data[i].compareTo(res) == Relation::greaterThan)
            res = data[--length];
    }
    }

// Function to reset the Reservation Array list.
void ArrayList::
    rResetList(){
    currentPos = 0;
    }

// Function to get the next item in the Reservation Array list.
Reservation ArrayList::rGetNextItem(){
if (currentPos < length)
    return data[currentPos++];
throw "Out of Range";
}

// Function to get the length of the Reservation Array list.
int ArrayList::rGetLength(){
    return length;
}

