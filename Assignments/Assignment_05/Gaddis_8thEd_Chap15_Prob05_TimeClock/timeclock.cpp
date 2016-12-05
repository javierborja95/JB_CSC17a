/* File:   timeclock.h
 * Author: Javier B
 * Created on December 4, 2016, 10:20 PM
 * Purpose: Class Implementation File for TimeClock
 */

#include "timeclock.h"


void TimeClock::setTime1(int n){
    if(n<0||n>2359){
        cout<<"Time must be greater than 0000 hours and less than 2359 hours"<<endl;
        exit(1);
    }
    time1.setTime(n,0);
}
void TimeClock::setTime2(int n){
    if(n<0||n>2359){
        cout<<"Time must be greater than 0000 hours and less than 2359 hours"<<endl;
        exit(1);
    }
    time2.setTime(n,0);
}

void TimeClock::getElpsTime(){
    int h,m;
    h=time2.getHour()-time1.getHour();
    m=time2.getMin()-time1.getMin();
    if(m<0){
        m+=60;
        h--;
    }
    cout<<h<<" hours"<<endl;
    cout<<m<<" minutes"<<endl;
}