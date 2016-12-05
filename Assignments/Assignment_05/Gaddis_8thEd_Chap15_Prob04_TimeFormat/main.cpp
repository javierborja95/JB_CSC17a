/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November , 2016,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "miltime.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int hours,sec;
    MilTime time;
    //Input Data
    cout<<"Input military hours: ";
    cin>>hours;
    cout<<"Input seconds: ";
    cin>>sec;
    //Process Data
    time.setTime(hours,sec);
    //Output Data
    cout<<setw(4)<<setfill('0')<<time.getMilH()
            <<" mil. hours and "<<time.getMilS()<<" mil. seconds\n";
    cout<<"Standard time: "<<endl;
    cout<<"Hour: ";{
        if(time.getHour()==0){
            cout<<"12 am"<<endl;
        }else if(time.getHour()==12){
            cout<<"12 pm"<<endl;
        }else if(time.getHour()<12){
            cout<<time.getHour()<<" am"<<endl;
        }else{
            cout<<time.getHour()-12<<" pm"<<endl;
        }
    }
    cout<<"Min: "<<time.getMin()<<endl;
    cout<<"Sec: "<<time.getSec()<<endl;
    return 0;
}