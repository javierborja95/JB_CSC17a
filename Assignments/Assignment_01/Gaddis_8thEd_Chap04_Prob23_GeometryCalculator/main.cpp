/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on August 30, 2016, 9:30 AM
 * Purpose: Menu to calculate areas of geometric shapes
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <cmath>      //Math Library
#include <iomanip>    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants
const float PI=4*atan(1);

//Function Prototypes
void menu();
float areaCir(); //Circle
float areaRec(); //Rectangle
float areaTri(); //Triangle

//Execution

int main(int argc, char** argv) {
    //Variables
    char choice;
    float area;
    //Input Data
    do{
        menu();
        cin>>choice;
        if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4')
            cout<<"Invalid input"<<endl<<endl;
    }while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
    //Process Data
    switch(choice){
        case '1':
            area=areaCir();
            break;
        case '2':
            area=areaRec();
            break;
        case '3':
            area=areaTri();
            break;
        default:
            return 0;
    }
    //Output Data
    cout<<"Area = "<<fixed<<showpoint<<setprecision(2)<<area<<"m^2"<<endl;
    return 0;
}

void menu(){
    //Output Data
    cout<<"Geometry Calculator\n\n"
          "\t1. Calculate the Area of a Circle\n"
          "\t2. Calculate the Area of a Rectangle\n"
          "\t3. Calculate the Area of a Triangle\n"
          "\t4. Quit\n\n"
          "\tEnter your choice (1-4): ";
}

float areaCir(){
    //Variables
    float area,radius;
    //Input Data
    cout<<"Input radius in meters: ";
    cin>>radius;
    //Process Data
    area=(PI*radius*radius);
    return(area);
}

float areaRec(){
    //Variables
    float area,length,width;
    //Input Data
    cout<<"Input length in meters: ";
    cin>>length;
    cout<<"Input  width in meters: ";
    cin>>width;
    //Process Data
    area=(length*width);
    return(area);
}

float areaTri(){
    //Variables
    float area,base,height;
    //Input Data
    cout<<"Input base in meters: ";
    cin>>base;
    cout<<"Input height in meters: ";
    cin>>height;
    //Process Data
    area=(base*height*.5);
    return(area);    
}