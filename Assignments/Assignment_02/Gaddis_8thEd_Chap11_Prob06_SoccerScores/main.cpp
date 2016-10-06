/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 5, 2016, 7:00 PM
 * Purpose: Stores Soccer scores
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>
#include <iomanip>

using namespace std; //Namespace of the System Libraries

//User Libraries
#include "soccer.h"

//Global Constants

//Function Prototypes
void inPlayer(Soccer*,int);
void display(Soccer*,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    int size=2;
    Soccer *team=new Soccer[size];
    
    //Input Data
    cout<<"How many players on the team?"<<endl;
    cin>>size;
    inPlayer(team,size);
    //Process Data
    
    //Output Data
    display(team,size);
    
    delete[] team;
    return 0;
}

void inPlayer(Soccer *a,int n){
    //Input Data
    for(int i=0;i<n;i++){
        cin.ignore();
        cout<<"Input Player "<<i+1<<"'s name: ";
        getline(cin,a[i].name);
        cout<<"Input Player "<<i+1<<"'s number: ";
        cin>>a[i].num;
        cout<<"Input Points scored by "<<a[i].name<<": ";
        cin>>a[i].points;
    }
    cout<<endl;
}

void display(Soccer *a,int n){
    //Variables
    int *high=&(a[0].points);
    string *highN=&(a[0].name);
    int sum=0;
    //Output Data
    cout<<"Number      Name      Pts Scored"<<endl;
    for(int i=0;i<n;i++){
        cout<<right<<setw(4)<<a[i].num<<right<<setw(16)<<a[i].name
                <<"     "<<a[i].points<<endl;
        if(i!=0){
            if(*high<a[i].points){
                high=&(a[i].points);
                highN=&(a[i].name);
            }
        }
        sum+=a[i].points;
    }
    cout<<"The team scored "<<sum<<" points in total!"<<endl;
    cout<<*highN<<" scored the most points with "<<*high<<" points!"<<endl;
}