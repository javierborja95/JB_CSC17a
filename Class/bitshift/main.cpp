/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November , 2016,  PM
 * Purpose:
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <cmath>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants
float PI=atan(1)*4.0;
//Function Prototypes

//Execution

int main(int argc, char** argv) {
    //Variables
    float drag,density=.00237,velocity=100.0,diameter=0.5,coeffic=0.5,
          area=(diameter/2)*(diameter/2)*PI;
    
    //Process Data
    drag=1/2.0f*density*velocity*velocity*area*coeffic;
    
    //Output Data
    cout<<drag<<endl;
    
    return 0;
}