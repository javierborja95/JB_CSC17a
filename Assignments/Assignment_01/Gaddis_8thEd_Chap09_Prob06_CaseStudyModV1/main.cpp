/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 21, 2016, 8:50 PM
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
#include <cstdlib>   //Random
#include <ctime>     //Time
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void arrSort(int*,int); //Selection sort
void showArr(int*,int);
void getArr(int*,int*,int);
//Execution

int main(int argc, char** argv) {
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    int n;        //Number of donations
    int *origPtr; //Original array of donations
    int *newPtr;  //Sorted array of donations
    //Input Data
    cout<<"Input amount of donations: ";
    cin>>n;
    origPtr=new int[n];
    newPtr=new int[n];
    getArr(origPtr,newPtr,n);
    //Process Data
    arrSort(newPtr,n);
    //Output Data
    cout<<"The Donations, sorted in ascending order:"<<endl;
    showArr(newPtr,n);
    cout<<"The Donations in their original order:"<<endl;
    showArr(origPtr,n);
    
    delete []newPtr;
    delete []origPtr;
    return 0;
}

void getArr(int *a,int *b,int n){
    //Input Data
    for(int i=0;i<n;i++){
        a[i]=(rand()%10+1)*5;
        b[i]=a[i];
    }
}

void showArr(int *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<"$"<<setw(2)<<*(a+i)<<".00 ";
        if((i+1)%10==0)cout<<endl;
    }
    cout<<endl;
}

void arrSort(int *a,int n){
    //Variables
    int start, minIndx; //Start scan, Minimum index
    int minElem;       //Minimum Element
    //Process Data
    for(start=0;start<(n-1);start++){
        minIndx=start;
        minElem=a[start];
        for(int index=(start+1);index<n;index++){
            if(a[index]<minElem){
                minElem=a[index];
                minIndx=index;
            }
        }
        a[minIndx]=a[start];
        a[start]=minElem;
    }
}