/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 15, 2016, 1:00 PM
 * Purpose: Inputs names from file and sorts
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <string>
#include <iostream>
#include <fstream>
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void read(string[],int);
void sort(string[],int);
void display(string[],int);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int NAMES = 40;
    string names[NAMES];
    
    //Input Data
    read(names,NAMES);
    cout<<"Before sorting:"<<endl;
    display(names,NAMES);
    
    //Process Data
    sort(names,NAMES);
    
    //Output Data
    cout<<"\n\nAfter Sorting:"<<endl;
    display(names,NAMES);
    
    return 0;
}
void read(string a[],int n){
    //Variables
    ifstream read;
    //Open File
    read.open("names.txt");
    if(read.is_open()){
        cout<<"File opening success."<<endl<<endl;
    }
    else cout<<"File opening failure."<<endl<<endl;
    //Input Data
    for(int i=0;i<n;i++){
        read>>a[i];
    }
    read.close();
}

void sort(string a[],int n){
    //Variables
    string temp;
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i].compare(a[i+1])>0){
                flag=true;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }while(flag==true);
}

void display(string a[],int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if((i+1)%5==0)cout<<endl;
    }
}