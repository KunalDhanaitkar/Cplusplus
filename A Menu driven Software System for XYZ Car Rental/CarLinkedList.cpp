#include "CarLinkedList.h"

// Function to print all Cars in the System to the user one by one.
ostream& operator << (ostream& out, Linkedlist& l){
    l.resetList();
    out << "\nAll Cars: \n" << endl;
    for(int i = 0; i < l.getLength(); ++i){
        int index = i;
        out << index + 1 << " " << l.getNextCar();
    }
    out << endl;
    return out;
}

// Function to empty the Car linked list.
void Linkedlist::
    makeEmpty(){
    Node * temp;
    while (head != nullptr){
        temp = head;
        head = head -> next;
        delete temp;
    }
    length = 0;
    }

// Function to add a new node for the added Car.
void Linkedlist::
    putCar(Car Car){
    Node * temp = new Node;
    temp -> data = Car;
    temp -> next = head;
    head = temp;
    length++;
    }


// Function which looks up for a specific Car in the Car linked list.
Car& Linkedlist::
    getCar(Car Car, bool& found){
    found = false;
    Node * temp = head;
    while (temp != nullptr){
        if (temp -> data.compareTo(Car) == Relation::equalTO){
            found = true;
            Car = temp -> data;
            break;
        }
        temp = temp -> next;
    }
    return Car;
    }

// Function to delete a Car for the Car linked list.
void Linkedlist::
    deleteCar(Car Car){
    if (Car.getAvailable() == false){
        cout << "\nA user has rented it." << endl;
        return;
    }
    if (head == nullptr){
        cout << "\nA user has rented it." << endl;
        return;
    }
    Node * temp;
    if (head -> data.compareTo(Car) == Relation::equalTO){
        temp = head -> next;
        delete head;
        head = temp;
        length--;
    }
    else{
        temp = head;
        while (temp -> next != nullptr){
            if (temp -> next -> data.compareTo(Car) == Relation::equalTO){
                Node * temp2 = temp -> next;
                temp -> next = temp -> next -> next;
                delete temp2;
                length--;
                return;
            }
            temp = temp -> next;
        }
    }
    }

// Function to reset Car linked list
void Linkedlist::
    resetList(){
    currentPos = NULL;
}

// Function to get the next Car in the Car linked list.
Car Linkedlist::
    getNextCar(){
    if (currentPos == NULL)
        currentPos = head;
    else
        currentPos = currentPos -> next;
    return currentPos -> data;
    }

// Function to get a Car from its index.
Car& Linkedlist::getCarAtIndex(int index){
currentPos = head;
for (int i = 0; i < index; i++){
    currentPos = head -> next;
}
return currentPos -> data;
}

// Function to get the length of Car linked list.
int Linkedlist::getLength(){
    return length;
}

// Function to print all available Cars that are available for booking.
int Linkedlist::
    printAvailCar(ostream& out){
    resetList();
    out << "\nAvailable Cars: \n" << endl;
    for (int i = 0; i < getLength(); ++i){
        int index = 1;
        out << index + i << " ";
        Car temp = getCarAtIndex(index);
        if (temp.getAvailable() == true)
            temp.printAvailable(out);
    }
    out << endl;
    return 0;
    }

// Function to empty the Car linked list.
Linkedlist::
    ~Linkedlist(){
    makeEmpty();
}
