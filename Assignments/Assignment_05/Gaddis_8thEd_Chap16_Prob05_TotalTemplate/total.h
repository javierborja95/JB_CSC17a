/* File:   total.h
 * Author: Javier B
 * Created on December 5, 2016, 11:19 AM
 * Purpose: Template Specification File for total
 */

#ifndef TOTAL_H
#define TOTAL_H

//System Libraries
#include <iostream> //Input/Output
using namespace std;
//User Libraries

template <class T1>
T1 total(int n){
    T1 tot=0;
    T1 input;
    for(int i=0;i<n;i++){
        cout<<"Input value to add: ";
        cin>>input;
        tot=tot+input;
    }
    return tot;
}

#endif /* TOTAL_H */

