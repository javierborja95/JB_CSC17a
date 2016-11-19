/* File:   inventory.h
 * Author: Javier B
 *
 * Created on November 18, 2016, 11:12 AM
 * Purpose: Inventory item class specification file
 */

#ifndef INVENTORY_H
#define INVENTORY_H

//System Libraries
#include <cstdlib>  //Exit function
#include <iostream> //Input/ Output Stream Library
using namespace std;

class Inventory{
    private: 
        int itemNum;
        int quantity;
        float cost;
        float totCost;
    public:
        Inventory();
        void setItemNum(int);
        void setQuant(int);
        void setCost(float);
        void setTotCost();
        int getItemNum(){return itemNum;}
        int getQuant(){return quantity;}
        float getCost(){return cost;}
        float getTotCost(){return totCost;}
};

#endif /* INVENTORY_H */

