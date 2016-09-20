/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 20, 2016, 11:30 AM
 * Purpose: Dynamically allocates an array of user size choice.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <ctime>     //Time Library
#include <cstdlib>   //Random Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int *getArry(int);
//Execution

int main(int argc, char** argv) {
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    int size;
    int *array;
    //Input Data
    cout<<"Input a size of an array to dynamically allocate: ";
    cin>>size;
    //Process Data
    array=getArry(size);
    //Output Data and Deallocate Memory
    cout<<"The values in your pointer array of size "<<size<<":"<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    delete[] array;
    
    return 0;
}

int *getArry(int n){
    //Allocate Memory
    int *a= new int[n];
    //Input Data and Return pointer
    for(int i=0;i<n;i++){
        a[i]=rand()%9;
    }
    return a;
}