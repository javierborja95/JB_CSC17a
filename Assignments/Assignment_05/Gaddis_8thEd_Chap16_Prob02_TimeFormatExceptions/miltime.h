/* File:   miltime.h
 * Author: Javier B
 * Created on December 4, 2016, 9:33 PM
 * Purpose: Class Specification File for military time class
 */

#ifndef MILTIME_H
#define MILTIME_H

//System Libraries
#include <cstdlib>   //Exit function
#include <iostream>  //Input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "time.h"

class MilTime:public Time{
    private:
        int milHours;
        int milSec;
    public:
        class BadHour{
        public:
            BadHour()
            {cout<<"Error: hours must be less than 23(23XX)"<<endl;}
        };
        class BadMinute{
        public:
            BadMinute()
            {cout<<"Error: time must not have minutes greater than 59(XX59)\n";}
        };
        class BadSec{
        public:
            BadSec()
            {cout<<"Error: Seconds must be less than 59"<<endl;}
        };
        MilTime(){milHours=0;milSec=0;}
        void setTime(int,int);
        int getMilH(){return milHours;}
        int getMilS(){return milSec;}
};

#endif /* MILTIME_H */

