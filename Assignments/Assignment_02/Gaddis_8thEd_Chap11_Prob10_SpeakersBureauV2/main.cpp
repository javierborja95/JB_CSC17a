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
#include "speakers.h"
//Global Constants

//Function Prototypes
void input(Speaker*,int);
void change(Speaker*);
void find(Speaker*,int);
void display(Speaker*,int);
//Execution

int main(int argc, char** argv) {
    //Variables
    const int SIZE=10;
    Speaker *data=new Speaker[SIZE];
    char choice;
    
    //Input Data
    do{
        cout<<"\nPress 1 to enter data in the array\n"
            <<"Press 2 to change elements in array\n"
            <<"Press 3 to find a topic\n"
            <<"Press 4 to view all speakers\n"
            <<"Press 5 to exit\n";
        cin>>choice;
        if(choice=='1')
            input(data,SIZE);
        else if(choice=='2')
            change(data);
        else if(choice=='3')
            find(data,SIZE);
        else if(choice=='4')
            display(data,SIZE);
        else cout<<"You chose to exit"<<endl;
    }while(choice=='1'||choice=='2'||choice=='3'||choice=='4');
    //Process Data
    
    //Output Data

    delete[] data;
    return 0;
}

void input(Speaker *a,int n){
    //Variables
    int choice;
    //Input Data
    cout<<"Which speaker's data would you like to input?\n"
        <<"Input 0 to input all\n"
        <<"Input 1-10 to input single person\n"
        <<"Input -1 to leave\n";
    cin>>choice;
    if(choice<0||choice>10){
        cout<<"You chose to exit"<<endl;
        return;
    }
    if(choice=='0'){
        cout<<"You chose to change all"<<endl;
        for(int i=0;i<n;i++){
            a[i].empty=false;
            cout<<"Input name for speaker #"<<i+1<<": ";
            cin.ignore();
            getline(cin,a[i].name);
            cout<<"Input "<<a[i].name<<"'s telephone number: ";
            cin.ignore();
            getline(cin,a[i].phone);
            cout<<"Input "<<a[i].name<<"'s speaking topic: ";
            cin.ignore();
            getline(cin,a[i].topic);
            do{
                cout<<"Input "<<a[i].name<<"'s fee in $: ";
                cin>>a[i].fee;
                if(&(a[i].fee)<0)
                    cout<<"Must be positive"<<endl;
            }while(&(a[i].fee)<0);
        }
    }else{
        cout<<"You chose to change #"<<choice<<endl;
        int i=choice-1;
        a[i].empty=false;
        cout<<"Input name for speaker #"<<i+1<<": ";
        cin.ignore();
        getline(cin,a[i].name);
        cout<<"Input "<<a[i].name<<"'s telephone number: ";
        getline(cin,a[i].phone);
        cout<<"Input "<<a[i].name<<"'s speaking topic: ";
        getline(cin,a[i].topic);
        do{
            cout<<"Input "<<a[i].name<<"'s fee in $: ";
            cin>>a[i].fee;
            if(&(a[i].fee)<0)
                cout<<"Must be positive"<<endl;
        }while(&(a[i].fee)<0);
    }
}

void change(Speaker *a){
    //Variables
    int choice;
    int temp;
    //Input Data
    cout<<"Which speaker's data would you like to change?\n"
        <<"Input 1-10 to change\n"
        <<"Input -1 to leave\n";
    cin>>choice;
    if(choice<0||choice>10){
        cout<<"You chose to exit"<<endl;
        return;
    }
    cout<<"You chose to change speaker #"<<choice<<endl;
    choice-=1;
    if(a[choice].empty==true){
        cout<<"You must enter data for this person before you can change elements"
            <<endl;
        return;
    }
    cout<<a[choice].name<<endl;
    cout<<"Phone: "<<a[choice].phone<<endl;
    cout<<"Topic: "<<a[choice].topic<<endl;
    cout<<"Fee: $"<<showpoint<<fixed<<setprecision(2)<<a[choice].fee<<endl;
    do{
        cout<<"Input 1 to change name\n"
            <<"Input 2 to change phone\n"
            <<"Input 3 to change topic\n"
            <<"Input 4 to change fee\n"
            <<"Input 0 to exit\n"<<endl;
        cin>>temp;
        switch(temp){
            case 1:{
                cout<<"Input name for speaker #"<<choice+1<<": ";
                cin.ignore();
                getline(cin,a[choice].name);
                break;
            }
            case 2:{
                cout<<"Input phone for "<<a[choice].name<<": ";
                cin.ignore();
                getline(cin,a[choice].phone);
                break;
            }
            case 3:{
                cout<<"Input topic for "<<a[choice].name<<": ";
                cin.ignore();
                getline(cin,a[choice].topic);
                break;
            }
            case 4:{
                cout<<"Input fee for "<<a[choice].name<<" in $: ";
                cin>>a[choice].fee;
                break;
            }
            default:{
                cout<<"You chose to exit"<<endl;
                break;
            }
        }
    }while(temp>0&&temp<5);
}

void find(Speaker *a,int n){
    //Variables
    string input;
    bool found=false;
    //Input Data
    cout<<"Type in part of topic to search for (case sensitive):"<<endl;
    cin.ignore();
    getline(cin,input);
    //Output data
    for(int i=0;i<n;i++){
        if((a[i].topic).find(input)!=string::npos){
            found=true;
            cout<<"Found speaker #"<<i+1<<endl;
            cout<<"Speaker #"<<i+1<<endl;
            cout<<a[i].name<<endl;
            cout<<"Phone: "<<a[i].phone<<endl;
            cout<<"Topic: "<<a[i].topic<<endl;
            cout<<"Fee: $"<<showpoint<<fixed<<setprecision(2)<<a[i].fee<<endl;
            cout<<endl;
        }
    }
    if(found==false){
        cout<<input<<" not found as a topic."<<endl;
    }
}

void display(Speaker *a,int n){
    //Display Data
    cout<<endl;
    for(int i=0;i<n;i++){
        if(a[i].empty==false){
            cout<<"Speaker #"<<i+1<<endl;
            cout<<a[i].name<<endl;
            cout<<"Phone: "<<a[i].phone<<endl;
            cout<<"Topic: "<<a[i].topic<<endl;
            cout<<"Fee: $"<<showpoint<<fixed<<setprecision(2)<<a[i].fee<<endl;
            cout<<endl;
        }
    }
}