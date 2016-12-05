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
#include "timeclock.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    TimeClock a;
    int n;
    //Input Data
    cout<<"This program shows the elapsed time between two times"<<endl;
    cout<<"Input the starting time in military time(ex.0700)"<<endl;
    cin>>n;
    a.setTime1(n);
    cout<<"Input the ending time in military time(ex.0700)"<<endl;
    cin>>n;
    a.setTime2(n);
    //Process Data
    
    //Output Data
    cout<<"Elapsed time: ";
    a.getElpsTime();
    
    return 0;
}