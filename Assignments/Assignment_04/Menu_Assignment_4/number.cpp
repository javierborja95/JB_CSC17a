/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 12:30 PM
 * Purpose: Number class Implementation file
 */

#include "number.h"

string Number::lessThan20[20]={"Zero ","One ","Two ","Three ","Four ","Five ",
    "Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ",
    "Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "
};

string Number::ten[10]={"Zero ","Ten ","Twenty ","Thirty ","Forty ","Fifty ",
    "Sixty ","Seventy ","Eighty ","Ninety "
};

string Number::hundred="Hundred ";

string Number::thousand="Thousand ";

void Number::print(){
    //Variables
    int temp=number,
        thousands,hundreds,tens;
    //Process Data
    if(number==0){
        cout<<"Zero"<<endl;
        return;
    }
    thousands=temp/1000;
    temp%=1000;
    if(thousands>0){
        cout<<lessThan20[thousands]<<thousand;
    }
    hundreds=temp/100;
    temp%=100;
    if(hundreds>0){
        cout<<lessThan20[hundreds]<<hundred;
    }
    tens=temp/10;
    if(tens>1){
        cout<<ten[tens];
        temp%=10;
    }
    if(temp<20&&temp>0){
        cout<<lessThan20[temp];
    }
    cout<<endl;
}