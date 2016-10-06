/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 5, 2016, 7:30 PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>
#include <string>

using namespace std; //Namespace of the System Libraries

//User Libraries
#include "customer.h"
//Global Constants

//Function Prototypes
void change(Customer*);
void display(Customer*);
void find(Customer*,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=10;
    Customer *data=new Customer[SIZE];
    char choice;
    
    //Input Data
    do{
        cout<<"Press 1 to enter data in the array\n"
            <<"Press 2 to view data in array\n"
            <<"Press 3 to search for a name\n"
            <<"Press 4 to exit"<<endl;
        cin>>choice;
        if(choice=='1')
            change(data);
        else if(choice=='2')
            display(data);
        else if(choice=='3')
            find(data,SIZE);
    }while(choice=='1'||choice=='2'||choice=='3');
    //Process Data
    
    //Output Data

    delete[] data;
    return 0;
}

void change(Customer *a){
    //Variables
    int choice;
    //Input Data
    cout<<"Which customer's data would you like to change?\n"
        <<"Input 1-10(input 0 to exit)";
    cin>>choice;
    if(choice<1||choice>10){
        cout<<"You chose to exit"<<endl;
        return;
    }
    cout<<"You chose "<<choice<<endl;
    choice-=1;
    cout<<"Input name: ";
    cin.ignore();
    getline(cin,a[choice].name);
    cout<<"Input "<<a[choice].name<<"'s Address: ";
    cin.ignore();
    getline(cin,a[choice].address);
    cout<<"Input "<<a[choice].name<<"'s City,State, and ZIP: ";
    cin.ignore();
    getline(cin,a[choice].zip);
    cout<<"Input "<<a[choice].name<<"'s telephone number: ";
    cin.ignore();
    getline(cin,a[choice].phone);
    cout<<"Input "<<a[choice].name<<"'s Account balance in $: ";
    cin>>a[choice].balance;
    cout<<"Input "<<a[choice].name<<"'s date of last payment: ";
    cin.ignore();
    getline(cin,a[choice].date);
    cout<<endl;
}

void display(Customer *a){
    //Variables
    int choice;
    //Input Data
    cout<<"Which customer's data would you like to view?\n"
        <<"Input 1-10(input 0 to exit)";
    cin>>choice;
    if(choice<1||choice>10){
        cout<<"You chose to exit"<<endl;
        return;
    }
    cout<<"You chose "<<choice<<endl;
    choice-=1;
    cout<<a[choice].name<<endl;
    cout<<a[choice].address<<endl;
    cout<<a[choice].zip<<endl;
    cout<<a[choice].phone<<endl;
    cout<<"Account balance: $"<<fixed<<showpoint<<setprecision(2)
            <<a[choice].balance<<endl;
    cout<<"Date of last payment: "<<a[choice].date<<endl<<endl;
}

void find(Customer *a,int n){
    //Variables
    string input;
    bool found=false;
    //Input Data
    cout<<"Type in part of name to search for (case sensitive):"<<endl;
    cin.ignore();
    getline(cin,input);
    //Output data
    for(int i=0;i<n;i++){
        if((a[i].name).find(input)!=string::npos){
            found=true;
            cout<<"Found customer #"<<i+1<<endl;
            cout<<a[i].name<<endl;
            cout<<a[i].address<<endl;
            cout<<a[i].zip<<endl;
            cout<<a[i].phone<<endl;
            cout<<"Account balance: $"<<fixed<<showpoint<<setprecision(2)
                    <<a[i].balance<<endl;
            cout<<"Date of last payment: "<<a[i].date<<endl<<endl;
        }
    }
    if(found==false){
        cout<<input<<" not found."<<endl;
    }
}