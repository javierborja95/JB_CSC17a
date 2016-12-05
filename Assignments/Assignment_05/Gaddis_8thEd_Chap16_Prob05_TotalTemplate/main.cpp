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
#include "total.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int size;
    int   a;
    short b;
    float c;
    
    //Input Data
    cout<<"Input amount of ints you want to add: ";
    cin>>size;
    a=total<int>(size);
    cout<<"Input amount of shorts you want to add: ";
    cin>>size;
    b=total<short>(size);
    cout<<"Input amount of floats you want to add: ";
    cin>>size;
    c=total<float>(size);
    //Process Data
    
    //Output Data
    cout<<"int a total = "<<a<<endl;
    cout<<"short b total = "<<b<<endl;
    cout<<"float c total = "<<c<<endl;
    
    return 0;
}