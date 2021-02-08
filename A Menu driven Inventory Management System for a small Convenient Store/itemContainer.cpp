#include <fstream>
#include "Item.h"
#include "itemContainer.h"

//Constructor for the initial allocation.
itemContainer::itemContainer(){
    count=0;
    max=1;// initialize current allocation
    itemList=new Item[max];
}

//Destructor to free allocated array in memory.
itemContainer::~itemContainer(){
    delete[] itemList;
}

//Function to expand allocated array in memory.
void itemContainer::grow(){
    Item* temp = itemList; //hang on the to the old array until copy
    max *= 2; //double the allocation
    itemList = new Item[max]; //expand allocation
    for(int i=0;i<count;++i)
        itemList[i] = temp[i]; //copy info into the new array
    delete[] temp; //Recycle(free) old array
}

//Function to add items to the list.
void itemContainer::addItem(){
     //If no memory available, calls the grow() function.
     if(count >= max){
        grow();
    }
    //Else adds the item to the list.
    itemList[count].read();
    ++count;
}

//Function to print out an item on the list onto the screen.
void itemContainer::printItem(){
    for(int i=0; i<count; ++i){
        itemList[i].printItem();
    }
}

//Function to find an item on the list using its ID.
void itemContainer::findItemID(){
    unsigned long id;

    cout << "\nEnter the Item ID to be found: ";
    cin >> id;
    //Checks whether the ID entered by the user is on the list.
    for(int i=0; i<count; i++){
        if(itemList[i].getId()==id){
            cout << "\nThe Item details are: \n";
            itemList[i].printItem();
            break;
        }else if (i >= count -1 && itemList[i].getId() != id){
            //Prints out an error if the id entered by user is not on the list.
            cout << "\nError: Item not Found!" << endl;
            break;
        }
    }
}

//Function to find an item on the list using its Name.
void itemContainer::findItemName(){
    string name;
    cout << "\nEnter the name to be searched: ";
    getline(cin>>ws, name);
    //Checks whether the Name entered by the user is on the list.
    for(int i=0; i<count; i++){
        if(itemList[i].getName()==name){
            cout << "\nThe Item details are: \n";
            itemList[i].printItem();
            break;
        }else if(i >= count -1 && itemList[i].getName() != name){
            //Prints out an error if the Name entered by the user is not on the list.
            cout << "\nError: Item not found!" << endl;
            break;
        }
    }
}

//Function to write the Item List in a .txt file on the hard drive.
void itemContainer::writeToFile(){
	ofstream dataFile (DATAFILE);  //create an input stream for the input file
	if (dataFile.is_open()) {  //test if the output file successfully opened
        for(int i=0; i<count;++i){
            itemList[i].printItem(dataFile);
        }
    }else{
	    //Print an error message to error stream, in console
		cerr << "Can't open " << DATAFILE << " for output.\n" << endl;
    }
    dataFile.close();
}

//Function to load the Item List stored in the .txt file.
void itemContainer::loadDataFromFile(){
    string name;
    unsigned long id;
    float cost;
    int quantity;
	ifstream dataFile (DATAFILE);  //create an input stream for the input file
	if (dataFile.is_open()) {  //test if the output file successfully opened
		while(true){
		    getline(dataFile>>ws, name, ','); //',' character is read and ignored automatically
		    dataFile >> id;
		    dataFile.ignore(1); //read and ignore the ',' character
		    dataFile >> cost;
		    dataFile.ignore(1);
		    dataFile >> quantity;
            if(dataFile.good()){
                //process data
                Item temp(id, name, cost, quantity);
                addItem(temp);
            }
            else if(dataFile.eof()){
                break;         //we have reached the end of file and can break the loop
            }
            else{
                cout << "Error: File corrupted or access issue!\n" << endl;
                break;
            }
		}
	}else{
	    //Print an error message to error stream, in console
		cerr << "Can't open " << DATAFILE << " for input.\n" << endl;
    }
    dataFile.close();
}

void itemContainer::addItem(const Item& item){
    if(count >= max){
        grow();
    }
    itemList[count]=item;
    ++count;
}
