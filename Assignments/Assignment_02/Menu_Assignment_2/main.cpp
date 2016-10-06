/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 5, 2016, 10:00 PM
 * Purpose: Menu for assignment two
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <iomanip>   //Output manipulation
#include <string>    //String library
#include <cstdlib>   //Random Library
#include <ctime>     //Time Library
using namespace std; //Namespace of the System Libraries

//User Libraries
#include "moviedata.h"
#include "moviedataV2.h"
#include "sales.h"
#include "weather.h"
#include "weather2.h"
#include "soccer.h"
#include "customer.h"
#include "speakers.h"
#include "Array.h"
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
void problem11();

MovieData *getData(int);
void display(const MovieData*,int);
MovieData2 *getData2(int);
void display(const MovieData2*,int);
void getSales(SaleDat*,int);
void display(const SaleDat*,int);
void getWther(Weather[],int);
void display(Weather[],int,float,float,float,float,float,int,int);
void getStat(Weather[],float&,float&,int&,int&,int,float&,float&,float&);
void month(int);
void getWther(Weather2[]);
void display(Weather2[],float,float,float,float,float,int,int);
void getStat(Weather2[],float&,float&,int&,int&,float&,float&,float&);
void inPlayer(Soccer*,int);
void display(Soccer*,int);
void change(Customer*);
void display(Customer*);
void find(Customer*,int);
void input(Speaker*,int);
void change(Speaker*);
void find(Speaker*,int);
void display(Speaker*,int);
void prntAry(Array);
Array fillAry(int);
Array fillIndx(int);
void mrkSort(Array,Array);
void swap(Array&,int,int);
//Execution

int main(int argc, char** argv) {
    //Set Random Seed
    srand(static_cast<unsigned int>(time(0)));
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
            case 11: problem11();break;
            default: def(inN);
         }
        }while(inN>0&&inN<12);
        
    //Output Data

    return 0;
}

void Menu(){
    //Output Data
    cout<<"Please input the problem you wish to view.\n";
    cout<<"The possible options are:\n"
          " 1.   Gaddis_8thEd_Chap11_Prob01_MovieData\n"
          " 2.   Gaddis_8thEd_Chap11_Prob02_MovieProfit\n"
          " 3.   Gaddis_8thEd_Chap11_Prob03_CorporateSalesData\n"
          " 4.   Gaddis_8thEd_Chap11_Prob04_WeatherStatistics\n"
          " 5.   Gaddis_8thEd_Chap11_Prob05_WeatherStatisticsV2\n"
          " 6.   Gaddis_8thEd_Chap11_Prob06_SoccerScores\n"
          " 7.   Gaddis_8thEd_Chap11_Prob07_CustomerAccounts\n"
          " 8.   Gaddis_8thEd_Chap11_Prob08_CustomerAccountsV2\n"
          " 9.   Gaddis_8thEd_Chap11_Prob09_SpeakersBureau\n"
          "10.   Gaddis_8thEd_Chap11_Prob10_SpeakersBureauV2\n"
          "11.   ClassProblem_StructureSort\n\n"
          " 0.   Exit\n";
}

int getN(){
    //Variables
    int inN;
    //Input Data
    cin>>inN;
    cin.ignore();
    //Return Data
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    return inN;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    
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
    
    cout<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    //Variables
    MovieData2 *array; //Array of movie data
    int size;         //Size of array
    //Input Data
    cout<<"How many movies do you want to store?"<<endl;
    cin>>size;
    
    //Process Data
    array=getData2(size);
    //Output Data
    display(array,size);
    
    //Deallocate Memory
    delete[] array;
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    //Variables
    SaleDat array[QUARTER];      //Array of Sales Data structure
    
    //Input Data
    getSales(array,QUARTER);
    
    //Process Data
    
    //Output Data
    display(array,QUARTER);
    
    cout<<endl<<endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
    //Variables
    const int MONTHS=12;
    Weather data[MONTHS];
    float high,low;      //Temp high and Temp low
    int hMonth,lMonth;   //Temp high month and Temp low Month
    float totRain,aveRain,aveTemp;
    //Input Data
    getWther(data,MONTHS);
    //Process Data
    getStat(data,high,low,hMonth,lMonth,MONTHS,totRain,aveRain,aveTemp);
    //Output Data
    display(data,MONTHS,totRain,aveRain,aveTemp,high,low,hMonth,lMonth);
    
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    //Variables
    Weather2 data[DEC+1];
    float high,low;      //Temp high and Temp low
    int hMonth,lMonth;   //Temp high month and Temp low Month
    float totRain,aveRain,aveTemp;
    //Input Data
    getWther(data);
    //Process Data
    getStat(data,high,low,hMonth,lMonth,totRain,aveRain,aveTemp);
    //Output Data
    display(data,totRain,aveRain,aveTemp,high,low,hMonth,lMonth);
    
    cout<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    //Variables
    int size=2;
    Soccer *team=new Soccer[size];
    
    //Input Data
    cout<<"How many players on the team?"<<endl;
    cin>>size;
    inPlayer(team,size);
    //Process Data
    
    //Output Data
    display(team,size);
    
    delete[] team;
    
    cout<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    
    //Variables
    const int SIZE=10;
    Customer *data=new Customer[SIZE];
    char choice;
    
    //Input Data
    do{
        cout<<"Press 1 to enter data in the array\n"
            <<"Press 2 to view data in array\n"
            <<"Press 3 to exit"<<endl;
        cin>>choice;
        if(choice=='1')
            change(data);
        else if(choice=='2')
            display(data);
    }while(choice=='1'||choice=='2');
    //Process Data
    
    //Output Data

    delete[] data;
    
    cout<<endl<<endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    
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
    
    cout<<endl<<endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    
    //Variables
    const int SIZE=10;
    Speaker *data=new Speaker[SIZE];
    char choice;
    
    //Input Data
    do{
        cout<<"Press 1 to enter data in the array\n"
            <<"Press 2 to change elements in array\n"
            <<"Press 3 to view all speakers\n"
            <<"Press 4 to exit\n";
        cin>>choice;
        if(choice=='1')
            input(data,SIZE);
        else if(choice=='2')
            change(data);
        else if(choice=='3')
            display(data,SIZE);
    }while(choice=='1'||choice=='2'||choice=='3');
    //Process Data
    
    //Output Data

    delete[] data;
    
    cout<<endl<<endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    
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
    
    cout<<endl<<endl;
}

void problem11(){
    cout<<"In problem # 11"<<endl<<endl;
    
    //Variables
    const int SIZE=100;
    Array array, index;
    //Input Data
    array=fillAry(SIZE);
    index=fillIndx(SIZE);
    
    //Output Original Data
    cout<<"Original Array:"<<endl;
    prntAry(array);
    cout<<"Original Indexed Array:"<<endl;
    prntAry(index);
    
    //Process Data
    mrkSort(array,index);
    
    //Output New Data
    cout<<"Original Array sorted:"<<endl;
    prntAry(array);
    cout<<"Original Indexed Array sorted:"<<endl;
    prntAry(index);
    
    //Deallocate Memory
    delete[] array.data;
    delete[] index.data;
    
    cout<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
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
        cout<<"Running Time (in minutes): "<<a[i].runTime<<endl<<endl;
    }
}

MovieData2 *getData2(int n){
    //Allocate Memory
    MovieData2 *a=new MovieData2[n];
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

void display(const MovieData2 *a,int n){
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

void getSales(SaleDat *a,int n){
    //Variables
    float temp; //Temporary variable
    //Input Data
    for(unsigned int i=0;i<n;i++){
        a[i].divName=i;
        for(int j=0;j<n;j++){
            a[i].sales[j]=(rand()%100)*100;
        }
        for(int j=0;j<n;j++){
            //Temp variable
            if(j==0)temp=0; //So temp does not reset each loop
            temp+=a[i].sales[j];
            if(j==(n-1))a[i].totSale=temp;
        }
            a[i].aveSale=a[i].totSale;
            a[i].aveSale/=4;
    }
}

void display(const SaleDat *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<"Division: ";
        switch (a[i].divName){
            case  0:cout<<"East\n";break;
            case  1:cout<<"West\n";break;
            case  2:cout<<"North\n";break;
            default:cout<<"South\n";break;
        }
        for(int j=0;j<n;j++){
            switch (j){
                case  0:cout<<"First ";break;
                case  1:cout<<"Second ";break;
                case  2:cout<<"Third ";break;
                default:cout<<"Fourth ";break;
            }
            cout<<"Quarter Sales: $";
            cout<<fixed<<showpoint<<setprecision(2)<<a[i].sales[j]<<endl;
        }
        cout<<"Total Annual Sales: $";
        cout<<fixed<<showpoint<<setprecision(2)<<a[i].totSale<<endl;
        cout<<"Average Quarterly Sales: $";
        cout<<fixed<<showpoint<<setprecision(2)<<a[i].aveSale<<endl<<endl;
    }
}

void getWther(Weather a[],int n){
    bool flag;
    //Input Data
    for(int i=0;i<n;i++){
        do{
            flag=true;
            cout<<"Input the total rainfall for ";
                month(i);
                cout<<"in inches: ";
            cin>>a[i].rain;
            if(a[i].rain<0){
                cout<<"Rainfall must be positive!"<<endl;
                flag=false;
            }
        }while(!flag);
        do{
            flag=true;
            cout<<"Input the high temp for ";
                month(i);
                cout<<"in F°: ";
            cin>>a[i].high;
            if(a[i].high<-100||a[i].high>140){
                cout<<"Temperature must be within -100F° and 140F°!"<<endl;
                flag=false;
            }
        }while(!flag);
        do{
            flag=true;
            cout<<"Input the low temp for ";
                month(i);
                cout<<"in F°: ";
            cin>>a[i].low;
            if(a[i].low<-100||a[i].low>140){
                cout<<"Temperature must be within -100F° and 140F°!"<<endl;
                flag=false;
            }
        }while(!flag);
        a[i].ave=(a[i].high+a[i].low)/2;
    }
}

void getStat(Weather a[],float &high,float &low,int &hMonth,int &lMonth,int n,
        float &totRain,float &aveRain,float &aveTemp){
    //Variables
    totRain=a[0].rain;
    aveTemp=a[0].ave;
    high=(a[0].high);
    hMonth=0;
    low=(a[0].low);
    lMonth=0;
    //Process Data
    for(int i=1;i<n;i++){
        if((a[i].high)>high){
            high=(a[i].high);
            hMonth=i;
        }
        if((a[i].low)<low){
            low=(a[i].low);
            lMonth=i;
        }
        totRain+=a[i].rain;
        aveTemp+=a[i].ave;
    }
    aveTemp/=n;
    aveRain=totRain/n;
}

void display(Weather a[],int n,float tR,float aR,float aT,float h,float l,
        int hM, int lM){
    //Output Data
    cout<<" Ave. rain: "<<fixed<<showpoint<<setprecision(2)<<aR
        <<"\""<<endl;
    cout<<"Total Rain: "<<fixed<<showpoint<<setprecision(2)<<tR<<"\""<<endl;
    cout<<"      High: "<<h<<" F° in month ";
    month(hM);
    cout<<endl<<"       Low: "<<l<<" F° in month ";
    month(lM);
    cout<<endl<<"  Ave temp: "<<aT<<" F°"<<endl;
}

void getWther(Weather2 a[]){
    bool flag;
    //Input Data
    for(int i=JAN;i<=DEC;i++){
        do{
            flag=true;
            cout<<"Input the total rainfall for ";
                month(i);
                cout<<"in inches: ";
            cin>>a[i].rain;
            if(a[i].rain<0){
                cout<<"Rainfall must be positive!"<<endl;
                flag=false;
            }
        }while(!flag);
        do{
            flag=true;
            cout<<"Input the high temp for ";
                month(i);
                cout<<"in F°: ";
            cin>>a[i].high;
            if(a[i].high<-100||a[i].high>140){
                cout<<"Temperature must be within -100F° and 140F°!"<<endl;
                flag=false;
            }
        }while(!flag);
        do{
            flag=true;
            cout<<"Input the low temp for ";
                month(i);
                cout<<"in F°: ";
            cin>>a[i].low;
            if(a[i].low<-100||a[i].low>140){
                cout<<"Temperature must be within -100F° and 140F°!"<<endl;
                flag=false;
            }
        }while(!flag);
        a[i].ave=(a[i].high+a[i].low)/2;
    }
}

void getStat(Weather2 a[],float &high,float &low,int &hMonth,int &lMonth,
        float &totRain,float &aveRain,float &aveTemp){
    //Variables
    totRain=a[JAN].rain;
    aveTemp=a[JAN].ave;
    high=(a[JAN].high);
    hMonth=JAN;
    low=(a[JAN].low);
    lMonth=JAN;
    //Process Data
    for(int i=FEB;i<=DEC;i++){
        if((a[i].high)>high){
            high=(a[i].high);
            hMonth=i;
        }
        if((a[i].low)<low){
            low=(a[i].low);
            lMonth=i;
        }
        totRain+=a[i].rain;
        aveTemp+=a[i].ave;
    }
    aveTemp/=(DEC+1);
    aveRain=totRain/(DEC+1);
}

void display(Weather2 a[],float tR,float aR,float aT,float h,float l,
        int hM, int lM){
    //Output Data
    cout<<" Ave. rain: "<<fixed<<showpoint<<setprecision(2)<<aR
        <<"\""<<endl;
    cout<<"Total Rain: "<<fixed<<showpoint<<setprecision(2)<<tR<<"\""<<endl;
    cout<<"      High: "<<h<<" F° in month ";
    month(hM);
    cout<<endl<<"       Low: "<<l<<" F° in month ";
    month(lM);
    cout<<endl<<"  Ave temp: "<<aT<<" F°"<<endl;
}

void month(int n){
    //Output Data
    switch (n){
        case 0:cout<<"Jan ";break;
        case 1:cout<<"Feb ";break;
        case 2:cout<<"Mar ";break;
        case 3:cout<<"Apr ";break;
        case 4:cout<<"May ";break;
        case 5:cout<<"Jun ";break;
        case 6:cout<<"Jul ";break;
        case 7:cout<<"Aug ";break;
        case 8:cout<<"Sep ";break;
        case 9:cout<<"Oct ";break;
        case 10:cout<<"Nov ";break;
        default:cout<<"Dec ";break;
    }
}

void inPlayer(Soccer *a,int n){
    //Input Data
    for(int i=0;i<n;i++){
        cin.ignore();
        cout<<"Input Player "<<i+1<<"'s name: ";
        getline(cin,a[i].name);
        cout<<"Input Player "<<i+1<<"'s number: ";
        cin>>a[i].num;
        cout<<"Input Points scored by "<<a[i].name<<": ";
        cin>>a[i].points;
    }
    cout<<endl;
}

void display(Soccer *a,int n){
    //Variables
    int *high=&(a[0].points);
    string *highN=&(a[0].name);
    int sum=0;
    //Output Data
    cout<<"Number      Name      Pts Scored"<<endl;
    for(int i=0;i<n;i++){
        cout<<right<<setw(4)<<a[i].num<<right<<setw(16)<<a[i].name
                <<"     "<<a[i].points<<endl;
        if(i!=0){
            if(*high<a[i].points){
                high=&(a[i].points);
                highN=&(a[i].name);
            }
        }
        sum+=a[i].points;
    }
    cout<<"The team scored "<<sum<<" points in total!"<<endl;
    cout<<*highN<<" scored the most points with "<<*high<<" points!"<<endl;
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

void input(Speaker *a,int n){
    //Variables
    int choice;
    //Input Data
    cout<<"Which customer's data would you like to input?\n"
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
            cout<<"Input name for customer #"<<i+1<<": ";
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
        cout<<"Input name for customer #"<<i+1<<": ";
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
    cout<<"Which customer's data would you like to change?\n"
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
                cout<<"Input name for customer #"<<choice+1<<": ";
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

void mrkSort(Array a,Array indx){
    for(int i=0;i<a.size-1;i++){
        for(int j=i+1;j<a.size;j++){
            if(a.data[i]>a.data[j]){
                swap(a,i,j);
                swap(indx,i,j);
            }
        }
    }
}

Array fillAry(int n){
    //Variables
    Array a;
    a.size=n;
    //Allocate Memory
    a.data=new int[a.size];
    //Input Data
    for(int i=0;i<a.size;i++){
        a.data[i]=rand()%90+10;// Random 2 digit numbers
    }
    return a;
}

Array fillIndx(int n){
    //Variables
    Array a;
    a.size=n;
    //Allocate Memory
    a.data=new int[a.size];
    //Input Data
    for(int i=0;i<a.size;i++){
        a.data[i]=i;
    }
    return a;
}

void prntAry(Array a){
    cout<<endl;
    for(int i=0;i<a.size;i++){
        cout<<setw(2)<<a.data[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    cout<<endl;
}

void swap(Array &a,int i,int j){
    a.data[i]=a.data[i]^a.data[j];
    a.data[j]=a.data[i]^a.data[j];
    a.data[i]=a.data[i]^a.data[j];
}