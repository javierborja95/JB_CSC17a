/*
 * File:   info.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 7:47 PM
 * Purpose: Personal info class specification
 */

#ifndef INFO_H
#define INFO_H

//System Libraries
#include <iostream> //Input/Output
using namespace std;

class Info{
    private:
        string name;
        string address;
        int age;
        char phone[10];
    public:
        Info();
        void setInfo(string,string,int,char[]);
        string getName(){return name;}
        string getAdd(){return address;}
        int getAge(){return age;}
        void getPhone();
};

#endif /* INFO_H */

