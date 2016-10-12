/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 12, 2016, 9:25 AM
 * Purpose: Write array to binary, read binary file to array. Display contents.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <fstream>   //File I/O
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void arrToFile(fstream&,int*,int);
void fileToArr(fstream&,int*,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    fstream writeF;
    fstream readF;
    const int SIZE=10;
    int array[SIZE]={1,2,3,4,5,6,7,8,9,10}; //Int array
    int *ptr=array; //Pointer to int array
    int *newPtr= new int[SIZE]; //New array to read in binary content
    
    //Output Data to file
    arrToFile(writeF,ptr,SIZE);
    
    //Input Data from file
    fileToArr(readF,newPtr,SIZE);
    
    //Output Data
    cout<<"Old int array written to binary file:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<*(ptr+i)<<",";
    }
    cout<<endl<<"New int array read from binary file:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<newPtr[i]<<",";
    }
    
    delete[] newPtr;
    
    return 0;
}

void arrToFile(fstream &out,int *a,int n){
    //Open File
    out.open("binary.dat",ios::out|ios::binary);
    //Output Data
    for(int i=0;i<n;i++){
        out.write(reinterpret_cast<char *>(a+i),sizeof(*(a+i)));
    }
    //Close File
    out.close();
}

void fileToArr(fstream &in,int *a,int n){
    in.open("binary.dat",ios::in|ios::binary);
    if(in.fail()){
        cout<<"File opening failed"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        in.read(reinterpret_cast<char *>(a+i),sizeof(*(a+i)));
    }
    in.close();
}