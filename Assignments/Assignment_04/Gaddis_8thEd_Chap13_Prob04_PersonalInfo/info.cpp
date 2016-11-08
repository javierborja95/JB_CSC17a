/*
 * File:   info.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 7:47 PM
 * Purpose: Personal info class implementation
 */

#include "info.h"

Info::Info(){
    name={""};
    address={""};
    age=0;
    for(int i=0;i<10;i++){
        phone[i]='x';
    }
}

void Info::setInfo(string name, string address, int age, char phone[]){
    this->name=name;
    this->address=address;
    this->age=age;
    for(int i=0;i<10;i++){
        this->phone[i]=phone[i];
    }
}

void Info::getPhone(){
    cout<<"(";
    for(int i=0;i<10;i++){
        if(i==3)cout<<")";
        if(i==6)cout<<"-";
        cout<<phone[i];
    }
}