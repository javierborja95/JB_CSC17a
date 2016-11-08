/* 
 * File:   employee.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 5:45 PM
 * Purpose: Employee class implementation file
 */

#include "employee.h"

void Employee::setEmp(string name, int idNum){
    this->name=name;
    this->idNum=idNum;
}

void Employee::setJob(string dep, string pos){
    dprtmnt=dep;
    this->pos=pos;
}