/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 20, 2016, 2:30 PM
 * Purpose: Dynamic array of test scores. Sorts and averages them after dropping
 * the lowest test score.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
#include <string>    //STring library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void display(float*,string*,int);
void getArry(float*,string*,int);
void sort(float*,string*,int);
float average(float*,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    float *array;
    string *names;
    int nTests;
    float ave; //Average score
    //Input Data & Allocate Memory
    cout<<"Input amount of tests: ";
    cin>>nTests;
    if(nTests<1){
        cout<<"Invalid amount."<<endl;
        return 0;
    }
    array=new float[nTests];
    names=new string[nTests];
    getArry(array,names,nTests);
    
    //Process Data
    cout<<"Test scores before sorting:"<<endl;
    display(array,names,nTests);
    sort(array,names,nTests);
    ave=average(array,nTests);
            
    //Output Data
    cout<<"Test scores after sorting:"<<endl;
    display(array,names,nTests);
    cout<<"Average test score: "<<showpoint<<setprecision(2)<<ave<<endl;
    //Deallocate Memory
    delete[] array;
    delete[] names;
    
    return 0;
}

void display(float *a,string *name,int n){
    //Output Data
    cout<<"Num Name    Score"<<endl;
    for(int i=0;i<n;i++){
        name[i]=name[i].substr(0,8);//Truncating name to 8 chars
        cout<<left;
        cout<<setw(4)<<i+1;
        cout<<setw(8)<<name[i]<<" ";
        cout<<setw(3)<<a[i]<<endl;
    }
    cout<<endl;
}

void getArry(float *a,string *name,int n){
    //Input Data
    for(int i=0;i<n;i++){
        cout<<"Input Score of test #"<<i+1<<": ";
        cin>>a[i];
        cin.ignore();
        cout<<"Input name of test #"<<i+1<<": ";
        getline(cin,name[i]);
    }
}

void sort(float *a,string *b,int n){
    //Variables
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
                swap(b[i],b[i+1]);
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