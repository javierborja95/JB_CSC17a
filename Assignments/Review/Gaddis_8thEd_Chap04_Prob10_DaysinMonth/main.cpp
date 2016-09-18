/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on August 29, 2016, 6:50 PM
 * Purpose: Displays number of days in month in a given year.
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=12;
    int months[SIZE]={31,28,31,30,31,30,31,31,30,31,30,31};
    int m, y; //Month, Year
    
    //Input Data
    cout<<"Input a month [1,12]: ";
    cin>>m;
    if(m<1||m>12){
        cout<<"You didn't choose a month between 1 and 12"<<endl;
        return 0;
    }
    cout<<"Input a year (>0): ";
    cin>>y;
    if(y<1){
        cout<<"You didn't input a year greater than 0"<<endl;
        return 0;
    }
    //Process Data
    if(m==2&&(y%100==0)){
        if(y%400==0)
            months[1]=29;
    }else if(m==2&&(y%100!=0)){
        if(y%4==0)
            months[1]=29;
    }
    
    //Output Data
    cout<<months[m-1]<<" days"<<endl;
    
    return 0;
}