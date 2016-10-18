/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 17, 2016, 6:00 PM
 * Purpose: Stores sales data of companies division
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
#include <cstdlib>   //Random Library
#include <ctime>     //Time Library
#include <fstream>
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "sales.h"
//Global Constants

//Function Prototypes
void getSales(SaleDat*,int);
void display(const SaleDat*,int);
void write(const SaleDat*,int);
//Execution

int main(int argc, char** argv) {
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    SaleDat array[QUARTER];      //Array of Sales Data structure
    
    //Input Data
    getSales(array,QUARTER);
    
    //Process Data
    
    //Output Data
    display(array,QUARTER);
    write(array,QUARTER);
    
    return 0;
}

void getSales(SaleDat *a,int n){
    //Variables
    float temp; //Temporary variable
    //Input Data
    for(unsigned int i=0;i<n;i++){
        a[i].divName=i;
        for(int j=0;j<n;j++){
            a[i].sales[j]=(rand()%100)*100;
        }
        for(int j=0;j<n;j++){
            //Temp variable
            if(j==0)temp=0; //So temp does not reset each loop
            temp+=a[i].sales[j];
            if(j==(n-1))a[i].totSale=temp;
        }
            a[i].aveSale=a[i].totSale;
            a[i].aveSale/=4;
    }
}

void display(const SaleDat *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<"Division: ";
        switch (a[i].divName){
            case  0:cout<<"East\n";break;
            case  1:cout<<"West\n";break;
            case  2:cout<<"North\n";break;
            default:cout<<"South\n";break;
        }
        for(int j=0;j<n;j++){
            switch (i){
                case  0:cout<<"First ";break;
                case  1:cout<<"Second ";break;
                case  2:cout<<"Third ";break;
                default:cout<<"Fourth ";break;
            }
            cout<<"Quarter Sales: $";
            cout<<fixed<<showpoint<<setprecision(2)<<a[i].sales[j]<<endl;
        }
        cout<<"Total Annual Sales: $";
        cout<<fixed<<showpoint<<setprecision(2)<<a[i].totSale<<endl;
        cout<<"Average Quarterly Sales: $";
        cout<<fixed<<showpoint<<setprecision(2)<<a[i].aveSale<<endl<<endl;
    }
}

void write(const SaleDat *a,int n){
    //Variables
    fstream out;
    //Open files
    out.open("sales.dat",ios::out);
    //Output Data to file
    for(int i=0;i<n;i++){
        out<<"Division: ";
        switch (a[i].divName){
            case  0:out<<"East\n";break;
            case  1:out<<"West\n";break;
            case  2:out<<"North\n";break;
            default:out<<"South\n";break;
        }
        for(int j=0;j<n;j++){
            switch (i){
                case  0:out<<"First ";break;
                case  1:out<<"Second ";break;
                case  2:out<<"Third ";break;
                default:out<<"Fourth ";break;
            }
            out<<"Quarter Sales: $";
            out<<fixed<<showpoint<<setprecision(2)<<a[i].sales[j]<<endl;
        }
        out<<"Total Annual Sales: $";
        out<<fixed<<showpoint<<setprecision(2)<<a[i].totSale<<endl;
        out<<"Average Quarterly Sales: $";
        out<<fixed<<showpoint<<setprecision(2)<<a[i].aveSale<<endl<<endl;
    }
    //Close files
    out.close();
    cout<<"Results written to sales.dat"<<endl;
}