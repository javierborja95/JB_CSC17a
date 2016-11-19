/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 2:10 PM
 * Purpose: Class DayOfYear implementation file
 */

#include "dayofyear.h"

string DayOfYear::months[MONTHS]={"Jan ","Feb ","Mar ","Apr ","May ","Jun ",
    "Jul ","Aug ","Sep ","Oct ","Nov ","Dec "
};

DayOfYear::DayOfYear(int n){
    day=n;
}

void DayOfYear::print() const{
    //Variables
    int month;
    int day=this->day;
    //Process data
    if(this->day<32){
        month=0;
    }else if(this->day<60){
        month=1;
        day-=31;
    }else if(this->day<91){
        month=2;
        day-=59;
    }else if(this->day<121){
        month=3;
        day-=90;
    }else if(this->day<152){
        month=4;
        day-=120;
    }else if(this->day<182){
        month=5;
        day-=151;
    }else if(this->day<213){
        month=6;
        day-=181;
    }else if(this->day<244){
        month=7;
        day-=212;
    }else if(this->day<274){
        month=8;
        day-=243;
    }else if(this->day<305){
        month=9;
        day-=273;
    }else if(this->day<335){
        month=10;
        day-=304;
    }else{
        month=11;
        day-=334;
    }
    //Output Data
    cout<<months[month]<<day;
}