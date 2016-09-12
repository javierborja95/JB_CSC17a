/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 12, 2016, 1:25 PM
 * Purpose: Shortest Sort
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <cstdlib>    //Random Numbers
#include <ctime>      //Time
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void prntAry(int [],int,int);
void fillAry(int [],int);
void mrkSort(int [],int);
//Execution

int main(int argc, char** argv) {
    //Initialize Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Variables
    int perLine=10;
    const int SIZE=100;
    int utilize=SIZE*0.5;
    int array[SIZE];
    
    //Input Data
    fillAry(array,utilize);
    
    //Process Data
    prntAry(array,utilize,perLine);
    mrkSort(array,utilize);
    
    //Output Data
    prntAry(array,utilize,perLine);
    return 0;
}

void mrkSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;// Random 2 digit numbers
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}