/* File:   essay.h
 * Author: Javier B
 * Created on December 5, 2016, 8:32 AM
 * Purpose: Class Specification File for Essay class
 */

#include "essay.h"

Essay::Essay(int a, int b, int c, int d){
    if(a<0||a>30||b<0||b>20||c<0||c>20||d<0||d>30){
        cout<<"Error: Incorrect range"<<endl;
        exit(1);
    }
    grammar=a;
    spelling=b;
    length=c;
    content=d;
}

char Essay::getLetterGrade(){
    score=grammar+spelling+length+content;
    
    return GradedActivity::getLetterGrade();
}