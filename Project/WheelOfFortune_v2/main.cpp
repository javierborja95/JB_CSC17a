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
#include <cstring>   //Cstrings
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "game.h"
//Global Constants

//Function Prototypes
void menu(Player);
void write(int);
void read(int);
bool isGood(char[],int);
unsigned int* fill(int,int&);
void game(unsigned int*,int,int,Player&);
void categry(int);
void viewBrd(Letter*,Letter*,int,int,Player);
bool spin(Letter*,Letter*,int,int,Player&,Clue);
bool vowel(Letter*,Letter*,int,int,Player&,Clue);
bool guess(Letter*,Letter*,int,int,Player&,Clue);
//Execution

int main(int argc, char** argv) {
    //Set Random seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    const int SIZE=44; //Max size of char array
    char choice;
    Player user={"(name)",50,0};
    unsigned int *arr; //Index array to find categories and clues
    int counter=0;     //Index starts at zero
    
    //Input Data
    arr=fill(SIZE,counter);
    do{
        menu(user);
        cin>>choice;
        cin.ignore();
    //Process Data
        switch(choice){
            case'1':
                game(arr,counter,SIZE,user);
                break;
            case'2':
                cout<<"In progress"<<endl;
                break;
            case'3':
                write(SIZE);
                break;
            case'4':
                read(SIZE);
                break;
        }
    }while((choice=='1'||choice=='2'||choice=='3'||choice=='4')&&user.money>0);
    //Output Data
    cout<<"Thanks for playing "<<user.name<<"!"<<endl;
    cout<<"Your final score: "<<user.score<<" points"<<endl;
    //Deallocate Memory
    delete[] arr;
    
    return 0;
}

void menu(Player a){
    //Output Data
    cout<<"Welcome to Wheel of Fortune "<<a.name<<"!\n"
            "Your money = $"<<a.money<<"0.00\n"
            "Your score: "<<a.score<<" points\n\n"
            "Select an option below:\n"
            " 1. Begin a new game of Wheel of Fortune\n"
            " 2. Continue a game of Wheel of Fortune\n"
            " 3. Append to the Library\n"
            " 4. View the Library(You'll spoil all the answers!)\n\n"
            "Any other input to exit: ";
}

void write(int size){
    //Variables
    char choice;
    char input;
    fstream out;
    char line[size];
    
    //Open File
    out.open("phrase.dat",ios::app);
    //Input Data
    do{
        cout<<endl<<"Input 1 to input a phrase\n"
                "Input 0 to exit: ";
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
                    "7 Song Title \n\n"
                    "0 Exit: ";
            cin>>input;
            cin.ignore();
    //Output Data
            if(input>48&&input<56){
                categry(input-48);
                cout<<"Input your phrase(max 44 characters): "<<endl;
                cin.getline(line,size);
                if(isGood(line,size)){
                    cin>>choice;
                    cin.ignore();
                    if(choice=='1'){
                        out<<input;
                        for(int i=0;i<strlen(line);i++){
                            out<<static_cast<char>(toupper(line[i]));
                        }
                        out<<"."<<endl;
                        cout<<"You must restart the game for effects to take effect"<<endl;
                    }
                }
            }
        }
    }while(choice=='1');
    //Close File
    out.close();
}

void read(int size){
    //Variables
    Clue clue;
    fstream in;
    //Open File
    in.open("phrase.dat",ios::in);
    //Input Data
    while(in>>clue.categry){
        in.getline(clue.phrase,size,'.');
    //Output Data
        categry(clue.categry);
        cout<<clue.phrase<<endl;
    }
    //Close Files
    in.close();
    cout<<endl;
}

bool isGood(char a[],int size){
    //Variables
    bool good=true;
    //Process Data
    if(strlen(a)<4||strlen(a)>44){
        good=false;
        cout<<"ERROR: Phrase must be greater than 3 characters and less than 44"<<endl;
    }
    for(int i=0;i<strlen(a);i++){
        if(isdigit(a[i])||(!isalpha(a[i])&&!isspace(a[i]))){
            cout<<"ERROR: Input must be characters only\n";
            good=false;
        }
        if(!good)break;
    }
    //Output Data
    if(good){
        cout<<"Do you really wish to add the following phrase?"<<endl;
        for(int i=0;i<strlen(a);i++){
            cout<<static_cast<char>(toupper(a[i]));
        }
        cout<<endl<<endl<<"Input 1 to append\n"
                "Or anything else to cancel: ";
    }
    return good;
}

unsigned int* fill(int size,int &n){
    //Variables
    Clue clue;
    unsigned int *arr;
    fstream in;
    //Open File
    in.open("phrase.dat",ios::in);
    //Input Data
    while(in>>clue.categry){
        in.getline(clue.phrase,size,'.');
        n++;
    }
    //Allocate Memory
    arr=new unsigned int[n];
    in.clear();
    in.seekg(0L,ios::beg);
    //Process Data
    for(int i=0;i<n;i++){
        arr[i]=in.tellg();
        in>>clue.categry;
        in.getline(clue.phrase,size,'.');
    }
    //Output Data
    return arr;
}

void game(unsigned int *a,int i,int size,Player &user){
    //Variables
    fstream in;
    Clue clue;            //Clue with category and phrase
    int index=(rand()%i); //Index to choose clue
    bool win=false;       //Win bool
    Letter *phrase,*kyBoard; //Pointer arrays of clue phrase and alphabet
    const int SIZE=26;    //Size of kyBoard array
    char option;
    //Open File
    in.open("phrase.dat",ios::in);
    //Input Data
    in.seekg(a[index],ios::beg);
    in>>clue.categry;
    in.getline(clue.phrase,size,'.');
    //Process Data
    //Allocate Memory
    kyBoard=new Letter[SIZE];
    phrase=new Letter[strlen(clue.phrase)];
    for(int j=0;j<SIZE;j++){     //Initialize the alphabet
        kyBoard[j].letter='A'+j; //Ascii code
    }
    for(int j=0;j<strlen(clue.phrase);j++){//Initialize phrase array with clue
        phrase[j].letter=clue.phrase[j];
        if(isspace(phrase[j].letter)){     //If letter is space
            phrase[j].isUsed=true;         //Don't hide it
        }
    }
    //Process Data
    do{
        categry(clue.categry);
        viewBrd(phrase,kyBoard,strlen(clue.phrase),SIZE,user);
        do{
            cout<<"Your money = $"<<user.money*10<<".00"<<endl;
            cout<<endl<<endl<<"What would you like to do?"<<endl;
            cout<<  " 1. Spin the Wheel ✪\n"
            " 2. Buy a vowel ($300.00)\n"
            " 3. Solve the Puzzle ✉(Bad guess lose $200.00)\n"<<endl;
            cin>>option;
            cin.ignore();
            switch(option){
                case'1':
                    win=spin(phrase,kyBoard,strlen(clue.phrase),SIZE,user,clue);
                    break;
                case'2':
                    if(user.money<=30){
                        cout<<"You don't have enough money!"<<endl;
                        cout<<"Spin the wheel or guess the puzzle"<<endl;
                        break;
                    }
                    win=vowel(phrase,kyBoard,strlen(clue.phrase),SIZE,user,clue);
                    break;
                case'3':
                    win=guess(phrase,kyBoard,strlen(clue.phrase),SIZE,user,clue);
                    if(win==false){
                        cout<<"You did not guess correctly. You have lost $200.00\n";
                        user.money-=20;
                    }
                    break;
                default: cout<<"ERROR: Bad Input"<<endl;
            }
        }while(option<49||option>51);
    }while(win==false&&user.money>0);
    //Output Data
    if(user.money<=0){
        cout<<"You have no money.\n"
            "You must restart the game to play again"<<endl;
    }else cout<<"Congrats you win!\n"
            "You have $"<<user.money*10<<".00 left in your account"<<endl;
    //Deallocate Memory
    delete[] phrase;
    delete[] kyBoard;
    
    in.close();
}

void categry(int a){
    //Output Data
    switch(a){
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
}

void viewBrd(Letter *clue,Letter *key,int n,int alpha,Player a){
    //Output Data
    for(int i=0;i<n;i++){
        if(clue[i].isUsed==false){
            cout<<"□";
        }else{
            cout<<clue[i].letter;
        }
    }
    cout<<endl<<"Your keyboard:"<<endl;
    for(int i=0;i<alpha;i++){
        if(key[i].isUsed==false){
            cout<<key[i].letter;
        }else cout<<"■";
        if((i+1)%13==0) cout<<endl;
    }
}

bool spin(Letter *phrase,Letter *key,int n,int alpha,Player &a,Clue clue){
    //Variables
    const int SIZE=12;     //Possible Options of wheel
    int wheel[SIZE]={0,0,0,5,5,10,15,15,20,25,30,40};
    int choice=rand()%SIZE;//Random wheel choice
    char input;            //Letter input
    bool error;            //Incorrect letter input
    bool match=false;      //Did letter match?
    int money=wheel[choice];
    int points=0;          //Counter for points
    //Input Data
    cout<<"Spinning...\nPress Enter to continue";
    cin.get();
    cout<<"_________________________________________"<<endl;
    if(money==0) cout<<"You spun a free guess"<<endl;
    else cout<<endl<<"You spun $"<<money*10<<".00"<<endl;
    categry(clue.categry);
    viewBrd(phrase,key,strlen(clue.phrase),alpha,a);
    do{
        error=false;
        cout<<"What letter do you want to use? ";
        cin>>input;
        cin.ignore();
    //Process Data
        if(!isalpha(input)){
            cout<<"Input must be part of the alphabet"<<endl;
            error=true;
        }
        input=static_cast<char>(toupper(input));
        if(input=='A'||input=='E'||input=='I'||input=='O'||input=='U'){
            cout<<"You have to buy vowels"<<endl;
            error=true;
        }
        if(!error){
            for(int i=0;i<alpha;i++){
                if(key[i].letter==input){
                    if(key[i].isUsed==true){
                        cout<<"You already used that letter"<<endl;
                        error=true;
                    }else key[i].isUsed=true;
                }
            }
        }
    }while(error);
    for(int i=0;i<n;i++){
        if(input==phrase[i].letter){
            points+=10;
            match=true;
            phrase[i].isUsed=true;
        }
    }
    //Output Data
    if(match){
        cout<<"You have been awarded $"<<money*10<<".00"<<endl;
        a.money+=money;
        cout<<"You gain 10 points for each letter guessed"<<endl;
        cout<<"You gained "<<points<<"points"<<endl;
        a.score+=points;
        for(int i=0;i<n;i++){
            if(phrase[i].isUsed==false){
                return false;//Not all letters are revealed, win=false;
            }
        }
        return true;         //All letters of phrase are revealed, return true
    }else{
        a.money-=money;
        cout<<"_________________________________________"<<endl;
        cout<<"You have lost $"<<money*10<<".00."<<endl;
    }
    
    return false;
    
}

bool vowel(Letter *phrase,Letter *key,int n,int alpha,Player &a,Clue clue){
    //Variables
    char input;
    bool error;
    //Input Data
    if((key[0].isUsed)&&(key[4].isUsed)&&(key[8].isUsed)&&(key[14].isUsed)&&(key[20].isUsed)){
        cout<<"You have already bought all the vowels"<<endl;
        return false;
    }
    do{
        error=false;
        cout<<"_________________________________________"<<endl;
        categry(clue.categry);
        viewBrd(phrase,key,strlen(clue.phrase),alpha,a);
        cout<<"Which vowel do you want to buy? ";
        cin>>input;
        cin.ignore();
        input=static_cast<char>(toupper(input));
        if(input=='A'||input=='E'||input=='I'||input=='O'||input=='U'){
            
        }
        else{
            cout<<"You did not choose a vowel"<<endl;
            error=true;
        }
        if(error==false){
            for(int i=0;i<alpha;i++){
                if(key[i].letter==input){
                    if(key[i].isUsed==true){
                        cout<<"You already used that letter"<<endl;
                        error=true;
                    }else key[i].isUsed=true;
                }
            }
        }
    }while(error==true);
    
    //Process Data
    cout<<"You have bought a vowel for $300.00"<<endl;
    a.money-=30;
    for(int i=0;i<n;i++){
        if(phrase[i].letter==input)
            phrase[i].isUsed=true;
    }
    for(int i=0;i<n;i++){
        if(phrase[i].isUsed==false){
            return false;//Not all letters are revealed, win=false;
        }
    }
    return true;         //All letters of phrase are revealed, return true
}

bool guess(Letter *phrase,Letter *key,int n,int alpha,Player &a,Clue clue){
    //Variables
    string answer;
    int counter=0;  //Amount of empty letters in keyboard array
    int score=30;
    //Input Data
    categry(clue.categry);
    viewBrd(phrase,key,strlen(clue.phrase),alpha,a);
    cout<<"Input the final answer: ";
    getline(cin,answer);
    //Process Data
    for(int i=0;i<strlen(clue.phrase);i++){
        answer[i]=static_cast<char>(toupper(answer[i]));
    }
    for(int i=0;i<strlen(clue.phrase);i++){
        if(phrase[i].letter!=answer[i]){//Check to see if all letters match
            return false;               //Phrase did not match answer
        }
    }
    for(int i=0;i<alpha;i++){
        if(key[i].isUsed==false){
            counter++;
        }
    }
    //Output Data
    score*=counter;
    cout<<"You gain 30 points for each hidden letter you guessed"<<endl;
    cout<<"You gain "<<score<<" points"<<endl;
    a.score+=score;
    
    return true;
}
