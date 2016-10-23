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
    const int size=3;
    fstream out,in;
    Player user[size];
    int n;
    Player player;
    //Open File
    out.open("users.dat",ios::out|ios::binary);
    //Input Data
    user[0].name="Johnny Appleseed";
    user[0].score=1250;
    user[1].name="Don Cook";
    user[1].score=6850;
    user[2].name="Joe Smith";
    user[2].score=7400;
    //while(in>>clue.categry){
        //in.getline(clue.phrase,size,'.');
    //Output Data
    for(int i=0;i<size;i++){
        n=user[i].name.size();
        out.write(reinterpret_cast<char *>(&n),sizeof(n));
        out.write(user[i].name.c_str(),n);
        out.write(reinterpret_cast<char *>(&user[i].score),sizeof(unsigned int));
    }
    //Close Files
    out.close();
    //Open to reinterpret
    in.open("users.dat",ios::in|ios::binary);
    //Input Data
    while(in.read(reinterpret_cast<char *>(&n),sizeof(n))){
    //Output Data
        player.name.resize(n);
        in.read(&player.name[0],n);
        in.read(reinterpret_cast<char *>(&player.score),sizeof(unsigned int));
        cout<<player.name<<endl;
        cout<<"Score: "<<player.score<<" points"<<endl;
    }
    in.close();
    
    return 0;
}