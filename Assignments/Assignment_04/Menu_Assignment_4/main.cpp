/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on November 18, 2016, 7:30 PM
 * Purpose: Menu for assignment four
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Input/ Output Manipulation
#include <memory>    //Unique pointers
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "date.h"
#include "car.h"
#include "info.h"
#include "retailitem.h"
#include "inventory.h"
#include "number.h"
#include "dayofyear.h"
#include "numdays.h"
#include "TimeOff.h"
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
          " 1.   Gaddis_8thEd_Chap13_Prob01_Date\n"
          " 2.   Gaddis_8thEd_Chap13_Prob03_Car\n"
          " 3.   Gaddis_8thEd_Chap13_Prob04_PersonalInfo\n"
          " 4.   Gaddis_8thEd_Chap13_Prob05_RetailItem\n"
          " 5.   Gaddis_8thEd_Chap13_Prob06_Inventory\n"
          " 6.   Gaddis_8thEd_Chap14_Prob01_Numbers\n"
          " 7.   Gaddis_8thEd_Chap14_Prob02_DayofYear_V1\n"
          " 8.   Gaddis_8thEd_Chap14_Prob03_DayofYear_V2\n"
          " 9.   Gaddis_8thEd_Chap14_Prob04_NumDays\n"
          "10.   Gaddis_8thEd_Chap14_Prob05_TimeOff\n\n"
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
    Date date;
    int year,day,month;
    
    //Input Data
    cout<<"Input the year: ";
    cin>>year;
    cout<<"Input the month(just the int,ex.2=feb): ";
    cin>>month;
    cout<<"Input the day: ";
    cin>>day;
    
    //Process Data
    date.setYear(year);
    date.setMnth(month);
    date.setDay(day,date.getMnth());
    
    //Output Data
    date.print();
    
    cout<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    //Variables
    Car car;
    int model;
    string make;
    //Input Data
    cout<<"Input the car's model year: ";
    cin>>model;
    cin.ignore();
    cout<<"Input the car's make: ";
    getline(cin,make);
    
    //Process Data
    car.setCar(model,make);
    
    //Output Data
    for(int i=0;i<5;i++){
        cout<<endl<<car.getModel()<<" "<<car.getMake()<<" is going ";
        car.showSpeed();
        car.accel();
    }
    for(int i=0;i<5;i++){
        cout<<endl<<car.getModel()<<" "<<car.getMake()<<" is going ";
        car.showSpeed();
        car.brake();
    }
    cout<<endl<<car.getModel()<<" "<<car.getMake()<<" is going ";
    car.showSpeed();
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    //Variables
    const int SIZE=3; //Size of array
    Info *arr=new Info[SIZE];
    string name,address;
    int age;
    char phone[10];
    //Input Data
    for(int i=0;i<SIZE;i++){
        if(i==0)cout<<"Your information: "<<endl;
        else if(i==1)cout<<"Your friend's information: "<<endl;
        else cout<<"Your family member's information: "<<endl;
        cout<<"Input name: ";
        getline(cin,name);
        cout<<"Input address: ";
        getline(cin,address);
        cout<<"Input age: ";
        cin>>age;
        cout<<"Input phone number (XXX)XXX-XXXX\n(just the integers): ";
        cin>>phone;
        cin.ignore();
    //Process Data
        arr[i].setInfo(name,address,age,phone);
    }
    //Output Data
    cout<<"Name            Address             Age   Phone"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<setw(16)<<left<<arr[i].getName()<<setw(20)<<left<<arr[i].getAdd()
                <<setw(6)<<arr[i].getAge();
        arr[i].getPhone();
        cout<<endl;
    }
    //Deallocate Data
    delete[] arr;
    
    cout<<endl<<endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
    //Variables
    int size;
    string info;
    int units;
    float price;
    //Get array of products
    cout<<"How many items are in your store?: ";
    cin>>size;
    cin.ignore();
    unique_ptr<RetailItem[]> arr(new RetailItem[size]);
    //Input Data
    for(int i=0;i<size;i++){
        cout<<"Item #"<<i+1<<"'s description: ";
        getline(cin,info);
        cout<<"Input number of products at hand: ";
        cin>>units;
        cout<<"Input price of product: $";
        cin>>price;
        cin.ignore();
    //Process Data
        arr[i].setInfo(info);
        arr[i].setUnit(units);
        arr[i].setPrice(price);
    }
    //Output Data
    cout<<"         Description            #units Price"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Item #"<<setw(3)<<left<<i+1<<setw(25)<<left<<arr[i].getInfo()
                <<setw(4)<<left<<arr[i].getUnit()<<"$"<<showpoint<<fixed
                <<setprecision(2)<<arr[i].getPrice()<<endl;
    }
    
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    //Variables
    int itemNum, quant; //Item number, quantity of items
    float cost;         //Cost of item in $
    Inventory *arr;     //Array of items
    int n;              //Number of elements in array
    //Input Data
    cout<<"This program holds information on a store's inventory.\n"
          "How many items do you have?\n"
          "Items: ";
    cin>>n;
    if(n<=0){
        cout<<"You need at least one element"<<endl;
        return;
    }
    //Allocate Memory
    arr=new Inventory[n];
    for(int i=0;i<n;i++){
        cout<<"Input item #"<<i+1<<"'s Item Number: ";
        cin>>itemNum;
        cout<<"Input quantity of items on hand: ";
        cin>>quant;
        cout<<"Input the per-unit cost of the item: $";
        cin>>cost;
    //Process Data
        arr[i].setItemNum(itemNum);
        arr[i].setQuant(quant);
        arr[i].setCost(cost);
        arr[i].setTotCost();
    }
    //Output Data
    cout<<"ItemNum   quantity  cost      totCost"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(13)<<left<<arr[i].getItemNum()<<setw(5)<<left
            <<arr[i].getQuant()<<"$"<<setw(10)<<fixed<<showpoint
            <<setprecision(2)<<arr[i].getCost()<<"$"<<fixed
            <<showpoint<<setprecision(2)<<arr[i].getTotCost()<<endl;
    }
    //Deallocate Memory
    delete[] arr;
    
    cout<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    //Variables
    int x;
    //Input Data
    cout<<"This programs translates a decimal number into english."<<endl;
    do{
        cout<<"Input a number between 0-9999: ";
        cin>>x;
    }while(x<0||x>9999);
    //Create a Number object
    Number n(x);
    //Output Data
    n.print();
    
    cout<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    
    //Variables
    int x;
    //Input Data
    cout<<"This program translates an integer to the date it corresponds to.\n";
    do{
        cout<<"Input a number 1-365: ";
        cin>>x;
    }while(x<1&&x>365);
    //Process Data
    DayOfYear n(x);
    //Output Data
    n.print();
    
    cout<<endl<<endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    
    //Variables
    string month;
    int day;
    //Input Data
    cout<<"This program takes a month and day"<<endl;
    cout<<"Input the first three lowercase letters of the month(jan,feb..): ";
    getline(cin,month);
    cout<<"Input the day of the month: ";
    cin>>day;
    //Process Data
    DayOfYear n(month,day);
    //Output Data
    n.print();
    cout<<" using the -- operator: ";
    n--;
    n.print();
    cout<<endl<<"And now after using the ++ operator twice: ";
    n++;
    n++;
    n.print();
    cout<<endl;
    
    cout<<endl<<endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    
    //Variables
    NumDays obj1,obj2;
    int n;
    //Input Data
    cout<<"This program converts work hours to days. For example, 8 hours equals"
            " 1 day."<<endl<<"Input amount of whole hours for object 1: ";
    cin>>n;
    obj1.setHours(n);
    cout<<"Input amount of whole hours for object 2: ";
    cin>>n;
    obj2.setHours(n);
    //Process Data
    
    //Output Data
    cout<<obj1.getHours()<<" hours = "<<obj1.getDays()<<" days"<<endl;
    cout<<obj2.getHours()<<" hours = "<<obj2.getDays()<<" days"<<endl;
    obj1++;
    cout<<"Object 1++ = "<<obj1.getDays()<<" days"<<endl;
    obj2--;
    cout<<"Object 2-- = "<<obj2.getDays()<<" days"<<endl;
    cout<<"Object 1+2 = "<<obj1+obj2<<" days"<<endl;
    cout<<"Object 1-2 = "<<obj1-obj2<<" days"<<endl;
    
    cout<<endl<<endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    
    //Variables
    string name,id;
    int day;
    //Input Data
    cout<<"This program tracks an employee's sick leave, vacation, and unpaid"
            " time off."<<endl;
    cout<<"Input employee's name: ";
    getline(cin,name);
    cout<<"Input "<<name<<"'s id number: ";
    getline(cin,id);
    //Create TimeOff Object
    TimeOff a(name,id);
    //Input More Data
    cout<<"Input max amount of sick days employee can take: ";
    cin>>day;
    a.setMaxSick(day);
    cout<<"Input amount of sick days taken: ";
    cin>>day;
    a.setSick(day);
    cout<<"Input amount of vacation days taken: ";
    cin>>day;
    a.setVacTaken(day);
    cout<<"Input max amount of days of unpaid leave an employee can take: ";
    cin>>day;
    a.setMaxUnpaid(day);
    cout<<"Input amount of days of unpaid leave taken: ";
    cin>>day;
    a.setUnpaid(day);
    //Output Data
    a.getEmployee();
    cout<<"Sick days remaining: "<<a.sickR()<<endl;
    cout<<"Vacation days remaining: "<<a.vacR()<<endl;
    cout<<"Unpaid leave days remaining: "<<a.unpR()<<endl;
    
    cout<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}