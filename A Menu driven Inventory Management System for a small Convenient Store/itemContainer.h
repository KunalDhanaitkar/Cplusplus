/*Header File for the itemContainer class.*/
#ifndef ITEMCONTAINER_H_INCLUDED
#define ITEMCONTAINER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Item.h"
#define DATAFILE "ItemList.txt"

class itemContainer{
//Private Variables
private:
    Item *itemList;
    int max;
    int count;

    void grow();

//Public Variables
public:
    itemContainer();   //Constructor
    ~itemContainer();  //Destructor
    void addItem();
    void printItem();
    void findItemID();
    void findItemName();
    void writeToFile();
    void loadDataFromFile();
    void addItem(const Item& item);
};

#endif // ITEMCONTAINER_H_INCLUDED
