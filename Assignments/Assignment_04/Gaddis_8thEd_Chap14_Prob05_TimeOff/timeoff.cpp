/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 5:20 PM
 * Purpose: TimeOff Implementation File
 */

#include "TimeOff.h"

TimeOff::TimeOff(string name,string id){
    this->name=name;
    this->id=id;
    maxVacation.setHours(240);
    cout<<"Max Vacation days allowed for "<<name<<": "<<maxVacation.getDays()
            <<" days"<<endl;
}

void TimeOff::setMaxSick(int n){
    if(n<0){
        cout<<"Error: Can not have negative value"<<endl;
        exit(1);
    }
    maxSickDays.setHours(n*8);
}

void TimeOff::setSick(int n){
    if(n<0){
        cout<<"Error: Can not have negative value"<<endl;
        exit(1);
    }
    sickTaken.setHours(n*8);
    if((maxSickDays-sickTaken)<0){
        cout<<"Error: Can't take more than the max alloted days"<<endl;
        exit(1);
    }
}

void TimeOff::setVacTaken(int n){
    if(n<0){
        cout<<"Error: Can not have negative value"<<endl;
        exit(1);
    }
    vacTaken.setHours(n*8);
    if((maxVacation-vacTaken)<0){
        cout<<"Error: Can't take more than the max alloted days"<<endl;
        exit(1);
    }
}

void TimeOff::setMaxUnpaid(int n){
    if(n<0){
        cout<<"Error: Can not have negative value"<<endl;
        exit(1);
    }
    maxUnpaid.setHours(n*8);
}

void TimeOff::setUnpaid(int n){
    if(n<0){
        cout<<"Error: Can not have negative value"<<endl;
        exit(1);
    }
    unpaidTaken.setHours(n*8);
    if((maxUnpaid-unpaidTaken)<0){
        cout<<"Error: Can't take more than the max alloted days"<<endl;
        exit(1);
    }
}