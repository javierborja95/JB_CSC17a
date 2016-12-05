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
#include "minmax.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int   a=1,b=3;
    float c=3,d=5;
    //Input Data

    //Process Data
    
    //Output Data
    cout<<"int a="<<a<<" int b="<<b<<endl;
    cout<<"minimum = "<<minimum(a,b)<<endl;
    cout<<"maximum = "<<maximum(a,b)<<endl;
    
    cout<<"float c="<<c<<" float d="<<d<<endl;
    cout<<"minimum = "<<minimum(c,d)<<endl;
    cout<<"maximum = "<<maximum(c,d)<<endl;
    
    return 0;
}