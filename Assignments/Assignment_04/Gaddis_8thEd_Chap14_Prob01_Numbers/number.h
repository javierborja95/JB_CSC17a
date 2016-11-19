/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 12:30 PM
 * Purpose: Number class specification file
 */

#ifndef NUMBER_H
#define NUMBER_H

//System Libraries
#include <string>   //String Library
#include <iostream> //Input/ Output Stream Library
using namespace std;

class Number{
    private:
        int number;
        static string lessThan20[20];
        static string ten[10];
        static string hundred;
        static string thousand;
    public:
        Number(int n){
            number=n;
        }
        void print();
};


#endif /* NUMBER_H */

