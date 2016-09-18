/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on August 29, 2016, 5:40 PM
 * Purpose: Converts dollars($) to yen(¥) and euros(€)
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <iomanip>    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
float yenConv(float); //Dollar to yen
float eurConv(float); //Dollar to euro

//Execution

int main(int argc, char** argv) {
    //Variables
    float dollars, yen, euros;
    
    //Input Data
    cout<<"Input amount of dollars to convert to yen and euros\n"
          "$";
    cin>>dollars;
    
    //Process Data
    yen=yenConv(dollars);
    euros=eurConv(dollars);
    
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"$"<<dollars<<" = ¥"<<yen<<" = €"<<euros<<endl;
    return 0;
}

float yenConv(float d){
    //Variables
    const float YCONV=101.99; //$1.00= ¥101.99
    float y;
    //Process Data
    y=d*YCONV;
    //Output Data
    return(y);
}

float eurConv(float d){
    //Variables
    const float ECONV=.89; //$1.00= €0.89
    float e;
    //Process Data
    e=d*ECONV;
    //Output Data
    return(e);
}