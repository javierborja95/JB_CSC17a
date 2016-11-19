/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 5:20 PM
 * Purpose: Class NumDays implementation file.
 */

#include "numdays.h"

void NumDays::setHours(int n){
    if(n<0){
        cout<<"Error: Can not have negative value"<<endl;
        exit(1);
    }
    hours=n;
}

float NumDays::getDays(){
    //Variables
    float day;
    //Process Data
    day=hours/8.0f;
    //Output Data
    return day;
}

void NumDays::operator ++(int){
    hours++;
}

void NumDays::operator --(int){
    hours--;
    if(hours<0){
        hours=0;
        cout<<"Converted negative value to 0"<<endl;
    }
}

float NumDays::operator +(NumDays &right){
    return (getDays()+right.getDays());
}

float NumDays::operator -(NumDays &right){
    return (getDays()-right.getDays());
}