/* File:   Keyboard.h
 * Author: Javier B
 * Created on December 6, 2016, 12:12 PM
 * Purpose: Class Specification File for Keyboard class
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

//System Libraries
#include <iostream>  //Input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Letter.h"

//Constants
const int ALPHA=26; //Size of the alphabet

class Keyboard: public Letter{
    private:
        Letter *arr; //Array of letters
    public:
        //Constructor
        Keyboard();
        
        //Destructor
        ~Keyboard();
        
        //Member functions
        void display() override;
};

#endif /* KEYBOARD_H */

