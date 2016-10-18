/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 17, 2016, 8:00 PM
 * Purpose: Pointer to String and displays number of words
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>    //Strings
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int count(string*);
//Execution

int main(int argc, char** argv) {
    //Variables
    string   input; //String input
    string    *ptr; //Pointer to string
    int   nWords=0; //Number of words
    
    //Input Data
    cout<<"This program counts the number of words in a string\nInput a string: ";
    getline(cin,input);
    
    //Process Data
    ptr=&input;
    nWords=count(ptr);
    
    //Output Data
    cout<<"Number of words: "<<nWords<<endl;
    
    return 0;
}

int count(string *ptr){
    //Variables
    string word;
    int counter=1;
    //Process Data
    
    for(int i=0,j=1;i<(*ptr).length();i++,j++){ //Go through each character
        if((*ptr)[i]==' '){       //If there is a space then new word
            counter++;
        }
    }
    return counter;
}