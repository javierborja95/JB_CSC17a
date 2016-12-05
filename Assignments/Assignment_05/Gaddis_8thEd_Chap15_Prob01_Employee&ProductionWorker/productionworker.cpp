/* File:   productionworker.h
 * Author: Javier B
 * Created on December 4, 2016, 2:32 PM
 * Purpose: Class Implementation File for ProductionWorker class
 */

//User Libraries
#include "productionworker.h"

ProductionWorker::ProductionWorker(int shift, float rate){
    if(shift!=1&&shift!=2){
        cout<<"Bad input for shift"<<endl;
        exit(1);
    }
    if(rate<0){
        cout<<"Pay rate must be positive"<<endl;
        exit(1);
    }
    this->shift=shift;
    payRate=rate;
}

void ProductionWorker::setShift(int shift){
    if(shift!=1&&shift!=2){
        cout<<"Bad input for shift"<<endl;
        exit(1);
    }
    this->shift=shift;
}

void ProductionWorker::setPayRate(float rate){
    if(rate<0){
        cout<<"Pay rate must be positive"<<endl;
        exit(1);
    }
    payRate=rate;
}

string ProductionWorker::getShift(){
    if(shift==1)return "Day Shift";
    else return "Night Shift";
}

float ProductionWorker::getPay(int n){
    if(n<0){
        cout<<"Hours worked must be positive"<<endl;
        exit(1);
    }
    return payRate*n;
}