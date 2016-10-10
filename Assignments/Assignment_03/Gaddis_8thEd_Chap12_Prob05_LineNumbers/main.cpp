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
void read4(fstream&);
//Execution

int main(int argc, char** argv) {
    //Variables
    string text; //Name of file
    fstream file;
    
    //Input Data
    cout<<"Input 'text1.txt' to open a file of the same name: \n";
    cin>>text;
    //Process Data
    file.open(text.c_str(),ios::in);
    if(file.fail()){
        cout<<text<<" does not exist."<<endl;
        return 0;
    }
    else cout<<text<<" opening success."<<endl;
    
    //Output Data
    read4(file);
    file.close();
    
    return 0;
}

void read4(fstream &file){
    //Variables
    string line;
    string temp;
    //Output Data
    cin.ignore();
    do{
        int count=0;
        while(!file.eof()&&count<24){
            count++;
            cout<<count<<":";
            getline(file,line);
            cout<<line<<endl;
        }
        cout<<endl<<"Input anything to continue";
        cin.get();
        cout<<endl<<endl<<endl;
    }while(!file.eof());
}