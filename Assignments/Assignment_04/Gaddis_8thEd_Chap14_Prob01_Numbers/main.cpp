/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 12:30 PM
 * Purpose: Translates decimal numbers to english
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "number.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int x;
    //Input Data
    cout<<"This programs translates a decimal number into english."<<endl;
    do{
        cout<<"Input a number between 0-9999: ";
        cin>>x;
    }while(x<0||x>9999);
    //Create a Number object
    Number n(x);
    //Output Data
    n.print();

    return 0;
}