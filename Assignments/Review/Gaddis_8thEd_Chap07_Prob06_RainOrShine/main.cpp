/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 13, 2016, 1:30 PM
 * Purpose: Displays how many days were a particular weather
 */

//System Libraries
#include <iostream>   //Input/ Output Stream Library
#include <fstream>    //File I/O
#include <cstdlib>    //Random
#include <ctime>      //Time
using namespace std;  //Namespace of the System Libraries

//User Libraries

//Global Constants
const int DAY=30; //Number of days in month
//Function Prototypes
void writAry(int);
void inAry(char[][DAY],int);
char getWthr();
void display(char[][DAY],int[],int);
//Execution

int main(int argc, char** argv) {
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables
    const int MONTH=3; //Months: June, July, August
    char weather[MONTH][DAY];
    int count[MONTH]={0,0,0};
    //Input Data
    writAry(MONTH);
    inAry(weather,MONTH);
    //Process Data
    
    //Output Data
    display(weather,count,MONTH);
    return 0;
}

void writAry(int n){
    //Variables
    ofstream write;
    char temp;
    //Open Files
    write.open("weather.dat");
    //Process Data and Output Data
    for(int i=0;i<n;i++){
        for(int j=0;j<DAY;j++){
            temp=getWthr();
            write<<temp<<" ";
        }
        write<<"\r";
    }
    write.close();
}

char getWthr(){
    //Variables
    const int OPTION=3;
    char weather[OPTION]={'R','C','S'}; //Rainy, cloudy, sunny
    //Output Data
    return(weather[rand()%3]); //0,1,2
}

void inAry(char a[][DAY],int n){
    //Variables
    ifstream read;
    //Open Files and Input Data
    read.open("weather.dat");
    for(int i=0;i<n;i++){
        for(int j=0;j<DAY;j++){
            read>>a[i][j];
        }
    }
    read.close();
}

void display(char a[][DAY],int b[],int n){
    //Output Data
    for(int i=0;i<n;i++){
        switch(i){
            case 0:cout <<"June ";break;
            case 1:cout <<"July ";break;
            default:cout<<" Aug ";break;
        }
        for(int j=0;j<DAY;j++){
            cout<<a[i][j]<<" ";
            if(a[i][j]=='R')      //Rainy
                b[0]++;
            else if(a[i][j]=='C') //Cloudy
                b[1]++;
            else b[2]++;          //'S' sunny
        }
        cout<<endl;
    }
    cout<<b[0]<<" days were rainy."<<endl;
    cout<<b[1]<<" days were cloudy."<<endl;
    cout<<b[2]<<" days were sunny."<<endl;
}