/* File:   retailitem.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 8:38 PM
 * Purpose: Retail item class specification file
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

//System Libraries
#include <string>
#include <iostream>
using namespace std;

class RetailItem{
    private:
        string info;
        int units;
        float price;
    public:
        Item(int n);
        void setInfo(string);
        void setUnit(int);
        void setPrice(float);
        string getInfo(){return info;}
        int getUnit(){return units;}
        float getPrice(){return price;}
};

#endif /* RETAILITEM_H */

