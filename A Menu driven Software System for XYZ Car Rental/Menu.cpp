#include "Menu.h"


// Declaring two lists, a Car Linked list and a Reservation Array list.
Linkedlist carList = Linkedlist();
ArrayList resList = ArrayList();


// Menu function to display the menu to the user.
void Menu::
    runMenu(){
    for(;;){
        printMenu();
    }
    }

// Function Definition that displays the Menu screen and prompts user to enter a selection.
void Menu::
    printMenu(){
    int menuchoice;
    Menu menu;

    cout << "\n\t\t\t\t\tXYZ Car Rental" << endl;
    cout << "\nHi, Enter a selection to Continue: " << endl;
    cout << "\n1. List all Cars" << endl;
    cout << "2. Add Car to Inventory" << endl;
    cout << "3. Remove Car from Inventory" << endl;
    cout << "4. List all Reservations" << endl;
    cout << "5. Add a Reservation" << endl;
    cout << "6. Cancel Reservation" << endl;
    cout << "7. Exit" << endl;
    cout << "\nEnter a selection: ";
    cin >> menuchoice;

    switch(menuchoice){
    case 1:
        // Lists all Cars in the list.
        menu.listCars();
        break;
    case 2:
        // Adds the Car to the list.
        menu.addCar();
        break;
    case 3:
        // Removes the Car from the list.
        menu.removeCar();
        break;
    case 4:
        // Lists all Reservations booked in the Program.
        menu.listRes();
        break;
    case 5:
        // Adds a Reservation to the list.
        menu.addRes();
        break;
    case 6:
        // Cancels a booked Reservation.
        menu.cancelRes();
        break;
    case 7:
        // Exits out of the Program.
        cout << "\nThank you for visiting XYZ Car Rental!" << endl;
        exit(0);
        break;
    default:
        break;
    }
    }

// Function to list all Cars in the Car Linked List.
void Menu::
    listCars(){
        cout << carList << endl;
    }

// Function to add a Car to the Car Linked List.
void Menu::
    addCar(){
    // Declaring Variables.
    Car c;
    string inpNum;
    string inMake;
    string inModel;
    vehicleType inType;
    double inppd;
    bool availability = true;

    // Prompts the user for the Car details to be added to the list.
    cout << "\nPlease Enter the following Information:" << endl;
    cout << "\nCar Plate Number: ";
    cin >> inpNum;
    c.getplateNumber() = inpNum;
    cout << "Car Make: ";
    cin >> inMake;
    cout << "Car Model: ";
    cin >> inModel;

    cout << "Vehicle Type (0 = Sedan, 1 = SUV, 2 = Exotic): ";
    cin >> inType;
    while(inType < vehicleType::Sedan || inType > vehicleType::Exotic){
        cout << "Invalid Input." << endl;
        cout << "Enter Vehicle Type Again: ";
        cin >> inType;
    }

    cout << "Price per day to rent: $";
    cin >> inppd;

    c = Car(inpNum, inMake, inModel, inType, inppd, availability);
    carList.putCar(c);

    cout << "\nCar added to the list." << endl;
    }

// Function to remove a Car from the Car Linked list.
void Menu::
    removeCar(){
    Car c;
    string inpNum;

    // Prompts the user for Car Plate Number and removes the Car which matches the plate number.
    cout << "\nPlease input the License Plate Number of the Car you would like to remove: ";
    cin >> inpNum;
    carList.deleteCar(Car(inpNum, " ", " ", Sedan, 0, true));

    cout << "\nCar removed from the list." << endl;
}

// Function to list all the Reservations in the Reservation Array list to the user.
void Menu::
    listRes(){
    cout << resList << endl;
    }

// Function to add a Reservation to the Reservation Array list.
void Menu::
    addRes(){
    string name;
    int choice;
    int cancel;
    string plateNumber;
    Car c;

    // Prompts the user for details and adds the Reservation to the Reservation Array list.
    cout << "\nPlease Enter your Name: ";
    cin >> name;
    carList.printAvailCar(cout);
    cancel = carList.getLength() + 1;
    cout << cancel << " Cancel" << endl;
    cout << "\nEnter the Car number you would like to book for Reservation: ";
    cin >> choice;
    if (choice == cancel) return;
    else{
        c = carList.getCarAtIndex(choice);
        carList.deleteCar(Car(c.getplateNumber(), " ", " ", Sedan, 0, true));
        carList.putCar(Car(c.getplateNumber(), c.getMake(), c.getModel(), c.getType(), c.getppd(), false));
        plateNumber = c.getplateNumber();
        Reservation r(name, plateNumber);
        resList.rPutItem(r);

    cout << "\nReservation added." << endl;
    }
    }

// Function to Cancel a Reservation from the Program.
void Menu::cancelRes(){
    string name;
    Reservation r;
    Car c;
    bool temp = false;

    // Looks up the name under the reservation and cancel the name with the matching string (Not Working Properly).
    cout << "\nEnter the Name under which the Reservation is: ";
    cin >> name;
    r = Reservation(name, "");
    resList.rDeleteItem(resList.rGetItem(r, temp));
    c.setAvailable(true);

    cout << "\nReservation canceled." << endl;
}
