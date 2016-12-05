/* File:   shiftsupervisor.h
 * Author: Javier B
 * Created on December 4, 2016, 4:23 PM
 * Purpose: Class Specification File for
 */

#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

//System Libraries
#include <cstdlib>   //Exit Function
#include <iostream>  //Input/ Output Stream Library
//User Libraries
#include "employee.h"

class ShiftSupervisor: public Employee{
    private:
        float salary;
        float bonusRate;
        int nBonus;
    public:
        ShiftSupervisor(){salary=0.0f;bonusRate=0.0f;nBonus=0;}
        void setSalary(float);
        void setBRate(float);
        void setNBonus(int);
        float getSalary(){return salary+bonusRate*nBonus;}
        float getBRate(){return bonusRate;}
        int getNBonus(){return nBonus;}
};

#endif /* SHIFTSUPERVISOR_H */

