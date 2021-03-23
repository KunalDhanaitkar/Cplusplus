#include "SlotMachine.h"

// Initializing all the reels
SlotMachine::SlotMachine() {
   r1 = new Reel();
   r2 = new Reel();
   r3 = new Reel();

   // Adding data to each real
   // Inserting into reel 1
   r1->insert('A');
   r1->insert('B');
   r1->insert('C');
   r1->insert('7');
   r1->insert('A');
   r1->insert('B');
   r1->insert('C');
   r1->insert('A');
   r1->insert('B');
   r1->insert('A');

   // Inserting into reel 2
   r2->insert('A');
   r2->insert('B');
   r2->insert('C');
   r2->insert('7');
   r2->insert('A');
   r2->insert('B');
   r2->insert('C');
   r2->insert('A');
   r2->insert('B');
   r2->insert('A');

   // Inserting into reel 3
   r3->insert('A');
   r3->insert('B');
   r3->insert('C');
   r3->insert('7');
   r3->insert('A');
   r3->insert('B');
   r3->insert('C');
   r3->insert('A');
   r3->insert('B');
   r3->insert('A');
}


// Function to destroy each reel
SlotMachine::~SlotMachine() {
   delete r1;
   delete r2;
   delete r3;
}

// Function to spin each reel randomly
void SlotMachine::spin() {

    int roll = rand() % 100;     // get random number from 0 to 99
    // roll reel 1 for random number times
    for (int i = 0; i < roll; i++) {
        r1->head = r1->head->next;
    }

    // roll reel 2
    roll = rand() % 100;
    for (int i = 0; i < roll; i++) {
        r2->head = r2->head->next;
    }

    // roll reel 3
    roll = rand() % 100;
    for (int i = 0; i < roll; i++) {
        r3->head = r3->head->next;
   }
}

// Function to hold payout information to provide the payout value to the user
int SlotMachine::payout() {

   // Getting data from each reel
   char c1 = r1->head->data;
   char c2 = r2->head->data;
   char c3 = r3->head->data;

   // Checks for hit
   if (c1 == c2 && c2 == c3) {

       if (c1 == 'A') {
           return 6;
       }

       else if (c2 == 'B') {
           return 15;
       }

       else if (c3 == 'C') {
           return 50;
       }

       else {
           return 500;
       }
   }

   else {
       return 0;
   }
}


char SlotMachine::getR1prev() {
   return r1->head->prev->data;
}

char SlotMachine::getR1() {
   return r1->head->data;
}
char SlotMachine::getR1next() {
   return r1->head->next->data;
}

char SlotMachine::getR2prev() {
   return r2->head->prev->data;
}

char SlotMachine::getR2() {
   return r2->head->data;
}
char SlotMachine::getR2next() {
   return r2->head->next->data;
}

char SlotMachine::getR3prev() {
   return r3->head->prev->data;
}

char SlotMachine::getR3() {
   return r3->head->data;
}
char SlotMachine::getR3next() {
   return r3->head->next->data;
}
