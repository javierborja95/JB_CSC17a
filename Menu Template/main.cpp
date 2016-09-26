/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 25, 2016, 11:30 AM
 * Purpose: Menu for assignment one
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
//Execution

int main(int argc, char** argv) {
    //Variables
    int inN;
    //Input Data
    do{
         Menu();
         inN=getN();
    //Process Data
         switch(inN){
            case 1:  problem1();break;
            case 2:  problem2();break;
            case 3:  problem3();break;
            case 4:  problem4();break;
            case 5:  problem5();break;
            case 6:  problem6();break;
            case 7:  problem7();break;
            case 8:  problem8();break;
            case 9:  problem9();break;
            case 10: problem10();break;
            default: def(inN);
         }
        }while(inN>0&&inN<11);
        
    //Output Data

    return 0;
}

void Menu(){
    //Output Data
    cout<<"Please input the problem you wish to view.\n";
    cout<<"The possible options are:\n"
          " 1.   Problem  1\n"
          " 2.   Problem  2\n"
          " 3.   Problem  3\n"
          " 4.   Problem  4\n"
          " 5.   Problem  5\n"
          " 6.   Problem  6\n"
          " 7.   Problem  7\n"
          " 8.   Problem  8\n"
          " 9.   Problem  9\n"
          "10.   Problem 10\n\n"
          " 0.   Exit\n";
}

int getN(){
    //Variables
    int inN;
    //Input Data
    cin>>inN;
    cin.ignore();
    //Return Data
    return inN;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    
    cout<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}