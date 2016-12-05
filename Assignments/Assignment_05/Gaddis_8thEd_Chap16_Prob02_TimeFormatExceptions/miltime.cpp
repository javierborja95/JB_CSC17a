/* File:   miltime.h
 * Author: Javier B
 * Created on December 4, 2016, 9:33 PM
 * Purpose: Class Implementation File for military time class
 */

#include "miltime.h"


void MilTime::setTime(int h, int s=0){
    if(h<0||h>2359){
        throw MilTime::BadHour();
    }
    if(s<0||s>59){
        throw MilTime::BadSec();
    }
    milHours=h;
    milSec=s;
    hour=milHours/100;
    min=milHours-hour*100;
    if(min>59){
        throw MilTime::BadSec();
    }
    sec=s;
}