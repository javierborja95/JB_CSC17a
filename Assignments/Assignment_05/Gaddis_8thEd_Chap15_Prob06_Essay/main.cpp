/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November , 2016,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "essay.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int grammar,spelling,length,content;
    //Input Data
    cout<<"This program gets the letter grade of a graded essay"<<endl;
    cout<<"Input grammar points(1-30): ";
    cin>>grammar;
    cout<<"Input spelling points(1-20): ";
    cin>>spelling;
    cout<<"Input length points(1-20): ";
    cin>>length;
    cout<<"Input content points(1-30): ";
    cin>>content;
    
    //Process Data
    Essay paper(grammar,spelling,length,content);
    
    //Output Data
    cout<<"The letter grade for the paper is "<<paper.getLetterGrade()<<endl;

    return 0;
}