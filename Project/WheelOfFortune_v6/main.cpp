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
#include "Letter.h"
#include "Keyboard.h"
#include "Phrase.h"

//Global Constants

//Function Prototypes
void play(Game *);
//Execution

int main(int argc, char** argv){
    //Variables
    Game whOfF;       //Wheel of fortune Game object
    Game *ptr=&whOfF; //Pointer to pass Game object
    char choice;      //Menu choice
    
    //Input Data
    do{
        whOfF.menu();
        cin>>choice;
        cin.ignore();
        
    //Process Data
        switch(choice){
            case'1':{
                play(ptr);
                break;
            }
            case'2':{
                whOfF.lderBrd();//****Placeholder pass in pointer*****
                cout<<"Your money = $"<<whOfF.getMoney()<<"0.00\n";
                break;
            }
            case'3':{
                whOfF.write();
                break;
            }
            case'4':{
                whOfF.read();
                break;
            }
        }
    }while((choice=='1'||choice=='2'||
            choice=='3'||choice=='4')&&whOfF.getMoney()>0);
    
    //Process Data
    
    return 0;
}

void play(Game *ptr){
    //Variables
    Play game;      //Play object
    game.play(ptr);
    char option;    //Menu option
    
    //Input Data
    do{
        game.display();
        do{
            game.menu(ptr);
            cin>>option;
            cin.ignore();
            switch(option){
                case'1':
                    game.spin();
                    break;
                case'2':
                    game.buy();
                    break;
                case'3':
                    game.guess(ptr);
                    break;
                default: cout<<"Placeholder for exception"<<endl;
            }
        }while(option<49||option>51);
    //Loop until win or lose
    }while((game.getWin()==false)&&(game.getMoney(ptr)>0));
}