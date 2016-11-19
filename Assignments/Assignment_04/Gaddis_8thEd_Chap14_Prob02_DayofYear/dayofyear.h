/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 2:10 PM
 * Purpose: Class DayOfYear specification file
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std;

//Global Constants
const int MONTHS=12;

class DayOfYear{
    private:
        int day;
        static string months[MONTHS];
    public:
        DayOfYear(int);
        void print() const;
};

#endif /* DAYOFYEAR_H */

