/* File:   retailitem.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 8:38 PM
 * Purpose: Retail item class specification file
 */

#include "retailitem.h"
//System Libraries
#include <cstdlib>

RetailItem::Item(int n){
    info={""};
    units=0;
    price=0.0;
}

void RetailItem::setInfo(string info){
    this->info=info;
}

void RetailItem::setUnit(int n){
    if(n<0){
        cout<<"Must have at least one product"<<endl;
        exit(1);
    }
    units=n;
}

void RetailItem::setPrice(float price){
    if(price<=0){
        cout<<"Price must be greater than $0.00"<<endl;
        exit(1);
    }
    this->price=price;
}