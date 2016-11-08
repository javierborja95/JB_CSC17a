/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 7, 2016, 7:50 PM
 * Purpose: Holds personal info of user and two others. Displays contents.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>  //Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "info.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=3; //Size of array
    Info *arr=new Info[SIZE];
    string name,address;
    int age;
    char phone[10];
    //Input Data
    for(int i=0;i<SIZE;i++){
        if(i==0)cout<<"Your information: "<<endl;
        else if(i==1)cout<<"Your friend's information: "<<endl;
        else cout<<"Your family member's information: "<<endl;
        cout<<"Input name: ";
        getline(cin,name);
        cout<<"Input address: ";
        getline(cin,address);
        cout<<"Input age: ";
        cin>>age;
        cout<<"Input phone number (XXX)XXX-XXXX\n(just the integers): ";
        cin>>phone;
        cin.ignore();
    //Process Data
        arr[i].setInfo(name,address,age,phone);
    }
    //Output Data
    cout<<"Name            Address             Age   Phone"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<setw(16)<<left<<arr[i].getName()<<setw(20)<<left<<arr[i].getAdd()
                <<setw(6)<<arr[i].getAge();
        arr[i].getPhone();
        cout<<endl;
    }
    //Deallocate Data
    delete[] arr;
    
    return 0;
}