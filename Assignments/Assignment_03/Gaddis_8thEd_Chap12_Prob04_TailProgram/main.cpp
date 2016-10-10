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
void read3(fstream&);
//Execution

int main(int argc, char** argv) {
    //Variables
    string text; //Name of file
    fstream file;
    
    //Input Data
    cout<<"This program only displays the last 10 lines of a file\n";
    cout<<"Input the name of file to open.\n"
          "Choices are 'text1.txt' or 'text2.txt'\n";
    cin>>text;
    //Process Data
    file.open(text.c_str(),ios::in);
    if(file.fail()){
        cout<<text<<" does not exist."<<endl;
        return 0;
    }
    else cout<<text<<" opening success."<<endl;
    
    //Output Data
    read3(file);
    file.close();
    
    return 0;
}

void read3(fstream &file){
    //Variables
    string line;
    string temp;
    int count=0;
    int *counter;
    //Input Data
    while(!file.eof()){
        count++;
        getline(file,line);
    }
    cout<<"There are "<<count<<" lines in the file"<<endl;
    //Process Data
    counter=new int[count]; //Set byte positions in array
    file.clear();           //Clear eof flag
    file.seekg(0L,ios::beg);//Go back to beginning
    for(int i=0;i<count;i++){
        counter[i]=file.tellg();
        getline(file,line);
    }
    //Output Data
    file.clear();           //Clear eof flag
    file.seekg(0L,ios::beg);//Go back to beginning
    if(count<=10){          //Less than ten lines output all
        for(int i=1;!file.eof();i++){
            getline(file,line);
            cout<<"line #"<<i<<": "<<line<<endl;
        }
    }else{                 //Output last 10 lines
        for(int i=count-10;i<count;i++){
            file.seekg(counter[i],ios::beg);
            getline(file,line);
            cout<<"line #"<<i+1<<": "<<line<<endl;
        }
    }
    file.close();
    //Deallocate Memory
    delete[] counter;
}