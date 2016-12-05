/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 4, 2016, 2:00 PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "productionworker.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    ProductionWorker worker;
    string s;
    int shift,hours;
    float rate;
    //Input Data
    cout<<"Input workers name: ";
    getline(cin,s);
    worker.setName(s);
    cout<<"Input "<<worker.getName()<<"'s employee number: ";
    getline(cin,s);
    worker.setNum(s);
    cout<<"Input date "<<worker.getName()<<" was hired: ";
    getline(cin,s);
    worker.setHDat(s);
    cout<<"What shift does "<<worker.getName()<<" work?\n"
          "Input 1 for day shift\n"
          "Input 2 for night shift"<<endl;
    cin>>shift;
    cout<<"What is "<<worker.getName()<<"'s hourly rate in $?\n$";
    cin>>rate;
    cout<<"Input amount of whole hours "<<worker.getName()<<" worked: ";
    cin>>hours;
    //Process Data
    worker.setShift(shift);
    worker.setPayRate(rate);
    //Output Data
    cout<<worker.getName()<<endl<<"Employee number: "<<worker.getNum()<<endl;
    cout<<"Hired: "<<worker.getHDat()<<endl;
    cout<<worker.getShift()<<endl;
    cout<<"Salary for the week: $"<<showpoint<<fixed<<setprecision(2)
            <<worker.getPay(hours)<<endl;
    return 0;
}