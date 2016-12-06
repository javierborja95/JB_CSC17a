/* File:   Play.h
 * Author: Javier B
 * Created on December 5, 2016, 8:56 PM
 * Purpose: Class Specification File for play class
 */

#ifndef PLAY_H
#define PLAY_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "Game.h"

class Play{
    public:
        string getName(Game *a){
            cout<<"Now playing ayy"<<endl;
            return a->user.name;
        }
};

#endif /* PLAY_H */

