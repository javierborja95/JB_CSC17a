/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 5:20 PM
 * Purpose: Converts work hours to days.
 */

//System Libraries
#include <iostream>

#include "numdays.h"  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "TimeOff.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    string name,id;
    int day;
    //Input Data
    cout<<"This program tracks an employee's sick leave, vacation, and unpaid"
            " time off."<<endl;
    cout<<"Input employee's name: ";
    getline(cin,name);
    cout<<"Input "<<name<<"'s id number: ";
    getline(cin,id);
    //Create TimeOff Object
    TimeOff a(name,id);
    //Input More Data
    cout<<"Input max amount of sick days employee can take: ";
    cin>>day;
    a.setMaxSick(day);
    cout<<"Input amount of sick days taken: ";
    cin>>day;
    a.setSick(day);
    cout<<"Input amount of vacation days taken: ";
    cin>>day;
    a.setVacTaken(day);
    cout<<"Input max amount of days of unpaid leave an employee can take: ";
    cin>>day;
    a.setMaxUnpaid(day);
    cout<<"Input amount of days of unpaid leave taken: ";
    cin>>day;
    a.setUnpaid(day);
    //Output Data
    a.getEmployee();
    cout<<"Sick days remaining: "<<a.sickR()<<endl;
    cout<<"Vacation days remaining: "<<a.vacR()<<endl;
    cout<<"Unpaid leave days remaining: "<<a.unpR()<<endl;
    
    return 0;
}