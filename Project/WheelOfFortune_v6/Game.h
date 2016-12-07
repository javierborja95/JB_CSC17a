/* File:   Game.h
 * Author: Javier B
 * Created on December 5, 2016, 5:19 PM
 * Purpose: Class Specification File for Game class
 */

#ifndef GAME_H
#define GAME_H

//System Libraries
#include <cstdlib>   //Random seed
#include <fstream>   //File Input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Player.h"
#include "Clue.h"
//Variables
const int SIZE=44; //Max Size of Char array

class Game{
    private:
        Player user;               //User
        unsigned int *arr=nullptr; //Index array to find categories and clues
        int counter;               //Size of Library
        fstream in;                //Input
        
    public:
        //Constructor
        Game();
        //Destructor
        ~Game();
        
        //Member Functions
        void fill();    //Creates an index to the library
        void menu();    //Displays the menu
        void lderBrd(); //Displays a leaderboard
        void write();   //Appends to the library
        void read();    //Displays the entire library
        
        //Mutators
        
        //Accessors
        string getName(){return user.name;}
        unsigned int getScore(){return user.score;}
        int getMoney(){return user.money;}
        
        //Add Functions
        void addMoney(int);
        void addScore(unsigned int);
        
        //Subtract Functions
        void subMoney();
        
        //Operator Overloads
        
        //Play class can access private members of Game class
        friend class Play;
};

#endif /* GAME_H */

