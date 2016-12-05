/* File:   employee.h
 * Author: Javier B
 * Created on December 4, 2016, 2:23 PM
 * Purpose: Class Specification File for Employee class
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//System Libraries
#include <string> //String library
using namespace std; //Namespace of the System Libraries
//User Libraries

class Employee{
    private:
        string name;
        string num;
        string hireDat;
    public:
        Employee(){name="";num="";hireDat="";}
        void setName(string s){name=s;}
        void setNum(string s){num=s;}
        void setHDat(string s){hireDat=s;}
        string getName(){return name;}
        string getNum(){return num;}
        string getHDat(){return hireDat;}
};

#endif /* EMPLOYEE_H */

