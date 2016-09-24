/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 23, 2016, 11:30 AM
 * Purpose: Return a pointer that points to an array in reverse order.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int *copy(int[],int);
//Execution

int main(int argc, char** argv) {
    //Variables
    int SIZE=10;
    int array[SIZE]={0,9,1,8,2,7,3,6,4,5};
    int *ptr;
    //Input Data
    ptr=copy(array,SIZE);
    //Output Data
    cout<<"Original Array:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<"New Array with Elements Reversed:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    //Deallocate Memory
    delete[] ptr;
    
    return 0;
}

int *copy(int a[],int n){
    //Variables and Allocate Memory
    int *pointer=new int[n];
    //Input Data
    for(int i=0;i<n;i++){
        pointer[i]=a[(n-1)-i];
    }
    return pointer;
}