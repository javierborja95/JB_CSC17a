/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October , 2016,  PM
 * Purpose: Displays the joke from a file and displays the punchline from another
 * file. The second file has garbage until the last line.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <fstream>   //File I/O
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void joke();
void pnchLin();
//Execution

int main(int argc, char** argv) {
    //Variables
    
    //Input Data
    joke();
    //Process Data
    
    //Output Data
    pnchLin();
    
    return 0;
}

void joke(){
    //Variables
    fstream file;
    string line;
    //Input Data
    file.open("joke.txt",ios::in);
    if(file.fail()){
        cout<<"joke.txt opening fail"<<endl;
        return;
    }else{
        while(!file.eof()){
            getline(file,line);
            cout<<line;
        }
    }
    cout<<endl;
    file.close();
}

void pnchLin(){
    //Variables
    long int pos;
    fstream file;
    string line;
    //Input Data
    file.open("punchline.txt",ios::in);
    if(file.fail()){
        cout<<"punchline.txt opening fail"<<endl;
        return;
    }else{
        file.seekg(792,ios::beg); //Set to read from 793rd byte
        getline(file,line);
        cout<<line;
    }
    file.close();
}