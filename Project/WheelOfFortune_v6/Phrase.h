/* File:   Phrase.h
 * Author: Javier B
 * Created on December 6, 2016, 12:12 PM
 * Purpose: Class Specification File for Phrase class
 */

#ifndef PHRASE_H
#define PHRASE_H

//System Libraries
#include <iostream>  //Input/Output
#include <string>    //String Library
#include <memory>    //Unique pointers
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Letter.h"

class Phrase: public Letter{
    public:
        Letter *arr; //Array of letters
        int size;    //Size of array
    public:
        //Constructor
        Phrase();
        
        //Destructor
        ~Phrase();
        
        //Member Functions
        void setArr(unsigned int,string);
        void display() override;
        
        //Accessors
        char getLetter(int);
        bool getUsed(int);
};

#endif /* PHRASE_H */

