/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 7, 2016, 6:00 PM
 * Purpose: Holds data for employees and displays the data
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "employee.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=3; //Number of employees
    Employee *arr=new Employee[SIZE];
    //Input Data
    arr[0].setEmp("Susan Meyers",47899);
    arr[0].setJob("Accounting","Vice President");
    arr[1].setEmp("Mark Jones",39119);
    arr[1].setJob("IT","Programmer");
    arr[2].setEmp("Joy Rogers",81774);
    arr[2].setJob("Manufacturing","Engineer");
    //Process Data
    
    //Output Data
    cout<<"Name            ID Num     Department     Position"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<setw(16)<<left<<arr[i].getName()<<setw(11)<<arr[i].getId()
                <<setw(15)<<arr[i].getDep()<<arr[i].getPos()<<endl;
    }
    
    return 0;
}