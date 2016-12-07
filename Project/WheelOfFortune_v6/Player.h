/* File:   Player.h
 * Author: Javier B
 * Created on December 5, 2016, 5:38 PM
 * Purpose: Struct Specification File for Player
 */

#ifndef PLAYER_H
#define PLAYER_H

//System Libraries
#include <iostream>
#include <string>
using namespace std; //Namespace of the System Libraries

//User Libraries

struct Player{
    string name;
    int money;         //Player starts with $500.00
    unsigned int score;//Player starts with 0 points
    
    Player(){
        money=50;
        score=0;
    }
};

#endif /* PLAYER_H */

