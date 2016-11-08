/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 7, 2016, 4:00 PM
 * Purpose: Stores and displays a date.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "date.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    Date date;
    int year,day,month;
    
    //Input Data
    cout<<"Input the year: ";
    cin>>year;
    cout<<"Input the month: ";
    cin>>month;
    cout<<"Input the day: ";
    cin>>day;
    
    //Process Data
    date.setYear(year);
    date.setMnth(month);
    date.setDay(day,date.getMnth());
    
    //Output Data
    date.print();
    
    return 0;
}