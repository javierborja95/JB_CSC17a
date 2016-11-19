/* 
 * File:   car.h
 * Author: Javier B
 *
 * Created on November 7, 2016, 6:38 PM
 * Purpose: Car class specification file
 */

#ifndef CAR_H
#define CAR_H

//System Libraries
#include <iostream>
using namespace std;

class Car{
    private:
        int model;
        std::string make;
        int speed;
    public:
        void setCar(int model,string make){
            this->model=model; this->make=make;
            speed=0;
        }
        int getModel(){return model;}
        std::string getMake(){return make;}
        void showSpeed(){
            cout<<speed<<" mph"<<endl;
        }
        void accel(){
            cout<<"Accelerating..."<<endl;
            speed+=5;
        }
        void brake(){
            cout<<"Braking..."<<endl;
            speed-=5;
        }
};

#endif /* CAR_H */

