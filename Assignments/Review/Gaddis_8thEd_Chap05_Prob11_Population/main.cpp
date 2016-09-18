/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 9, 2016, 11:00 AM
 * Purpose: Predicts size of a population of organisms.
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <iomanip>    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void increas(unsigned int,unsigned int,float);
//Execution

int main(int argc, char** argv) {
    //Variables
    unsigned int initPop; //Initial population
    float        percent; //Increase percent
    unsigned int    days; //Number of days population increases
    //Input Data
    cout<<"What is the initial population of the organisms? (must be greater "
          "than 1)\n"
          "Initial population: ";
    cin>>initPop;
    cout<<"What is the average daily population increase percentage? (can't be "
          "negative)\n"
          "Percentage: %";
    cin>>percent;
    cout<<"Number of days they will multiply?\n"
          "Days: ";
    cin>>days;
    //Process Data
    
    //Output Data
    cout<<"Day Population"<<endl;
    increas(initPop,days,percent);
    
    return 0;
}

void increas(unsigned int pop,unsigned int days,float per){
    //Variables
    
    //Process Data
    for(int i=1;i<=days+1;i++){
        cout<<setw(3)<<i<<setw(8)<<pop<<endl;
        pop+=(pop*per)/100+.5f;
    }
}