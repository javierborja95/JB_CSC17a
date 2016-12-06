/* File:   Game.h
 * Author: Javier B
 * Created on December 5, 2016, 5:19 PM
 * Purpose: Class Implementation File for Game class
 */

//User Libraries
#include "Game.h"

Game::Game(){
    //Set Random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Fill Library
    counter=0;
    fill();
    //Input
    cout<<"Input your name: ";
    getline(cin,user.name);
    cout<<"Welcome to Wheel of Fortune "<<user.name<<"!\n"
            "Your money = $"<<user.money<<"0.00\n";
}

Game::~Game(){
    delete[] arr;
}

unsigned int *Game::fill(){
    //Variables
    fstream in;       //Input
    char s[SIZE];     //Temp char array
    unsigned int a;   //Temp char
    //Open File
    in.open("phrase.dat",ios::in);
    //Input Data
    while(in>>a){
        in.getline(s,SIZE,'.');
        counter++;    //Add to size of array
    }
    //Allocate Memory
    arr=new unsigned int[counter];
    in.clear();
    in.seekg(0L,ios::beg); //Go back to beginning of file
    //Process Data
    for(int i=0;i<counter;i++){
        arr[i]=in.tellg(); //Each index has a position
        in>>a;
        in.getline(s,SIZE,'.');
    }
    //Output Data
    return arr;
}

void Game::lderBrd(){
    
}

void Game::read(){
    
}

void Game::write(){
    
}

void Game::menu(){
    //Output Data
        cout<<"Your score: "<<user.score<<" points\n\n"
            "Select an option below:\n"
            " 1. Begin a new game of Wheel of Fortune\n"
            " 2. View the leaderboard\n"
            " 3. Append to the Library\n"
            " 4. View the Library(You'll spoil all the answers!)\n\n"
            "Any other input to exit: ";
}

void Game::addMoney(int){
    
}

void Game::addScore(unsigned int){
    
}