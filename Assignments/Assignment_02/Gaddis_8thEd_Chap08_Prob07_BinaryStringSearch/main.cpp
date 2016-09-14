/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 14, 2016, 11:00 AM
 * Purpose: Sorts and searches through names
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <string>
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void sort(string[],int);
//Execution

int main(int argc, char** argv) {
    //Variables
const int NAMES = 40;
string names[NAMES] = {"Collins","Bill","Smith","Bart","Allen","Jim",
                       "Griffin","Jim","Stamey","Marty","Rose","Geri",
                       "Taylor","Terri","Johnson","Jill",
                       "Allison","Jeff","Looney","Joe","Wolfe","Bill",
                       "James","Jean","Weaver","Jim","Pore","Bob",
                       "Rutherford","Greg","Javens","Renee",
                       "Harrison","Rose","Setzer","Cathy",
                       "Pike","Gordon","Holland","Beth"};
    //Input Data
    sort(names,NAMES);
    //Process Data
    
    //Output Data
    for(int i=0;i<NAMES;i++){
        cout<<names[i]<<" ";
        if((i+1)%5==0)cout<<endl;
    }
    return 0;
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