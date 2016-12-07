/* File:   Play.h
 * Author: Javier B
 * Created on December 5, 2016, 8:56 PM
 * Purpose: Class Specification File for play class
 */

#ifndef PLAY_H
#define PLAY_H

//System Libraries
#include <string>    //Strings
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Game.h"
#include "Keyboard.h"
#include "Phrase.h"

class Play{
    private:
        Clue clue;   //Category and clue phrase
        bool win;    //Win or lose
        Keyboard k;  //Keyboard
        Phrase p;    //Phrase
    public:
        //Member Functions
        void play(Game*);
        ~Play(){
            //delete[] p;
            //p=nullptr;
        }
        void spin();
        void buy();
        void guess(Game*);
        void display();
        void menu(Game*);
        
        //Accessors
        bool getWin()
        {return win;}
        int getMoney(Game *a)
        {return a->getMoney();}
};

#endif /* PLAY_H */

