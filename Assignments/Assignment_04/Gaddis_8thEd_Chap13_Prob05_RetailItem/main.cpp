/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 7, 2016, 8:30 PM
 * Purpose: Holds info for products. Displays products' info.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <memory>    //Unique pointers
#include <iomanip>
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "retailitem.h"
//Global Constants

//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    int size;
    string info;
    int units;
    float price;
    //Get array of products
    cout<<"How many items are in your store?: ";
    cin>>size;
    cin.ignore();
    unique_ptr<RetailItem[]> arr(new RetailItem[size]);
    //Input Data
    for(int i=0;i<size;i++){
        cout<<"Item #"<<i+1<<"'s description: ";
        getline(cin,info);
        cout<<"Input number of products at hand: ";
        cin>>units;
        cout<<"Input price of product: $";
        cin>>price;
        cin.ignore();
    //Process Data
        arr[i].setInfo(info);
        arr[i].setUnit(units);
        arr[i].setPrice(price);
    }
    //Output Data
    cout<<"         Description            #units Price"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Item #"<<setw(3)<<left<<i+1<<setw(25)<<left<<arr[i].getInfo()
                <<setw(4)<<left<<arr[i].getUnit()<<"$"<<showpoint<<fixed
                <<setprecision(2)<<arr[i].getPrice()<<endl;
    }
    return 0;
}