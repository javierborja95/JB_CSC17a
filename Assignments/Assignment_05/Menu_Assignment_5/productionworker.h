/* File:   productionworker.h
 * Author: Javier B
 * Created on December 4, 2016, 2:32 PM
 * Purpose: Class Specification File for ProductionWorker class
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

//System Libraries
#include <cstdlib>   //Exit Function
#include <iostream>  //Input/ Output Stream Library
//User Libraries
#include "employee.h"

class ProductionWorker: public Employee{
    private:
        int shift;
        float payRate;
    public:
        ProductionWorker(){shift=0;payRate=0.0f;}
        ProductionWorker(int,float);
        void setShift(int);
        void setPayRate(float);
        string getShift();
        float getPayRate(){return payRate;}
        float getPay(int);
};

#endif /* PRODUCTIONWORKER_H */

