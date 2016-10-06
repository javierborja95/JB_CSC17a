/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   weather2.h
 * Author: Javier B
 *
 * Created on October 5, 2016, 10:05 PM
 */

#ifndef WEATHER2_H
#define WEATHER2_H

enum Month{JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};

struct Weather2{
    float rain;
    float high;
    float low;
    float ave;
};

#endif /* WEATHER2_H */

