/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 5:20 PM
 * Purpose: Class NumDays specification file.
 */


#ifndef NUMDAYS_H
#define NUMDAYS_H

//System Libraries
#include <iostream> //Input/Output Stream
#include <cstdlib>  //Exit Function
using namespace std;

class NumDays{
    private:
        int hours;
    public:
        void setHours(int);
        int getHours(){return hours;}
        float getDays();
        void operator ++ (int);
        void operator -- (int);
        float operator + (NumDays &);
        float operator - (NumDays &);
};

#endif /* NUMDAYS_H */

