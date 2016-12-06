/* File:   shiftsupervisor.h
 * Author: Javier B
 * Created on December 4, 2016, 4:23 PM
 * Purpose: Class Implementation File for
 */

#include "shiftsupervisor.h"

void ShiftSupervisor::setSalary(float s){
    if(s<0){
        cout<<"Salary must be positive"<<endl;
        exit(1);
    }
    salary=s;
}

void ShiftSupervisor::setBRate(float s){
    if(s<0){
        cout<<"Bonus must be positive"<<endl;
        exit(1);
    }
    bonusRate=s;
}

void ShiftSupervisor::setNBonus(int n){
    if(n<0){
        cout<<"Can't have negative value"<<endl;
        exit(1);
    }
    nBonus=n;
}