/* File:   absval.h
 * Author: Javier B
 * Created on December 5, 2016, 11:07 AM
 * Purpose: Class Specification File for
 */

#ifndef ABSVAL_H
#define ABSVAL_H

//System Libraries

//User Libraries

template <class T>
T absVal(T num){
    if(num>=0)return num;
    else return num*-1;
}

#endif /* ABSVAL_H */

