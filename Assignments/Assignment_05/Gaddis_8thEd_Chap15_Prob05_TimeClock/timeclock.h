/* File:   timeclock.h
 * Author: Javier B
 * Created on December 4, 2016, 10:20 PM
 * Purpose: Class Specification File for TimeClock
 */


#ifndef TIMECLOCK_H
#define TIMECLOCK_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "miltime.h"

class TimeClock: public MilTime{
    private:
        MilTime time1;
        MilTime time2;
    public:
        void setTime1(int);
        void setTime2(int);
        void getElpsTime();
};

#endif /* TIMECLOCK_H */