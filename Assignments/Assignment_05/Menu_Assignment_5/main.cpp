/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on December 5, 2016, 4:00 pm
 * Purpose: Menu for assignment five
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Input/Output Manipulation
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "productionworker.h"
#include "shiftsupervisor.h"
#include "miltime.h"
#include "timeclock.h"
#include "essay.h"
#include "date.h"
#include "minmax.h"
#include "absval.h"
#include "total.h"
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
          " 1.   Gaddis_8thEd_Chap15_Prob01_Employee&ProductionWorker\n"
          " 2.   Gaddis_8thEd_Chap15_Prob02_ShiftSupervisor\n"
          " 3.   Gaddis_8thEd_Chap15_Prob04_TimeFormat\n"
          " 4.   Gaddis_8thEd_Chap15_Prob05_TimeClock\n"
          " 5.   Gaddis_8thEd_Chap15_Prob06_Essay\n"
          " 6.   Gaddis_8thEd_Chap16_Prob01_DateException\n"
          " 7.   Gaddis_8thEd_Chap16_Prob02_TimeFormatExceptions\n"
          " 8.   Gaddis_8thEd_Chap16_Prob03_MaxMinTemplate\n"
          " 9.   Gaddis_8thEd_Chap16_Prob04_AbsoluteValueTemplate\n"
          "10.   Gaddis_8thEd_Chap16_Prob05_TotalTemplate\n\n"
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
    
    //Variables
    ProductionWorker worker;
    string s;
    int shift,hours;
    float rate;
    //Input Data
    cout<<"Input workers name: ";
    getline(cin,s);
    worker.setName(s);
    cout<<"Input "<<worker.getName()<<"'s employee number: ";
    getline(cin,s);
    worker.setNum(s);
    cout<<"Input date "<<worker.getName()<<" was hired: ";
    getline(cin,s);
    worker.setHDat(s);
    cout<<"What shift does "<<worker.getName()<<" work?\n"
          "Input 1 for day shift\n"
          "Input 2 for night shift"<<endl;
    cin>>shift;
    cout<<"What is "<<worker.getName()<<"'s hourly rate in $?\n$";
    cin>>rate;
    cout<<"Input amount of whole hours "<<worker.getName()<<" worked: ";
    cin>>hours;
    //Process Data
    worker.setShift(shift);
    worker.setPayRate(rate);
    //Output Data
    cout<<worker.getName()<<endl<<"Employee number: "<<worker.getNum()<<endl;
    cout<<"Hired: "<<worker.getHDat()<<endl;
    cout<<worker.getShift()<<endl;
    cout<<"Salary for the week: $"<<showpoint<<fixed<<setprecision(2)
            <<worker.getPay(hours)<<endl;
    
    cout<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    //Variables
    ShiftSupervisor worker;
    string s;
    int n;
    float salary,rate;
    //Input Data
    cout<<"Input shift supervisor's name: ";
    getline(cin,s);
    worker.setName(s);
    cout<<"Input "<<worker.getName()<<"'s employee number: ";
    getline(cin,s);
    worker.setNum(s);
    cout<<"What is "<<worker.getName()<<"'s yearly salary?\n$";
    cin>>salary;
    cout<<"What is "<<worker.getName()<<"'s bonus rate?\n$";
    cin>>rate;
    cout<<"How many bonuses did "<<worker.getName()<<" earn this year? ";
    cin>>n;
    //Process Data
    worker.setBRate(rate);
    worker.setSalary(salary);
    worker.setNBonus(n);
    //Output Data
    cout<<worker.getName()<<endl<<"Employee number: "<<worker.getNum()<<endl;
    cout<<"Salary for the year(bonuses included): $"<<showpoint<<fixed
            <<setprecision(2)<<worker.getSalary()<<endl;
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    //Variables
    int hours,sec;
    MilTime time;
    //Input Data
    cout<<"Input military hours: ";
    cin>>hours;
    cout<<"Input seconds: ";
    cin>>sec;
    //Process Data
    time.setTime(hours,sec);
    //Output Data
    cout<<setw(4)<<setfill('0')<<time.getMilH()
            <<" mil. hours and "<<time.getMilS()<<" mil. seconds\n";
    cout<<"Standard time: "<<endl;
    cout<<"Hour: ";{
        if(time.getHour()==0){
            cout<<"12 am"<<endl;
        }else if(time.getHour()==12){
            cout<<"12 pm"<<endl;
        }else if(time.getHour()<12){
            cout<<time.getHour()<<" am"<<endl;
        }else{
            cout<<time.getHour()-12<<" pm"<<endl;
        }
    }
    cout<<"Min: "<<time.getMin()<<endl;
    cout<<"Sec: "<<time.getSec()<<endl;
    
    cout<<endl<<endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
    //Variables
    TimeClock a;
    int n;
    //Input Data
    cout<<"This program shows the elapsed time between two times"<<endl;
    cout<<"Input the starting time in military time(ex.0700)"<<endl;
    cin>>n;
    a.setTime1(n);
    cout<<"Input the ending time in military time(ex.0700)"<<endl;
    cin>>n;
    a.setTime2(n);
    //Process Data
    
    //Output Data
    cout<<"Elapsed time: ";
    a.getElpsTime();
    
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    //Variables
    int grammar,spelling,length,content;
    //Input Data
    cout<<"This program gets the letter grade of a graded essay"<<endl;
    cout<<"Input grammar points(1-30): ";
    cin>>grammar;
    cout<<"Input spelling points(1-20): ";
    cin>>spelling;
    cout<<"Input length points(1-20): ";
    cin>>length;
    cout<<"Input content points(1-30): ";
    cin>>content;
    
    //Process Data
    Essay paper(grammar,spelling,length,content);
    
    //Output Data
    cout<<"The letter grade for the paper is "<<paper.getLetterGrade()<<endl;
    
    cout<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    //Variables
    Date date;
    int year,day,month;
    
    //Input Data
    cout<<"Input the year: ";
    cin>>year;
    cout<<"Input the month: ";
    cin>>month;
    cout<<"Input the day: ";
    cin>>day;
    
    //Process Data
    try{
        date.setYear(year);
        date.setMnth(month);
        date.setDay(day,date.getMnth());

        //Output Data
        date.print();
    }
    catch(Date::InvalidDay){
        cout<<"Caught an InvalidDay"<<endl;
    }
    catch(Date::InvalidMonth){
        cout<<"Caught an InvalidMonth"<<endl;
    }
    
    cout<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    
    //Variables
    int hours,sec;
    MilTime time;
    //Input Data
    cout<<"Input military hours: ";
    cin>>hours;
    cout<<"Input seconds: ";
    cin>>sec;
    //Process Data
    try{
        time.setTime(hours,sec);
        //Output Data
        cout<<setw(4)<<setfill('0')<<time.getMilH()
                <<" mil. hours and "<<time.getMilS()<<" mil. seconds\n";
        cout<<"Standard time: "<<endl;
        cout<<"Hour: ";{
            if(time.getHour()==0){
                cout<<"12 am"<<endl;
            }else if(time.getHour()==12){
                cout<<"12 pm"<<endl;
            }else if(time.getHour()<12){
                cout<<time.getHour()<<" am"<<endl;
            }else{
                cout<<time.getHour()-12<<" pm"<<endl;
            }
        }
        cout<<"Min: "<<time.getMin()<<endl;
        cout<<"Sec: "<<time.getSec()<<endl;
    }
    catch(MilTime::BadHour){
        cout<<"Caught BadHour"<<endl;
    }
    catch(MilTime::BadMinute){
        cout<<"Caught BadMinute"<<endl;
    }
    catch(MilTime::BadSec){
        cout<<"Caught BadSec"<<endl;
    }
    
    cout<<endl<<endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    
    //Variables
    int   a=1,b=3;
    float c=3.5,d=5.5;
    //Input Data

    //Process Data
    
    //Output Data
    cout<<"int a="<<a<<" int b="<<b<<endl;
    cout<<"minimum = "<<minimum(a,b)<<endl;
    cout<<"maximum = "<<maximum(a,b)<<endl;
    
    cout<<"float c="<<c<<" float d="<<d<<endl;
    cout<<"minimum = "<<minimum(c,d)<<endl;
    cout<<"maximum = "<<maximum(c,d)<<endl;
    
    cout<<endl<<endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    
    //Variables
    int    a=-5;
    short  b=-3;
    float  c=-7.5;
    double d=-9.6;
    
    //Input Data

    //Process Data
    
    //Output Data
    cout<<"int a = "<<a<<endl<<"Abs value of a = "<<absVal(a)<<endl<<endl;
    cout<<"short b = "<<b<<endl<<"Abs value of b = "<<absVal(b)<<endl<<endl;
    cout<<"float c = "<<c<<endl<<"Abs value of c = "<<absVal(c)<<endl<<endl;
    cout<<"double d = "<<d<<endl<<"Abs value of d = "<<absVal(d)<<endl<<endl;
    
    cout<<endl<<endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    
    //Variables
    int size;
    int   a;
    short b;
    float c;
    
    //Input Data
    cout<<"Input amount of ints you want to add: ";
    cin>>size;
    a=total<int>(size);
    cout<<"Input amount of shorts you want to add: ";
    cin>>size;
    b=total<short>(size);
    cout<<"Input amount of floats you want to add: ";
    cin>>size;
    c=total<float>(size);
    //Process Data
    
    //Output Data
    cout<<"int a total = "<<a<<endl;
    cout<<"short b total = "<<b<<endl;
    cout<<"float c total = "<<c<<endl;
    
    cout<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}