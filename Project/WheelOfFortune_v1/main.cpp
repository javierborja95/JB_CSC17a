/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 21, 2016, 8:30 PM
 * Purpose: Wheel of fortune. Player guesses a phrase with category as a clue.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <fstream>   //File I/O
#include <string>    //Strings
#include <cstdlib>   //Random Library
#include <ctime>     //Time Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "game.h"
//Global Constants

//Function Prototypes
void menu(Player);
void write();
void read();
bool isGood(string);
//Execution

int main(int argc, char** argv) {
    //Set Random seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    char choice;
    Player user={"(name)",0};
    //Input Data
    do{
        menu(user);
        cin>>choice;
        cin.ignore();
    //Process Data
        switch(choice){
            case'1':
                cout<<"In progress"<<endl;
                break;
            case'2':
                cout<<"In progress"<<endl;
                break;
            case'3':
                write();
                break;
            case'4':
                read();
            default:cout<<"Thanks for playing "<<user.name<<"!"<<endl;
        }
    }while(choice=='1'||choice=='2'||choice=='3'||choice=='4');
    //Output Data

    return 0;
}

void menu(Player a){
    //Output Data
    cout<<"Welcome to Wheel of Fortune "<<a.name<<"!\n"
            "Select an option below:\n"
            " 1. Begin a new game of Wheel of Fortune\n"
            " 2. Continue a game of Wheel of Fortune\n"
            " 3. Append to the Library\n"
            " 4. View the Library\n\n"
            "Any other input to exit\n\n";
}

void write(){
    //Variables
    char choice;
    fstream out;
    string line;
    
    //Open File
    out.open("phrase.dat",ios::app);
    //Input Data
    cout<<endl;
    do{
        cout<<endl<<"Input 1 to input a phrase\n"
                "Input 0 to exit"<<endl;
        cin>>choice;
        cin.ignore();
        if(choice=='1'){
            cout<<"Input a category:\n"
                    "1 TV Show \n"
                    "2 Event \n"
                    "3 Movie \n"
                    "4 Landmark \n"
                    "5 Famous Person \n"
                    "6 Thing \n"
                    "7 Song Title \n";
            cin>>choice;
            cin.ignore();
            switch(choice){
                case '1':
                    cout<<"TV Show"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"1"<<line<<"."<<endl;
                        }
                    }
                    break;
                case '2':
                    cout<<"Event"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"2"<<line<<"."<<endl;
                        }
                    }
                    break;
                case '3':
                    cout<<"Movie"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"3"<<line<<"."<<endl;
                        }
                    }
                    break;
                case '4':
                    cout<<"Landmark"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"4"<<line<<"."<<endl;
                        }
                    }
                    break;
                case '5':
                    cout<<"Famous Person"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"5"<<line<<"."<<endl;
                        }
                    }
                    break;
                case '6':
                    cout<<"Thing"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"6"<<line<<"."<<endl;
                        }
                    }
                    break;
                case '7':
                    cout<<"Song Title"<<endl;
                    cout<<"Input your phrase in all CAPS(max 44 characters): "<<endl;
                    getline(cin,line);
                    if(isGood(line)){
                        cin>>choice;
                        cin.ignore();
                        if(choice=='1'){
                            out<<"7"<<line<<"."<<endl;
                        }
                    }
                    break;
                default:cout<<"Incorrect input"<<endl<<endl;
            }
            choice='1';
        }
    }while(choice=='1');
    //Close File
    out.close();
}

void read(){
    //Variables
    Clue clue;
    fstream in;
    //Open File
    in.open("phrase.dat",ios::in);
    //Input Data
    while(in>>clue.categry){
        getline(in,clue.phrase,'.');
    //Output Data
        switch(clue.categry){
            case 1:
                cout<<"TV Show"<<endl;
                break;
            case 2:
                cout<<"Event"<<endl;
                break;
            case 3:
                cout<<"Movie"<<endl;
                break;
            case 4:
                cout<<"Landmark"<<endl;
                break;
            case 5:
                cout<<"Famous Person"<<endl;
                break;
            case 6:
                cout<<"Thing"<<endl;
                break;
            default:
                cout<<"Song Title"<<endl;
        }
        cout<<clue.phrase<<endl;
    }
    //Close Files
    in.close();
    cout<<endl;
}

bool isGood(string a){
    //Variables
    bool good=true;
    //Process Data
    if(a.size()<4||a.size()>44){
        good=false;
        cout<<"ERROR: Phrase must be greater than 3 characters and less than 44"<<endl;
    }
    for(int i=0;i<a.size();i++){
        if(isdigit(a[i])){
            cout<<"ERROR: Input must be characters only\n";
            good=false;
        }
        if(islower(a[i])){
            cout<<"ERROR: Phrase must be all CAPS\n";
            good=false;
        }
        if(!good)break;
    }
    //Output Data
    if(good){
        cout<<"Do you really wish to add the following phrase?"<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i];
            if((i+1)%22==0&&i!=(a.size()-1)){
                if(isalpha(a[i+1])&&isspace(a[i+2])){
                    i++;
                    cout<<a[i]<<endl;
                }
                else if(isspace(a[i+1])) cout<<endl;
                else cout<<"-"<<endl;
            }
        }
        cout<<endl<<endl<<"Input 1 to append\n"
                "Or anything else to cancel: ";
    }
    return good;
}