/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 19, 2016, 9:30 AM
 * Purpose: Database Sort using pointers
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <cstdlib>    //Random Numbers
#include <ctime>      //Time
#include <iomanip>    //Output Manipulation
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void fillAry(int *,int *,int);
void mrkSort(int *,int *,int);
//Execution

int main(int argc, char** argv) {
    //Initialize Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Variables
    int perLine=10;
    const int SIZE=100;
    int utilize=SIZE*0.5;
    int *array, *index;
    //Allocate Memory
    array=new int[SIZE];
    index=new int[SIZE];
    //Input Data
    fillAry(array,index,utilize);
    
    //Process Data
    cout<<"Original Array:"<<endl;
    prntAry(array,utilize,perLine);
    cout<<"Original Indexed Array:"<<endl;
    prntAry(index,utilize,perLine);
    cout<<"Array output utilizing the Index"<<endl;
    prntAry(array,index,utilize,perLine);
    
    mrkSort(array,index,utilize);
    
    //Output Data
    cout<<"Original Array sorted:"<<endl;
    prntAry(array,utilize,perLine);
    cout<<"Original Indexed Array:"<<endl;
    prntAry(index,utilize,perLine);
    cout<<"Array output utilizing the Index"<<endl;
    prntAry(array,index,utilize,perLine);
    //Deallocate Memory
    delete[] array;
    delete[] index;
    return 0;
}

void mrkSort(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[indx[i]]>a[indx[j]]){
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
    }
}

void fillAry(int *a,int *indx,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;// Random 2 digit numbers
        indx[i]=i;
    }
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(2)<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}