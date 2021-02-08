/*
CSCI 6610 - 03
Intermediate Programming: C/C++
Fall 2020
Assignment 3 - A Menu driven Inventory Management System for a small Convenient Store with File Store and Dynamic Arrays.
Created by - Kunal Dhanaitkar 00722835
             Department of Computer Science
*/

//Header files.
#include <iostream>
#include "Item.h"
#include "itemContainer.h"

//Function Prototype.
int menuSelection(void);

using namespace std;

/*Main Function*/
int main()
{
    //Object and Variable Declaration.
    itemContainer itemList;         //Initialize using the default constructor.
    int select;

    //Calling function to load the data saved in a .txt file stored on the hard drive.
    itemList.loadDataFromFile();
    do{
        select = menuSelection();           //Calling menuSelection Function to display menu and prompt user to enter a selection.
        //Conditional Statements to perform after the selection from the menu above.
        switch(select){
            case 1:
                //Calling function to add an item to the list.
                itemList.addItem();
                break;

            case 2:
                //Calling function to print all the items on the list.
                itemList.printItem();
                break;

            case 3:
                //Calling function to find an item on the list using its ID.
                itemList.findItemID();
                break;

            case 4:
                //Calling function to find an item on the list using its Name.
                itemList.findItemName();
                break;

            case 5:
                //Exits the program.
                cout << "\nGood Bye!" << endl;
                break;

            default:
                /*If user enters any number that is not in the selection menu.*/
                cout << "\nError: Invalid selection. Please try again!" << endl;
        }
    }while(select !=5);

    //Calling function to write the data entered by the user on a .txt file stored on the hard drive.
    itemList.writeToFile();

    return 0;
}

//Function Definition that displays the Menu screen and prompts user to enter a selection.
int menuSelection(void){
    int select;

    cout << "\t\t\t\t\tInventory Management System Menu\n" << endl;
    cout << "1. Add new item" << endl;
    cout << "2. Print item list" <<endl;
    cout << "3. Find item by ID" <<endl;
    cout << "4. Find item by name" <<endl;
    cout << "5. Quit" <<endl;
    cout << "\nSelect: ";
    cin >> select;
    return select;
}
