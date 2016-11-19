/* File:   inventory.h
 * Author: Javier B
 *
 * Created on November 18, 2016, 11:12 AM
 * Purpose: Inventory item class implementation file
 */

#include "inventory.h"

Inventory::Inventory(){
    itemNum=0;
    quantity=0;
    cost=0.0;
    totCost=0.0;
}

void Inventory::setItemNum(int n){
    if(n<0){
        cout<<"Can't have a negative value for Item Number"<<endl;
        exit(1);
    }
    itemNum=n;
}

void Inventory::setQuant(int n){
    if(n<0){
        cout<<"Can't have a negative value for Quantity"<<endl;
        exit(1);
    }
    quantity=n;
}

void Inventory::setCost(float cost){
    if(cost<0){
        cout<<"Can't have a negative value for Cost"<<endl;
        exit(1);
    }
    this->cost=cost;
}

void Inventory::setTotCost(){
    totCost=cost*quantity;
}