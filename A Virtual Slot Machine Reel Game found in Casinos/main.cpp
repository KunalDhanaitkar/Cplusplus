/*
CSCI 6620 - 01
Data Structures
Spring 2021
Assignment Program 2 - A Virtual Slot Machine Reel Game found in Casinos.
Created by - Kunal Dhanaitkar 00722835
             Department of Computer Science
*/


// Header files.
#include "SlotMachine.h"
#include <iomanip>

using namespace std;

// Function Prototype, also known as Function Declaration.
void printMachine(int total, int cost, SlotMachine* sm);


/* Main Function */
int main() {

   // User start game with initially $100
   int total = 100;     // user money
   const int cost = 1;  // each spin cost $1

   // Creating a slot machine
   SlotMachine *sm = new SlotMachine();

   // Spinning the slot machine at start
   sm->spin();

   // Prints the welcome message
   cout << "Hi, Welcome to the CASINO\n" << endl;

   // Prints the slot machine
   printMachine(total,cost,sm);

   // Asks the user for option till option is exit
   int option = 0;
   while (option != 2) {
       cout << "\nSelect option:" << endl;
       cout << "1. play" << endl;
       cout << "2. exit" << endl;
       cin >> option;

       if (option == 1) {

           // Check if user have enough balance
           if (total > cost) {

               // Lets the user play
               // Spins the machine once.
               sm->spin();

               // Payout
               int payout = sm->payout();

               // Checks if its a Jackpot
               if (payout == 500) {
                    // Prints Jackpot
                   cout << "JACKPOT!" << endl << endl;
               }

               // Remove the cost from balance
               total = total - cost;

               // Adds winnings to total balance
               total = total + payout;

               // Prints machine
               printMachine(total, cost, sm);

               // Prints winnings
               cout << "\nYou just won $" << payout << endl;
           }
           else {

               // Prints this if user is out of money
               cout << "Sorry, you don't have enough money!" << endl;
           }
       }
   }

   return 0;
}

// Function which prints the Slot Machine to the User.
void printMachine(int total, int cost, SlotMachine* sm) {
   cout << "----------------" << endl;
   cout << "| Slot Machine |" << endl;
   cout << "----------------" << endl << endl;
   cout << "|  " << sm->getR1prev();
   cout << "   " << sm->getR2prev();
   cout << "   " << sm->getR3prev() << "  |" << endl;
   cout << "|> " << sm->getR1();
   cout << "   " << sm->getR2();
   cout << "   " << sm->getR3() << " <|" << endl;
   cout << "|  " << sm->getR1next();
   cout << "   " << sm->getR2next();
   cout << "   " << sm->getR3next() << "  |" << endl << endl;
   cout << "----------------" << endl;
   cout << "| spin cost $" << cost << " |" << endl;
   cout << "| balance $" << setw(4) << left << total << "|" << endl;
   cout << "----------------" << endl;
}

