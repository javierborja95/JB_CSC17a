/* 
 * File:   date.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 3:50 PM
 * Purpose: Date class implementation
 */

//Class location
#include "date.h"

void Date::setDay(int n,int m){
    //Make sure day is greater than 1 and less than month max
    if(n<1)exit(1);
    if(isLpYr()){             //If leap year
        if(m==2&&n>29)exit(1);//If feb and day is greater than 29, exit
    }else{
        if(m==2&&n>28)exit(1);//If feb and day is greater than 28, exit
    }
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        if(n>31)exit(1);      //If day is greater than 31 days
    }
    else{
        if(n>30)exit(1);      //If day is greater than 30 days
    }
    day=n;
}

bool Date::isLpYr(){
    if((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    return false;
}

void Date::print(){
    //Output Data
    cout<<month<<"/"<<day<<"/"<<year<<endl;
    printM();
        cout<<day<<","<<year<<endl;
    cout<<day<<" ";
        printM();
        cout<<year<<endl;
}

void Date::printM(){
    switch (month){
        case 1:
            cout<<"January ";break;
        case 2:
            cout<<"February ";break;
        case 3:
            cout<<"March ";break;
        case 4:
            cout<<"April ";break;
        case 5:
            cout<<"May ";break;
        case 6:
            cout<<"June ";break;
        case 7:
            cout<<"July ";break;
        case 8:
            cout<<"August ";break;
        case 9:
            cout<<"September ";break;
        case 10:
            cout<<"October ";break;
        case 11:
            cout<<"November ";break;
        default:
            cout<<"December ";
    }
}
