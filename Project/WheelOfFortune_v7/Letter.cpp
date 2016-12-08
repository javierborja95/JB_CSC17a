/* File:   Letter.h
 * Author: Javier B
 * Created on December 5, 2016, 6:08 PM
 * Purpose: Class Specification File for Letter class
 */

//User Libraries
#include "Letter.h"

//Initializing static variable
int Letter::calls=0;

Letter::Letter(char a){
    //Process Data
    letter=a;
    isUsed=false;
    calls++;
}

Letter::Letter(){
    //Process Data
    letter=' ';
    isUsed=false;
    calls++;
}