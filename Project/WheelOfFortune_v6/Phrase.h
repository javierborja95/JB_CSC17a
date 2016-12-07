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
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Letter.h"

class Phrase: public Letter{
    public:
        Letter *arr; //Array of letters
        int size;    //Size of array
    public:
        //Constructor
        Phrase(unsigned int,string);
        
        //Destructor
        ~Phrase();
        
        //Member Functions
        void display() override;
};

#endif /* PHRASE_H */

