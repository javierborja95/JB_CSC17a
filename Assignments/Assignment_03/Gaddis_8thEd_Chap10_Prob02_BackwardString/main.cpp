/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 17, 2016, 8:30 PM
 * Purpose: Displays a reversed string
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void reverse(string*);
//Execution

int main(int argc, char** argv) {
    //Variables
    string input;
    string *ptr;
    int nChar;
    //Input Data
    cout<<"This program reverses a string and outputs it.\n"
          "Input a string: ";
    getline(cin,input);
    //Process Data
    ptr=&input;
    //Output Data
    reverse(ptr);
    
    return 0;
}

void reverse(string *a){
    //Output Data
    for(int i=(*a).length();i>0;i--){
        cout<<(*a)[i-1];
    }
    cout<<endl;
}