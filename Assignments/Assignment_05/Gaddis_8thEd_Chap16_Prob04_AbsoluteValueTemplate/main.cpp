/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November , 2016,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "absval.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int    a=-5;
    short  b=-3;
    float  c=-7;
    double d=-9;
    
    //Input Data

    //Process Data
    
    //Output Data
    cout<<"int a = "<<a<<endl<<"Abs value of a = "<<absVal(a)<<endl<<endl;
    cout<<"short b = "<<b<<endl<<"Abs value of b = "<<absVal(b)<<endl<<endl;
    cout<<"float c = "<<c<<endl<<"Abs value of c = "<<absVal(c)<<endl<<endl;
    cout<<"double d = "<<d<<endl<<"Abs value of d = "<<absVal(d)<<endl<<endl;
    
    return 0;
}