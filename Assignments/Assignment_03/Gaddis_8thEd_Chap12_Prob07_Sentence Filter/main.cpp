/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 12, 2016, 11:00 AM
 * Purpose: Reads in file, changes all letters to lowercase except the first.
 * Output revised contents to new file.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <fstream>   //File I/O
#include <string>    //Strings
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void read(fstream&);
void lower(fstream&,fstream&);
//Execution

int main(int argc, char** argv) {
    //Variables
    fstream inOld; //In old file
    fstream inNew; //In new file
    fstream out;   //Write new file
    //Input Data
    inOld.open("sentences.txt",ios::in);
    read(inOld);
    //Process Data
    inOld.open("sentences.txt",ios::in);
    out.open("revised.txt",ios::out);
    lower(inOld,out);
    //Output Data
    inNew.open("revised.txt",ios::in);
    read(inNew);
    
    return 0;
}

void read(fstream &in){
    //Variables
    string line;
    //Output Data
    if(in.fail()){
        cout<<"File Opening Error"<<endl;
        in.close();
        return;
    }else while(!in.eof()){
        getline(in,line,'.');
        cout<<line<<endl;
    }
    //Close File
    in.close();
}

void lower(fstream &in,fstream &out){
    //Variables
    string line;
    //Check for Errors
    if(in.fail()){
        cout<<"File Opening Error"<<endl;
        in.close();
        return;
    }
    //Input Data
    while(!in.eof()){
        getline(in,line,'.');
    //Output Data
        for(int i=0;i<(line.length());i++){
            if(i==0){
                if(islower(line[i])){
                    line[i]=toupper(line[i]);
                }
            }else{
                if(isupper(line[i])){
                    line[i]=tolower(line[i]);
                }
            }
        }
        out<<line<<".";
    }
    //Close Files
    in.close();
    out.close();
}