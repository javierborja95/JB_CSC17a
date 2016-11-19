/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 5:20 PM
 * Purpose: Converts work hours to days.
 */

//System Libraries
#include <iostream>

#include "numdays.h"  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    NumDays obj1,obj2;
    int n;
    //Input Data
    cout<<"This program converts work hours to days. For example, 8 hours equals"
            "1 day."<<endl<<"Input amount of whole hours for object 1: ";
    cin>>n;
    obj1.setHours(n);
    cout<<"Input amount of whole hours for object 2: ";
    cin>>n;
    obj2.setHours(n);
    //Process Data
    
    //Output Data
    cout<<obj1.getHours()<<" hours = "<<obj1.getDays()<<" days"<<endl;
    cout<<obj2.getHours()<<" hours = "<<obj2.getDays()<<" days"<<endl;
    obj1++;
    cout<<"Object 1++ = "<<obj1.getDays()<<" days"<<endl;
    obj2--;
    cout<<"Object 2-- = "<<obj2.getDays()<<" days"<<endl;
    cout<<"Object 1+2 = "<<obj1+obj2<<" days"<<endl;
    cout<<"Object 1-2 = "<<obj1-obj2<<" days"<<endl;
    
    return 0;
}