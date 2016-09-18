/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 18, 2016, 1:30 PM
 * Purpose: Displays truth table
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <iomanip>    //Output Manipulation
using namespace std;  //iostream uses the standard namespace

//User Libraries

//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    bool x, y;
    unsigned int ROW=4;
    
    //Input Data

    //Process Data
                 
    //Output Data
    cout<<"The truth Table"<<endl;
    cout<<"X Y !X !Y X||Y X&&Y X^Y X^Y^Y X^Y^X !(X||Y) !X&&!Y !(X&&Y) !X||!Y\n";
    for(int i=1;i<=ROW;i++){
        switch(i){
            case  1:x=true; y=true; break;
            case  2:x=true; y=false;break;
            case  3:x=false;y=true; break;
            default:x=false;y=false;break;
        }
        cout<<setw(1)<<(x?'T':'F')
            <<setw(2)<<(y?'T':'F')
            <<setw(3)<<(!x?'T':'F')
            <<setw(3)<<(!y?'T':'F')
            <<setw(4)<<(x||y?'T':'F')
            <<setw(4)<<(x&&y?'T':'F')
            <<setw(5)<<(x^y?'T':'F')
            <<setw(5)<<(x^y^y?'T':'F')
            <<setw(6)<<(x^y^x?'T':'F')
            <<setw(7)<<(!(x||y)?'T':'F')
            <<setw(7)<<(!x&&!y?'T':'F')
            <<setw(8)<<(!(x&&y)?'T':'F')
            <<setw(7)<<(!x||!y?'T':'F')<<endl;
    }
    return 0;
}