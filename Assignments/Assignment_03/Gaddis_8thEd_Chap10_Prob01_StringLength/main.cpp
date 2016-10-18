/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 17, 2016, 8:10 PM
 * Purpose: Counts the characters of a string
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int length(string*);
//Execution

int main(int argc, char** argv) {
    //Variables
    string input;
    string *ptr;
    int nChar;
    //Input Data
    cout<<"This program counts the number of characters in a string excluding "
          "whitespace.\n"
          "Input a string: ";
    getline(cin,input);
    //Process Data
    ptr=&input;
    nChar=length(ptr);
    //Output Data
    cout<<"The length of the string is "<<input.length()<<endl;
    cout<<"There are "<<nChar<<" characters in this string"<<endl;

    return 0;
}

int length(string *a){
    //Variables
    int count=0;
    //Process Data
    for(int i=0;i<(*a).length();i++){
        if(isalnum((*a)[i])){
            count++;
        }
    }
    //Output Data
    return count;
}