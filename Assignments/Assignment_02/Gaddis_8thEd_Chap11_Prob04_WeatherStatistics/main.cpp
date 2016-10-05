/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 4, 2016, 3:00 PM
 * Purpose: Stores weather data for 12 months and displays them
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "weather.h"
//Global Constants

//Function Prototypes
void getWther(Weather[],int);
void display(Weather[],int,float,float,float,float,float,int,int);
void getStat(Weather[],float&,float&,int&,int&,int,float&,float&,float&);
void month(int);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int MONTHS=12;
    Weather data[MONTHS];
    float high,low;    //Temp high and Temp low
    int hMonth,lMonth;   //Temp high month and Temp low Month
    float totRain,aveRain,aveTemp;
    //Input Data
    getWther(data,MONTHS);
    //Process Data
    getStat(data,high,low,hMonth,lMonth,MONTHS,totRain,aveRain,aveTemp);
    //Output Data
    display(data,MONTHS,totRain,aveRain,aveTemp,high,low,hMonth,lMonth);
    
    return 0;
}

void getWther(Weather a[],int n){
    bool flag;
    //Input Data
    for(int i=0;i<n;i++){
        do{
            flag=true;
            cout<<"Input the total rainfall for ";
                month(i);
                cout<<"in inches: ";
            cin>>a[i].rain;
            if(a[i].rain<0){
                cout<<"Rainfall must be positive!"<<endl;
                flag=false;
            }
        }while(!flag);
        do{
            flag=true;
            cout<<"Input the high temp for ";
                month(i);
                cout<<"in F°: ";
            cin>>a[i].high;
            if(a[i].high<-100||a[i].high>140){
                cout<<"Temperature must be within -100F° and 140F°!"<<endl;
                flag=false;
            }
        }while(!flag);
        do{
            flag=true;
            cout<<"Input the low temp for ";
                month(i);
                cout<<"in F°: ";
            cin>>a[i].low;
            if(a[i].low<-100||a[i].low>140){
                cout<<"Temperature must be within -100F° and 140F°!"<<endl;
                flag=false;
            }
        }while(!flag);
        a[i].ave=(a[i].high+a[i].low)/2;
    }
}

void getStat(Weather a[],float &high,float &low,int &hMonth,int &lMonth,int n,
        float &totRain,float &aveRain,float &aveTemp){
    //Variables
    totRain=a[0].rain;
    aveTemp=a[0].ave;
    high=(a[0].high);
    hMonth=0;
    low=(a[0].low);
    lMonth=0;
    //Process Data
    for(int i=1;i<n;i++){
        if((a[i].high)>high){
            high=(a[i].high);
            hMonth=i;
        }
        if((a[i].low)<low){
            low=(a[i].low);
            lMonth=i;
        }
        totRain+=a[i].rain;
        aveTemp+=a[i].ave;
    }
    aveTemp/=n;
    aveRain=totRain/n;
}

void display(Weather a[],int n,float tR,float aR,float aT,float h,float l,
        int hM, int lM){
    //Output Data
    cout<<" Ave. rain: "<<fixed<<showpoint<<setprecision(2)<<aR
        <<"\""<<endl;
    cout<<"Total Rain: "<<fixed<<showpoint<<setprecision(2)<<tR<<"\""<<endl;
    cout<<"      High: "<<h<<" F° in month ";
    month(hM);
    cout<<endl<<"       Low: "<<l<<" F° in month ";
    month(lM);
    cout<<endl<<"  Ave temp: "<<aT<<" F°"<<endl;
}

void month(int n){
    //Output Data
    switch (n){
        case 0:cout<<"Jan ";break;
        case 1:cout<<"Feb ";break;
        case 2:cout<<"Mar ";break;
        case 3:cout<<"Apr ";break;
        case 4:cout<<"May ";break;
        case 5:cout<<"Jun ";break;
        case 6:cout<<"Jul ";break;
        case 7:cout<<"Aug ";break;
        case 8:cout<<"Sep ";break;
        case 9:cout<<"Oct ";break;
        case 10:cout<<"Nov ";break;
        default:cout<<"Dec ";break;
    }
}