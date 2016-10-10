/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 9, 2016, 8:00 PM
 * Purpose: Displays first 10 lines of a file, or all if less than 10 lines
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <fstream>   //Input I/O
#include <string>    //STrings
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void read1(fstream&);
//Execution

int main(int argc, char** argv) {
    //Variables
    string text; //Name of file
    fstream file;
    
    //Input Data
    cout<<"Input the name of file to open.\n"
          "choices are 'text1.txt' or 'text2.txt'\n";
    cin>>text;
    //Process Data
    file.open(text.c_str(),ios::in);
    if(file.fail()){
        cout<<text<<" does not exist."<<endl;
        return 0;
    }
    else cout<<text<<" opening success."<<endl;
    
    //Output Data
    read1(file);
    file.close();
    
    return 0;
}

void read1(fstream &file){
    //Variables
    string line;
    int count=0;
    while(!file.eof()&&count<10){
        count++;
        cout<<count<<"******";
        getline(file,line);
        cout<<line<<endl;
    }
    if(file.eof())cout<<"All the file has been displayed"<<endl;
    else cout<<"Only 10 lines of text has been displayed"<<endl;
}