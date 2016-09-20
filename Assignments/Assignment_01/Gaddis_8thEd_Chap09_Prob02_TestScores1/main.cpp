/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 19, 2016, 8:20 PM
 * Purpose: Dynamic array of test scores. Sorts and averages them.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void display(float*,int);
void getArry(float*,int);
void sort(float*,int);
float average(float*,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    float *array;
    int nTests;
    float ave;
    //Input Data & Allocate Memory
    cout<<"Input amount of tests: ";
    cin>>nTests;
    if(nTests<1){
        cout<<"Invalid amount."<<endl;
        return 0;
    }
    array=new float[nTests];
    getArry(array,nTests);
    
    //Process Data
    if(nTests<2){
        cout<<"Test #"<<nTests<<"'s score is ="<<array[0]<<endl;
        delete[] array;
        return 0;
    }
    cout<<"Test scores before sorting:"<<endl;
    display(array,nTests);
    sort(array,nTests);
    ave=average(array,nTests);
            
    //Output Data
    cout<<"Test scores after sorting:"<<endl;
    display(array,nTests);
    cout<<"The average test score is "<<ave<<endl;
    //Deallocate Memory
    delete[] array;
    
    return 0;
}

void display(float *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    cout<<endl;
}

void getArry(float *a,int n){
    //Input Data
    for(int i=0;i<n;i++){
        cout<<"Input Score of test #"<<i+1<<": ";
        cin>>a[i];
    }
}

void sort(float *a,int n){
    //Variables
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
                flag=true;
            }
        }
    }while(flag==true);
}

float average(float *a,int n){
    //Variables
    float ave=0;
    //Process Data
    for(int i=0;i<n;i++){
        ave+=a[i];
    }
    ave/=n;
    return(ave);
}