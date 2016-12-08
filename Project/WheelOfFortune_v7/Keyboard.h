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
        
        //Mutators
        void use(int i)
        {arr[i].use();}
        
        //Accessors
        bool isUsed(int i)
        {return arr[i].isLtUsed();}
        char getChar(int i)
        {return arr[i].getLetter();}
        
        //Member functions
        void display() override;
        void setArr();
};

#endif /* KEYBOARD_H */