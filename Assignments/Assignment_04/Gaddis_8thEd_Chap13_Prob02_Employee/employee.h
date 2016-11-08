/* 
 * File:   employee.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 5:45 PM
 * Purpose: Employee class specification file
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//System Libraries
#include <string>
using namespace std;

class Employee{
    private:
        string name={""};
        int idNum=0;
        string dprtmnt={""};
        string pos={""};
    public:
        void setEmp(string,int);
        void setJob(string,string);
        string getName(){return name;}
        string getDep(){return dprtmnt;}
        string getPos(){return pos;}
        int getId(){return idNum;}
};

#endif /* EMPLOYEE_H */

