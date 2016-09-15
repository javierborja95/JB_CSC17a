/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 14, 2016, 11:00 AM
 * Purpose: Sorts and searches through names
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <string>     //String Library
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void sort(string[],int);
void display(string[],int);
int search(string[],int,string);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int NAMES = 40;
    string names[NAMES] = {"Collins","Bill","Smith","Bart","Allen","Jim",
                           "Griffin","Jim","Stamey","Marty","Rose","Geri",
                           "Taylor","Terri","Johnson","Jill",
                           "Allison","Jeff","Looney","Joe","Wolfe","Bill",
                           "James","Jean","Weaver","Jim","Pore","Bob",
                           "Rutherford","Greg","Javens","Renee",
                           "Harrison","Rose","Setzer","Cathy",
                           "Pike","Gordon","Holland","Beth"};
    string choice;
    int index;
    
    //Input Data
    cout<<"Old Array:\n";
    display(names,NAMES);
    sort(names,NAMES);
    cout<<"\n\nSorted Array:\n";
    display(names,NAMES);
    cout<<"\nInput Name to find in the array.(case sensitive)\n";
    cin>>choice;
    
    //Process Data
    index=search(names,NAMES,choice);
    
    //Output Data
    if(index!=-1)
        cout<<choice<<" was found at index #"<<index+1<<endl;
    else
        cout<<"Name not found"<<endl;
    return 0;
}

void sort(string a[],int n){
    //Variables
    string temp;
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i].compare(a[i+1])>0){
                flag=true;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }while(flag==true);
}

void display(string a[],int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if((i+1)%5==0)cout<<endl;
    }
}

int search(string a[],int n,string choice){
    //Variables
    int first=0,
        last=n-1,
        middle,
        position=-1;
    bool found=false;
    //Process Data
    while(first<=last){
        middle=(first+last)/2;
        if(a[middle].compare(choice)==0){
            position=middle;
            return position;
        }
        else if(a[middle].compare(choice)>0)
            last=middle-1;
        else
            first=middle+1;
    }
    return position;
}