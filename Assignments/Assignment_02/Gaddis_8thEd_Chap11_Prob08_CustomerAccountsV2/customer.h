/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customer.h
 * Author: Javier B
 *
 * Created on October 5, 2016, 7:27 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer{
    std::string name;
    std::string address;
    std::string zip;
    std::string phone;
    float balance;
    std::string date;
};

#endif /* CUSTOMER_H */

