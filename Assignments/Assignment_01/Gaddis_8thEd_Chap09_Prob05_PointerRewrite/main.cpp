/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 2, 2016, 7:50 PM
 * Purpose: Rewrite a function so that it uses pointers instead of reference 
 * variables.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
//int doSomething(int &x, int &y) //Old Code
int doSomething(int*, int*); //New Code
//Execution

int main(int argc, char** argv) {
    //Variables
    int x=1,y=2,z;
    int *p1=&x;
    int *p2=&y;
    //Output Data
    cout<<"p1 points to value "<<*p1<<endl;
    cout<<"p2 points to value "<<*p2<<endl;
    //Process Data
    z=doSomething(p1,p2);
    //Output Data
    cout<<"p1 now points to value "<<*p1<<endl;
    cout<<"p2 now points to value "<<*p2<<endl;
    cout<<"The sum of pointed values is "<<z<<endl;

    return 0;
}

 /*int doSomething(int &x, int &y){ //Old Code
     int temp = x;
     x = y * 10;
     y = temp * 10;
     return x + y;
 }*/

int doSomething(int *x, int *y){ //New Code
    //Variables
    int temp=*x;  //temp=1
    //Process Data
     *x=*y*10;    //*x=2*10
     *y=temp*10;  //*y=1*10
     //Output Data
     return *x+*y;//30
}