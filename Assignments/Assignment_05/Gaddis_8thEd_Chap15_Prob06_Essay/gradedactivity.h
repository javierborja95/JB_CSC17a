/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* File:   gradedactivity.h
 * Author: Javier B
 * Created on December 5, 2016, 8:21 AM
 * Purpose: Class Specification File for graded activity
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries

class GradedActivity{
    protected:
        float score;   // To hold the numeric score
    public:
        // Default constructor
        GradedActivity()
            {score=0.0;}

        // Constructor
        GradedActivity(float s)
            {score=s;}

        // Mutator function
        void setScore(float s) 
            {score=s;}

        // Accessor functions
        float getScore() const
            {return score;}

        virtual char getLetterGrade() const;
};

#endif /* GRADEDACTIVITY_H */

