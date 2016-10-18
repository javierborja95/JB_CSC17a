/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October , 2016,  PM
 * Purpose: Pointer to String and displays number of words and average number of
 * letters in each word.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>    //Strings
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void count(string*,int&,float&);
//Execution

int main(int argc, char** argv) {
    //Variables
    string   input; //String input
    string    *ptr; //Pointer to string
    int   nWords=0; //Number of words
    float aveLtr=0; //Ave number of letters in each word
    
    //Input Data
    cout<<"This program counts the number of words in a string and displays the "
          "average number of letters in each word.\nInput a string: ";
    getline(cin,input);
    
    //Process Data
    ptr=&input;
    count(ptr,nWords,aveLtr);
    
    //Output Data
    cout<<"Number of words: "<<nWords<<endl;
    cout<<"Average number of letters in each word: "<<aveLtr<<endl;
    
    return 0;
}

void count(string *ptr,int &nW,float &aL){
    //Variables
    string word;
    int counter=1;
    //Process Data
    
    for(int i=0,j=1;i<(*ptr).length();i++,j++){ //Go through each character
        if(i==(*ptr).length()-1){ //If last character in string
            aL+=j;                //Add j to ave number of letters
        }
        if((*ptr)[i]==' '){       //If there is a space then new word
            counter++;
            aL+=--j;
            j=0;
        }
    }
    nW=counter;
    aL/=nW;
}