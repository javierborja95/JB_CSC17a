/* File:   Letter.h
 * Author: Javier B
 * Created on December 5, 2016, 6:08 PM
 * Purpose: Class Specification File for Letter class
 */

#ifndef LETTER_H
#define LETTER_H

//System Libraries
#include <iostream>  //Input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries

class Letter{
    protected:
        char letter;
        bool isUsed;
        //static int calls;
    public:
        //Constructors
        Letter(char a){
            letter=a;
            isUsed=false;
            //calls++;
        }
        Letter(){
            letter=' ';
            isUsed=false;
            //calls++;
        }
        
        //Mutators
        void setChar(char a)
        {letter=a;}
        void use()
        {isUsed=true;}
        
        //Accessors
        char getLetter(){return letter;}
        bool isLtUsed(){return isUsed;}
        //static int callUse(){return calls;}
        virtual void display(){cout<<letter;}
};

#endif /* LETTER_H */

