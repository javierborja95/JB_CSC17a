/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 28, 2016, 1:00 PM
 * Purpose: Wheel of fortune. Player guesses a phrase with category as a clue.
 */

//System Libraries
#include <iostream>   //Input/Output
using namespace std;

//User Libraries
#include "Game.h"
#include "Play.h"

//Global Constants

//Function Prototypes
void play(const Game);
//Execution

int main(int argc, char** argv){
    //Variables
    Game game;      //Game object
    Game *ptr=&game;//Pointer to pass game object
    Play theGame;   //Play object
    char choice;    //Menu choice
    
    //Input Data
    do{
        game.menu();
        cin>>choice;
        cin.ignore();
        
    //Process Data
        switch(choice){
            case'1':{
                cout<<theGame.getName(ptr)<<endl;
                break;
            }
            case'2':{
                game.lderBrd();
                cout<<"Your money = $"<<game.getMoney()<<"0.00\n";
                break;
            }
            case'3':{
                game.write();
                break;
            }
            case'4':{
                game.read();
                break;
            }
        }
    }while((choice=='1'||choice=='2'||
            choice=='3'||choice=='4')&&game.getMoney()>0);
    
    //Process Data
    
    return 0;
}