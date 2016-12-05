/* 
 * File:   date.h
 * Author: Javier B
 *
 * Created on December 5, 2016, 3:50 PM
 * Purpose: Date class specification
 */

#ifndef DATE_H
#define DATE_H

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std;

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        class InvalidDay{
            public:
                InvalidDay(){cout<<"Bad Day input"<<endl;}
        };
        class InvalidMonth{
            public:
                InvalidMonth(){cout<<"Bad Month Input"<<endl;}
        };
        void setMnth(int n){
            if(n<1||n>12)throw InvalidMonth(); //Make sure month is 1-12
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

