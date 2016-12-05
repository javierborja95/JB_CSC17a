/* File:   miltime.h
 * Author: Javier B
 * Created on December 4, 2016, 9:33 PM
 * Purpose: Class Implementation File for military time class
 */

#include "miltime.h"


void MilTime::setTime(int h, int s=0){
    if(h<0||h>2359){
        cout<<"Error: hours must be greater than 0 and less than 2359"<<endl;
        exit(1);
    }
    if(s<0||s>59){
        cout<<"Error: seconds must be greater than 0 and less than 59"<<endl;
        exit(1);
    }
    milHours=h;
    milSec=s;
    hour=milHours/100;
    min=milHours-hour*100;
    if(min>59){
        cout<<"Military time must not have minutes greater than 59(XX59)";
        exit(1);
    }
    sec=s;
}