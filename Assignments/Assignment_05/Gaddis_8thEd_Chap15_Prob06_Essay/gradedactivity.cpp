/* File:   gradedactivity.h
 * Author: Javier B
 * Created on December 5, 2016, 8:21 AM
 * Purpose: Class Implementation File for graded activity
 */

#include "gradedactivity.h"

char GradedActivity::getLetterGrade() const{
    if(score>89)
        return 'A';
    else if(score>79)
        return 'B';
    else if(score>69)
        return 'C';
    else if(score>59)
        return 'D';
    else
        return 'F';
}