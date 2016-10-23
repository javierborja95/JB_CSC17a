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
    int money;
    unsigned int score;
};

struct Clue{
    unsigned int categry;
    char phrase[44];
};

struct Letter{
    char letter;
    bool isUsed=false;
};

#endif /* GAME_H */

