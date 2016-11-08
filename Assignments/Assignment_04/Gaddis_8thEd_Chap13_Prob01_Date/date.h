/* 
 * File:   date.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 3:50 PM
 * Purpose: Date class specification
 */

#ifndef DATE_H
#define DATE_H

//System Libraries
#include <cstdlib>   //Exit
#include <iostream>  //Input/ Output Stream Library
using namespace std;

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        void setMnth(int n){
            if(n<1||n>12)exit(1); //Make sure month is 1-12
            month=n;
        }
        void setYear(int n){year=n;}
        void setDay(int,int);
        int getMnth(){return month;}
        int getDay(){return day;}
        int getYear(){return year;}
        bool isLpYr();
        void print();
        void printM();
};

#endif /* DATE_H */

