/* File:   minmax.h
 * Author: Javier B
 * Created on December 5, 2016, 10:53 AM
 * Purpose: Class Specification File for min and max functions
 */

#ifndef MINMAX_H
#define MINMAX_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries

template <class T>
T minimum(T a,T b){
    if(a<b) return a;
    else return b;
}

template <class T>
T maximum(T a,T b){
    if(a>b) return a;
    else return b;
}

#endif /* MINMAX_H */

