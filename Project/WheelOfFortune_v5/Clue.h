/* File:   Clue.h
 * Author: Javier B
 * Created on December 5, 2016, 6:21 PM
 * Purpose: Class Specification File for Clue class
 */

#ifndef CLUE_H
#define CLUE_H

//System Libraries
#include <string>    //Strings
#include <iostream>  //Input/Output
#include <fstream>   //File input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries

class Clue{
    private:
        unsigned int categry;
        char phrase[44];     //Max Phrase length
    public:
        //Mutators
        void setCat(unsigned int);
        void setPhrase(string);
        //Accessors
        char getPhrase()
        {return *phrase;}
        //Output
        void showCat();
};

#endif /* CLUE_H */

