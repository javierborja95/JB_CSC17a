/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 2, 2016, 9:30 PM
 * Purpose: User submits movie data and program displays all the movie info
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>    //String library
#include <iomanip>   //Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "moviedataV2.h"
//Global Constants

//Function Prototypes
MovieData *getData(int);
void display(const MovieData*,int);

//Execution

int main(int argc, char** argv) {
    //Variables
    MovieData *array; //Array of movie data
    int size;         //Size of array
    //Input Data
    cout<<"How many movies do you want to store?"<<endl;
    cin>>size;
    
    //Process Data
    array=getData(size);
    //Output Data
    display(array,size);
    
    //Deallocate Memory
    delete[] array;
    
    return 0;
}

MovieData *getData(int n){
    //Allocate Memory
    MovieData *a=new MovieData[n];
    //Input Data
    for(int i=0;i<n;i++){
        cin.ignore();
        cout<<"Input Title of Movie #"<<i+1<<":\n";
        getline(cin, a[i].title);
        cout<<"Input Director of Movie:\n";
        getline(cin, a[i].director);
        cout<<"Input the Year Released: ";
        cin>>a[i].year;
        cout<<"Input the Running Time in Minutes: ";
        cin>>a[i].runTime;
        cout<<"Input the profit or loss in dollars: ";
        cin>>a[i].profit;
    }
    cout<<endl;
    //Output Data
    return a;
}

void display(const MovieData *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<"Title: "<<a[i].title<<endl;
        cout<<"Director: "<<a[i].director<<endl;
        cout<<"Year Released: "<<a[i].year<<endl;
        cout<<"Running Time: "<<a[i].runTime<<" mins"<<endl;
        cout<<"Profit/Loss: $"<<fixed<<showpoint<<setprecision(2)<<a[i].profit
                <<endl<<endl;
    }
}