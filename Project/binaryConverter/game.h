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
    float money;
};

struct Clue{
    unsigned int categry;
    char phrase[44];
};

struct Letter{
    unsigned char letter;
    bool isUsed;
};

#endif /* GAME_H */

