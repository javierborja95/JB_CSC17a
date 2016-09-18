/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 9, 2016, 11:30 AM
 * Purpose: Converts Fahrenheit to Celsius in a table
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <iomanip>    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void celsius(); //Fahrenheit to Celsius table

//Execution

int main(int argc, char** argv) {
    //Variables
    
    //Input Data
    
    //Process Data

    //Output Data
    cout<<"Fahrenheit Celsius"<<endl;
    celsius();
    
    return 0;
}

void celsius(){ //Fahrenheit to Celsius
    //Variables
    unsigned int f=0; //Fahrenheit
    float c;          //Celsius
    //Input Data
    //Process Data
    do{
        c=(f-32.0f)/1.8f;
    //Output Data
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<setw(4)<<f<<" F°= "<<setw(7)<<c<<" C°"<<endl;
        f++;
    }while(f<=20);
    cout<<endl;
}