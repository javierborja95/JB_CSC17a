/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 2:10 PM
 * Purpose: Translates an integer representing a day of the year and outputs 
 * the date
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>    //String Library

using namespace std; //Namespace of the System Libraries

//User Libraries
#include "dayofyear.h"

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    string month;
    int day;
    //Input Data
    cout<<"This program takes a month and day"<<endl;
    cout<<"Input the first three lowercase letters of the month(jan,feb..): ";
    getline(cin,month);
    cout<<"Input the day of the month: ";
    cin>>day;
    //Process Data
    DayOfYear n(month,day);
    //Output Data
    n.print();
    cout<<" using the -- operator: ";
    n--;
    n.print();
    cout<<endl<<"And now after using the ++ operator twice: ";
    n++;
    n++;
    n.print();
    cout<<endl;
    
    return 0;
}