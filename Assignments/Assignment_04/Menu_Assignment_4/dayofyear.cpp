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

DayOfYear::DayOfYear(string a, int n){
    //Variables
    bool match=false;
    //Process Data
    if(n<1)exit(1);
    if(a=="jan"){
        match=true;
        if(n>31){
            cout<<"Jan can't have more than 31 days";
            exit(1);
        }
        day=n;
    }else if(a=="feb"){
        match=true;
        if(n>28){
            cout<<"Feb can't have more than 28 days";
            exit(1);
        }
        day=n+31;
    }else if(a=="mar"){
        match=true;
        if(n>31){
            cout<<"Mar can't have more than 31 days";
            exit(1);
        }
        day=n+59;
    }else if(a=="apr"){
        match=true;
        if(n>30){
            cout<<"Apr can't have more than 30 days";
            exit(1);
        }
        day=n+90;
    }else if(a=="may"){
        match=true;
        if(n>31){
            cout<<"May can't have more than 31 days";
            exit(1);
        }
        day=n+120;
    }else if(a=="jun"){
        match=true;
        if(n>30){
            cout<<"Jun can't have more than 30 days";
            exit(1);
        }
        day=n+151;
    }else if(a=="jul"){
        match=true;
        if(n>31){
            cout<<"Jul can't have more than 31 days";
            exit(1);
        }
        day=n+181;
    }else if(a=="aug"){
        match=true;
        if(n>31){
            cout<<"Aug can't have more than 31 days";
            exit(1);
        }
        day=n+212;
    }else if(a=="sep"){
        match=true;
        if(n>30){
            cout<<"Sep can't have more than 30 days";
            exit(1);
        }
        day=n+243;
    }else if(a=="oct"){
        match=true;
        if(n>31){
            cout<<"Oct can't have more than 31 days";
            exit(1);
        }
        day=n+273;
    }else if(a=="nov"){
        match=true;
        if(n>31){
            cout<<"Nov can't have more than 30 days";
            exit(1);
        }
        day=n+304;
    }else if(a=="dec"){
        match=true;
        if(n>31){
            cout<<"Dec can't have more than 31 days";
            exit(1);
        }
        day=n+334;
    }
    if(match==false){
        cout<<"Did not recognize the month"<<endl;
        exit(1);
    }
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

void DayOfYear::operator ++(int){
    day++;
    if(day==366)day=1;
}

void DayOfYear::operator --(int){
    day--;
    if(day==0)day=365;
}