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
#include "shiftsupervisor.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    ShiftSupervisor worker;
    string s;
    int n;
    float salary,rate;
    //Input Data
    cout<<"Input shift supervisor's name: ";
    getline(cin,s);
    worker.setName(s);
    cout<<"Input "<<worker.getName()<<"'s employee number: ";
    getline(cin,s);
    worker.setNum(s);
    cout<<"What is "<<worker.getName()<<"'s yearly salary?\n$";
    cin>>salary;
    cout<<"What is "<<worker.getName()<<"'s bonus rate?\n$";
    cin>>rate;
    cout<<"How many bonuses did "<<worker.getName()<<" earn this year? ";
    cin>>n;
    //Process Data
    worker.setBRate(rate);
    worker.setSalary(salary);
    worker.setNBonus(n);
    //Output Data
    cout<<worker.getName()<<endl<<"Employee number: "<<worker.getNum()<<endl;
    cout<<"Salary for the year(bonuses included): $"<<showpoint<<fixed
            <<setprecision(2)<<worker.getSalary()<<endl;
    
    return 0;
}