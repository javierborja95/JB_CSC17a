/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sales.h
 * Author: Javier Borja
 *
 * Created on October 3, 2016, 1:09 PM
 */

#ifndef SALES_H
#define SALES_H

const int QUARTER=4; //Four Quarters and 4 Divisions

struct SaleDat{
    unsigned int divName; //Division name
    float sales[QUARTER];       //Quarterly Sales
    float totSale;        //Total Sales
    float aveSale;        //Average Quarterly Sales
};

#endif /* SALES_H */

