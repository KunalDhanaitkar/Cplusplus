#ifndef REEL_H_INCLUDED
#define REEL_H_INCLUDED

// Preprocessor Directive designed to cause the current source file to be included only once in a single compilation.
#pragma once

class Reel {
// Private Variables
private:
   class Node {
   public:
       char data;
       Node* next;
       Node* prev;
       Node(char t) {
           data = t;
           next = this;     // circular list assign next of new node to self
           prev = this;     // circular list assign prev of new node to self
       }
   };

// Public Variables
public:
   Node* head;      // Head of circular list
   Reel();          // Constructor
   ~Reel();         // Destructor
   void insert(char c);     // insert a new node at position of head in the list with given data
};


#endif // REEL_H_INCLUDED
