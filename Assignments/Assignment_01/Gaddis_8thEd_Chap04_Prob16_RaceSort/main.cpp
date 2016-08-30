/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on August 29, 2016, 9:45 PM
 * Purpose: Input names and times of runners and sorts by who finished first.
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <string>     //STring Library
using namespace std;  //Namespace of the System Libraries

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
void sort(Pair[],int);
void swap(Pair[],int,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=3;
    Pair racer[SIZE]={}; //A racer has a name and time
    
    //Input Data
    cout<<"Input three racers' names and times"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"Racer "<<i+1<<" name: ";
        getline(cin, racer[i].name);
        cout<<racer[i].name<<"'s time in seconds: ";
        cin>>racer[i].time;
        cin.ignore();
    }
    //Process Data
    sort(racer,SIZE);
    //Output Data
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<i+1<<". "<<racer[i].name<<" with a time of "<<racer[i].time<<"s\n";
    }
    return 0;
}

void sort(Pair a[],int n){
    for(int i=0;i<n-1;i++){
        for(int x=i+1;x<n;x++){
            if(a[i].time>a[x].time){
                swap(a,i,x);
            }
        }
    }
}

void swap(Pair a[],int x,int y){
    //Variables
    Pair temp;
    //Process Data
    temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}