/* File:   Phrase.h
 * Author: Javier B
 * Created on December 6, 2016, 12:12 PM
 * Purpose: Class Implementation File for Phrase class
 */

//User Libraries
#include "Phrase.h"
#include "Letter.h"

Phrase::Phrase(unsigned int n,string s){
    //Allocate Memory
    arr=new Letter[n]; //New array of Letters for phrase
    
    //Input Data
    for(int i=0;i<n;i++){               //Initialize phrase array with clue
        arr[i].setChar(s[i]);
        if(isspace(arr[i].getLetter())){//If letter is space
            arr[i].use();               //Don't hide it
        }
    }
    size=n;
}

Phrase::~Phrase(){
    //Deallocate Memory
    delete[] arr;
    arr=nullptr;
}

void Phrase::display(){
    //Output Data
    for(int i=0;i<size;i++){         //Go through clue array
        if(arr[i].isLtUsed()==false){  //If letter has not been used, hide letter
            cout<<"□";
        }else{
            arr[i].display();
        }
    }
    cout<<endl;
}