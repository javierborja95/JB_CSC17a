/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 2:10 PM
 * Purpose: Translates an integer representing a day of the year and outputs 
 * the date
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "dayofyear.h"

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int x;
    //Input Data
    cout<<"This program translates an integer to the date it corresponds to.\n";
    do{
        cout<<"Input a number 1-365: ";
        cin>>x;
    }while(x<1&&x>365);
    //Process Data
    DayOfYear n(x);
    //Output Data
    n.print();
    
    return 0;
}