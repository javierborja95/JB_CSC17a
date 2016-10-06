/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   speakers.h
 * Author: Javier B
 *
 * Created on October 5, 2016, 8:12 PM
 */

#ifndef SPEAKERS_H
#define SPEAKERS_H

struct Speaker{
    std::string name;
    std::string phone;
    std::string topic;
    float fee;
    bool empty=true;
};

#endif /* SPEAKERS_H */

