/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October , 2016,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "car.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    Car car;
    int model;
    string make;
    //Input Data
    cout<<"Input the car's model year: ";
    cin>>model;
    cin.ignore();
    cout<<"Input the car's make: ";
    getline(cin,make);
    
    //Process Data
    car.setCar(model,make);
    
    //Output Data
    for(int i=0;i<5;i++){
        cout<<endl<<car.getModel()<<" "<<car.getMake()<<" is going ";
        car.showSpeed();
        car.accel();
    }
    for(int i=0;i<5;i++){
        cout<<endl<<car.getModel()<<" "<<car.getMake()<<" is going ";
        car.showSpeed();
        car.brake();
    }
    cout<<endl<<car.getModel()<<" "<<car.getMake()<<" is going ";
    car.showSpeed();
    
    return 0;
}