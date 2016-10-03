/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 2, 2016, 8:00 PM
 * Purpose: Database Sort using structures.
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <cstdlib>    //Random Numbers
#include <ctime>      //Time
#include <iomanip>    //Output Manipulation

#include "Array.h"    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void prntAry(Array);
Array fillAry(int);
Array fillIndx(int);
void mrkSort(Array,Array);
void swap(Array&,int,int);
//Execution

int main(int argc, char** argv) {
    //Initialize Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Variables
    const int SIZE=100;
    Array array, index;
    //Input Data
    array=fillAry(SIZE);
    index=fillIndx(SIZE);
    
    //Output Original Data
    cout<<"Original Array:"<<endl;
    prntAry(array);
    cout<<"Original Indexed Array:"<<endl;
    prntAry(index);
    
    //Process Data
    mrkSort(array,index);
    
    //Output New Data
    cout<<"Original Array sorted:"<<endl;
    prntAry(array);
    cout<<"Original Indexed Array:"<<endl;
    prntAry(index);
    
    //Deallocate Memory
    delete[] array.data;
    delete[] index.data;
    
    return 0;
}

void mrkSort(Array a,Array indx){
    for(int i=0;i<a.size-1;i++){
        for(int j=i+1;j<a.size;j++){
            if(a.data[i]>a.data[j]){
                swap(a,i,j);
                swap(indx,i,j);
            }
        }
    }
}

Array fillAry(int n){
    //Variables
    Array a;
    a.size=n;
    //Allocate Memory
    a.data=new int[a.size];
    //Input Data
    for(int i=0;i<a.size;i++){
        a.data[i]=rand()%90+10;// Random 2 digit numbers
    }
    return a;
}

Array fillIndx(int n){
    //Variables
    Array a;
    a.size=n;
    //Allocate Memory
    a.data=new int[a.size];
    //Input Data
    for(int i=0;i<a.size;i++){
        a.data[i]=i;
    }
    return a;
}

void prntAry(Array a){
    cout<<endl;
    for(int i=0;i<a.size;i++){
        cout<<setw(2)<<a.data[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    cout<<endl;
}

void swap(Array &a,int i,int j){
    a.data[i]=a.data[i]^a.data[j];
    a.data[j]=a.data[i]^a.data[j];
    a.data[i]=a.data[i]^a.data[j];
}