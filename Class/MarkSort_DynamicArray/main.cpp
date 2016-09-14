/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 14, 2016, 2:00 PM
 * Purpose:Mark Sort a static array
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
int* fillAry(int);
void mrkSort(int [],int);
//Execution

int main(int argc, char** argv) {
    //Initialize Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Variables
    int perLine=10;
    const int SIZE=100;
    int *array;
    
    //Input Data
    array=fillAry(SIZE);
    
    //Process Data
    prntAry(array,SIZE,perLine);
    mrkSort(array,SIZE);
    
    //Output Data
    prntAry(array,SIZE,perLine);
    
    //Deallocate Memory
    delete []array;
    
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

int* fillAry(int n){
    //Allocate Memory
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;// Random 2 digit numbers
    }
    return a;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}