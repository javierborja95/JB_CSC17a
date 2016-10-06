/* File:   weather.h
 * Author: Javier B
 *
 * Created on October 4, 2016, 3:12 PM
 */

#ifndef WEATHER_H
#define WEATHER_H

enum Month{JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};

struct Weather{
    float rain;
    float high;
    float low;
    float ave;
};

#endif /* WEATHER_H */

