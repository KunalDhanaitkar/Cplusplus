#ifndef SLOTMACHINE_H_INCLUDED
#define SLOTMACHINE_H_INCLUDED

// Header files for the SlotMachine class
#pragma once
#include "Reel.h"
#include <iostream>

class SlotMachine {
// Private Variables
private:
   Reel* r1;    // reel 1, left reel
   Reel* r2;    // real 2, middle reel
   Reel* r3;    // reel 3, right reel

// Public Variables
public:
   SlotMachine();       // constructor
   ~SlotMachine();      // destructor
   void spin();         // spin the reels and get head of each reel to random position
   int payout();        // return amount of payout for given combination
   char getR1prev();    // return previous element from reel head
   char getR1();        // return head of reel
   char getR1next();    // return next element from reel head
   char getR2prev();    // return previous element from reel 2's head
   char getR2();        // return head of reel 2
   char getR2next();    // return next element from reel 2's head
   char getR3prev();    // return previous element from reel 3's head
   char getR3();        // return head of reel 3
   char getR3next();    // return next element from reel 3's head

};

#endif // SLOTMACHINE_H_INCLUDED
