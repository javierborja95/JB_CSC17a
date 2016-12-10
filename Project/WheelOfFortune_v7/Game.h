/* File:   Game.h
 * Author: Javier B
 * Created on December 5, 2016, 5:19 PM
 * Purpose: Class Specification File for Game class
 */

#ifndef GAME_H
#define GAME_H

//System Libraries
#include <cstdlib>   //Random seed
#include <ctime>     //Time
#include <fstream>   //File Input/Output
#include <iomanip>   //Output manipulation
#include <vector>    //Vectors
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Base.h"
#include "Player.h"
#include "Clue.h"
#include "addSub.h"

//Variables
const int SIZE=44; //Max Size of Char array

class Game: public Base{
    private:
        unsigned int *arr;         //Index array to find categories and clues
        int counter;               //Size of Library
        fstream in;                //Input
        
    public:
        int staticCalls; //Keeps track of Letter calls, just for fun
        //Constructor
        Game();  //Introduction, sets random seed, creates library
        
        //Destructor
        ~Game(); //Deletes library, closes file streams, appends to leaderboard
        
        //Member Functions
        void fill();          //Creates an index to the library
        void menu();          //Displays the menu
        void lderBrd();       //Displays a leaderboard
        void write();         //Appends to the library
        void read();          //Displays the entire library
        void addLder();       //Adds profile to leaderboard
        bool isGood(char[]);  //Input verification
        
        //Add Functions
        void addMoney(int);
        void addScore(unsigned int);
        
        //Subtract Functions
        void subMoney(int);
        
        //Play class can access private members of Game class
        friend class Play;
};

#endif /* GAME_H */