/* File:   essay.h
 * Author: Javier B
 * Created on December 5, 2016, 8:32 AM
 * Purpose: Class Specification File for Essay class
 */

#ifndef ESSAY_H
#define ESSAY_H

//System Libraries
#include <cstdlib>   //Exit function
#include <iostream>  //Input/Output
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "gradedactivity.h"

class Essay: public GradedActivity{
    private:
        int grammar;
        int spelling;
        int length;
        int content;
    public:
        Essay(int,int,int,int);
        virtual char getLetterGrade();
};

#endif /* ESSAY_H */

