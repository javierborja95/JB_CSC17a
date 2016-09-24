/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 23, 2016, 4:00 PM
 * Purpose: Create a new array 1 size larger than argument array. Set first
 * element of new array to 0 and copy the rest to each subsequent element.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int *shift(int[],int);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=10;
    int origArr[SIZE]={0,1,2,3,4,5,6,7,8,9};
    int *newArr;
    //Input Data
    newArr=shift(origArr,SIZE);
    //Process Data
    
    //Output Data
    cout<<"Original Array:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<origArr[i]<<" ";
    }
    cout<<endl<<"New Array:"<<endl;
    for(int i=0;i<(SIZE+1);i++){
        cout<<newArr[i]<<" ";
    }
    delete[] newArr;
    return 0;
}

int *shift(int a[],int n){
    //Variables
    int *array=new int[n+1]{}; //Initialize to 0
    //Input Data
    for(int i=0;i<n;i++){
        array[i+1]=a[i];
    }
    //Output Data
    return array;
}