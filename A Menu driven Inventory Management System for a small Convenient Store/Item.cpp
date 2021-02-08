#include <iostream>
#include <string>
#include "Item.h"
#include "itemContainer.h"

using namespace std;

//Constructor for Item class.
Item::Item(unsigned long id, string name, float cost, int quantity){
    this->id=id;
    this->name=name;
    this->cost=cost;
    this->quantity=quantity;
}

//Function to read and store the details of an item in the list.
void Item::read(){
    unsigned long tid;
    string tname;
    float tcost;
    int tquantity;

    cout << "\nEnter the Item ID: ";
    cin >> tid;
    setId(tid);

    cout << "Enter the Item Name: ";
    getline(cin>>ws, tname);
    setName(tname);

    cout << "Enter the Item Cost: ";
    cin >> tcost;
    setCost(tcost);

    cout << "Enter the Item Quantity: ";
    cin >> tquantity;
    setQuantity(tquantity);
}

//Function to print out the details of an item onto the screen.
void Item::printItem(){
	cout << "\nItem ID: " << getId() << endl;
	cout << "Item Name: " << getName() << endl;
	cout << "Item Cost: " << getCost() << endl;
	cout << "Item Quantity: " << getQuantity() << endl;
}

//Function to print the item list on a .txt file stored on the hard drive.
void Item::printItem(ofstream& out){
    out<<name<<", " << id << ", " << cost << ", " << quantity << endl;
}
