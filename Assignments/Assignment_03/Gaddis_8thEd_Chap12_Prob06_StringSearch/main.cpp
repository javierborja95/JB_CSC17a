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
#include <vector>    //Vectors
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void read5(fstream&);
void find(fstream&,string);
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
    read5(file);
    //Search Data
    cout<<"Input a string to search for: ";
    cin>>text;
    find(file,text);
    //Close File
    file.close();
    
    return 0;
}

void read5(fstream &file){
    //Variables
    string line;
    string temp;
    int count=0;
    //Output Data
    while(!file.eof()){
        count++;
        cout<<count<<":";
        getline(file,line);
        cout<<line<<endl;
    }
    cout<<endl<<endl<<endl;
}

void find(fstream &file,string a){
    //Variables
    vector<int> vArray; //Array of lines where string is found
    string line;
    int *count, //Array of occurences
           n=0; //Number of occurences
    //Input Data
    file.clear();           //Clear eof flag
    file.seekg(0L,ios::beg);//Go back to beginning
    cout<<"Searching for '"<<a<<"'..."<<endl<<endl;
    //Process Data
    for(int i=0;(!file.eof());i++){
        bool found=false;
        getline(file,line);
        if(line.find(a)!=string::npos){ //Check if line string is in a string
            found=true;
            n++;
        }
        if(found==true){
            vArray.push_back(i);
        }
    }
    //Output Data
    cout<<"'"<<a<<"' found in "<<n<<" lines"<<endl;
    if(vArray.size()==0) return;
    else{
        int temp=0, //temp index counter
               i=0; //index
        file.clear();           //Clear eof flag
        file.seekg(0L,ios::beg);//Go back to beginning
        while(!file.eof()){
            getline(file,line);
            if(vArray[temp]==i){
                cout<<i<<":"<<line<<endl;
                temp++;
            }
            i++;
        }
    }
}