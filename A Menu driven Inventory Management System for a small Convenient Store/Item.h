/*Header File for the Item class.*/
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class Item{

// Private Variables
private:
    unsigned long id;
    string name;
    float cost;
    int quantity;

//Public Variables
public:
    //Constructor for the Item
    Item(unsigned long id, string name, float cost, int quantity);
    Item()=default;
    void read();
    void printItem();

     //Accessor Setters
    void setId(unsigned long id){this->id=id;};
    void setName(string name){this->name=name;};
    void setCost(float cost){this->cost=cost;};
    void setQuantity(int quantity){this->quantity=quantity;};

    //Accessor Getters
    unsigned long getId(){return id;};
    string getName(){return name;};
    float getCost(){return cost;};
    int getQuantity(){return quantity;};

    void printItem(ofstream& out);

};

#endif // ITEM_H_INCLUDED
