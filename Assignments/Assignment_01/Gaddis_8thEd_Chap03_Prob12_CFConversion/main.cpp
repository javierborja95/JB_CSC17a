/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on August 29, 2016, 5:40 PM
 * Purpose: Converts Fahrenheit to Celsius or vice versa
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <iomanip>    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void ctof(); //Celsius to Fahrenheit
void ftoc(); //Fahrenheit to Celsius

//Execution

int main(int argc, char** argv) {
    //Variables
    char choice;
    
    //Input Data
    cout<<"Input 1 to convert Celsius temperature to Fahrenheit"<<endl;
    cout<<"Input 2 to convert Fahrenheit temperature to Celsius"<<endl;
    cin>>choice;
    
    //Process Data

    //Output Data
    switch(choice){
        case '1':{
            ctof();
            break;
        }
        case '2':{
            ftoc();
            break;
        }
        default: cout<<"Invalid input";
    }
    return 0;
}

void ctof(){ //Celsius to Fahrenheit
    //Variables
    float c, //Celsius
          f; //Fahrenheit
    //Input Data
    cout<<"Input Celsius to convert: "<<endl;
    cin>>c;
    //Process Data
    f=(1.8*c)+32.0f; //F=(9/5)*C+32
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<c<<" C°= "<<f<<" F°"<<endl;
}

void ftoc(){ //Fahrenheit to Celsius
    //Variables
    float c, //Celsius
          f; //Fahrenheit
    //Input Data
    cout<<"Input Fahrenheit to convert: "<<endl;
    cin>>f;
    //Process Data
    c=(f-32.0f)/1.8f;
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<f<<" F°= "<<c<<" C°"<<endl;
}