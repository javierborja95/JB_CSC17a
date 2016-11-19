/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 11:00 AM
 * Purpose: Holds information of a retail store's inventory
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "inventory.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int itemNum, quant; //Item number, quantity of items
    float cost;         //Cost of item in $
    Inventory *arr;     //Array of items
    int n;              //Number of elements in array
    //Input Data
    cout<<"This program holds information on a store's inventory.\n"
          "How many items do you have?\n"
          "Items: ";
    cin>>n;
    if(n<=0){
        cout<<"You need at least one element"<<endl;
        return 0;
    }
    //Allocate Memory
    arr=new Inventory[n];
    for(int i=0;i<n;i++){
        cout<<"Input item #"<<i+1<<"'s Item Number: ";
        cin>>itemNum;
        cout<<"Input quantity of items on hand: ";
        cin>>quant;
        cout<<"Input the per-unit cost of the item: $";
        cin>>cost;
    //Process Data
        arr[i].setItemNum(itemNum);
        arr[i].setQuant(quant);
        arr[i].setCost(cost);
        arr[i].setTotCost();
    }
    //Output Data
    cout<<"ItemNum   quantity  cost      totCost"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(13)<<left<<arr[i].getItemNum()<<setw(5)<<left
            <<arr[i].getQuant()<<"$"<<setw(10)<<fixed<<showpoint
            <<setprecision(2)<<arr[i].getCost()<<"$"<<fixed
            <<showpoint<<setprecision(2)<<arr[i].getTotCost()<<endl;
    }
    //Deallocate Memory
    delete[] arr;

    return 0;
}