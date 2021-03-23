// Header file for the reel class
#include "Reel.h"

// Initializing the reel head with nullptr
Reel::Reel() {
   // initialize data members
   head = nullptr;
}


Reel::~Reel() {
   // create a iterator
   Node* itr = head;
   while (itr != nullptr) {
       head = head->next; // move head to next node
       delete itr; // delete current node
       itr = head;
   }
}


void Reel::insert(char c) {

   // check if head is nullptr
   if (head == nullptr) {
       // insert new node as head
       head = new Node(c);
   }

   else {
       // create a new node
       Node* n = new Node(c);
       // assign links of nodes to circular list
       n->next = head;
       n->prev = head->prev;
       head->prev->next = n;
       head->prev = n;
       // reassign head
       head = n;
   }
}
