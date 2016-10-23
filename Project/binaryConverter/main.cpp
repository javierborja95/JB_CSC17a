/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October , 2016,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>
#include <fstream>  //Input/ Output Stream Library
#include <cstring>   //Cstrings
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "game.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    const int size=44;
    char a='.';
    Clue clue;
    fstream out,in;
    //Open File
    in.open("phrase.dat",ios::in);
    out.open("phrseDat.dat",ios::out|ios::binary);
    //Input Data
    while(in>>clue.categry){
        in.getline(clue.phrase,size,'.');
    //Output Data
        out.write(reinterpret_cast<char *>(&clue),sizeof(clue));
        //out.write(&a,sizeof(a));
    }
    //Close Files
    in.close();
    out.close();
    //Open to reinterpret
    in.open("phrseDat.dat",ios::in|ios::binary);
    //Input Data
    while(in.read(reinterpret_cast<char *>(&clue),sizeof(clue))){
    //Output Data
        cout<<clue.categry<<" "<<clue.phrase<<endl;
    }
    

    return 0;
}