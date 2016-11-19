/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 5:20 PM
 * Purpose: TimeOff Specification File
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

//User Libraries
#include "numdays.h"
//System Libraries
#include <string>  //String Library
#include <cstdlib> //Exit Function

class TimeOff{
    private:
        string name;
        string id;
        NumDays maxSickDays; //Max days of sick leave
        NumDays sickTaken;   //Days of sick leave taken
        NumDays maxVacation; //Max days of vacation
        NumDays vacTaken;    //Days of vacation taken
        NumDays maxUnpaid;   //Max days of unpaid vacation
        NumDays unpaidTaken; //Days of unpaid vacation taken
    public:
        TimeOff(string,string);
        void setMaxSick(int);
        void setSick(int);
        void setVacTaken(int);
        void setMaxUnpaid(int);
        void setUnpaid(int);
        void getEmployee(){cout<<"Name: "<<name<<endl<<"Id: "<<id<<endl;}
        float getMaxSick(){return maxSickDays.getDays();}
        float getSickTaken(){return sickTaken.getDays();}
        float getMaxVac(){return maxVacation.getDays();}
        float getVacTaken(){return vacTaken.getDays();}
        float getMaxUnpaid(){return maxUnpaid.getDays();}
        float getUnpaidTaken(){return unpaidTaken.getDays();}
        int sickR(){return(maxSickDays-sickTaken);}
        int vacR(){return(maxVacation-vacTaken);}
        int unpR(){return(maxUnpaid-unpaidTaken);}
};


#endif /* TIMEOFF_H */

