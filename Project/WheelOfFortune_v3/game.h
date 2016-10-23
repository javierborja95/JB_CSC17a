/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game.h
 * Author: Javier B
 *
 * Created on October 21, 2016, 9:06 PM
 */

#ifndef GAME_H
#define GAME_H

struct Player{
    std::string name;
    int money=50;        //Player starts with $500.00
    unsigned int score=0;//Player starts with 0 points
};

struct Clue{
    unsigned int categry;
    char phrase[44];     //Max Phrase length
};

struct Letter{
    char letter;
    bool isUsed=false;
};

#endif /* GAME_H */

