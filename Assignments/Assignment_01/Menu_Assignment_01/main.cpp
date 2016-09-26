/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 25, 2016, 11:30 AM
 * Purpose: Menu for assignment one.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <ctime>     //Time Library
#include <cstdlib>   //Random Library
#include <iomanip>   //Output Manipulation
#include <string>    //STring library
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
int *getArry(int);
void display(float*,int);
void getArry(float*,int);
void sort(float*,int);
void display(float*,string*,int);
void getArry(float*,string*,int);
void sort(float*,string*,int);
float average(float*,int);
//int doSomething(int &x, int &y) //Old Code
int doSomething(int*, int*); //New Code
void arrSort1(int*,int); //Selection sort ascending order
void arrSort2(int*,int); //Selection sort descending order
void showArr(int*,int);
void getArr(int*,int*,int);
int *copy(int[],int);
int *shift(int[],int);
int *fillAry(int,int);
void sort(int*,int);
float average(int*,int);
float median(int*,int);
int *mode(int*,int,int,int&);
void display(int*,int);
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
          "     1.   Gaddis_8thEd_Chap09_Prob01_ArrayAllocator\n"
          //Dynamically allocates an array of user size choice.
          "     2.   Gaddis_8thEd_Chap09_Prob02_TestScores1\n"
          //Dynamic array of test scores. Sorts and averages them.
          "     3.   Gaddis_8thEd_Chap09_Prob03_DropLowestScore\n"
          //Dynamic array of test scores. Sorts and averages them and drop
          //the lowest score.
          "     4.   Gaddis_8thEd_Chap09_Prob04_TestScores2\n"
          //Dynamic array of test scores and names. Sorts and averages them 
          //after dropping the lowest test score.
          "     5.   Gaddis_8thEd_Chap09_Prob05_PointerRewrite\n"
          //Rewrite a function so that it uses pointers instead of reference 
          //variables.
          "     6.   Gaddis_8thEd_Chap09_Prob06_CaseStudyModV1\n"
          //Gets an array of donations and points to them sorted descending.
          "     7.   Gaddis_8thEd_Chap09_Prob07_CaseStudyModV2\n"
          //Gets an array of donations and points to them sorted ascending.
          "     8.   Gaddis_8thEd_Chap09_Prob10_ReverseArray\n"
          //Return a pointer that points to an array in reverse order.
          "     9.   Gaddis_8thEd_Chap09_Prob12_ElementShifter\n"
          //Create a new array 1 size larger than argument array. Set first 
       //element of new array to 0 and copy the rest to each subsequent element.
          "    10.   ClassProblem_MeanMedianMode\n\n"
          //Return average, median and mode from array.
          "     0.   Exit\n";
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
    int size;
    int *array;
    
    //Input Data
    cout<<"Input a size of an array to dynamically allocate: ";
    cin>>size;
    
    //Process Data
    array=getArry(size);
    
    //Output Data and Deallocate Memory
    cout<<"The values in your pointer array of size "<<size<<":"<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    delete[] array;
    
    cout<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    //Variables
    float *array;
    int nTests;
    float ave;
    //Input Data & Allocate Memory
    cout<<"Input amount of tests: ";
    cin>>nTests;
    if(nTests<1){
        cout<<"Invalid amount."<<endl;
        cout<<endl<<endl;
        return;
    }
    array=new float[nTests];
    getArry(array,nTests);
    
    //Process Data
    if(nTests<2){
        cout<<"Test #"<<nTests<<"'s score is ="<<array[0]<<endl;
        delete[] array;
        cout<<endl<<endl;
        return;
    }
    cout<<"Test scores before sorting:"<<endl;
    display(array,nTests);
    sort(array,nTests);
    ave=average(array,nTests);
            
    //Output Data
    cout<<"Test scores after sorting:"<<endl;
    display(array,nTests);
    cout<<"The average test score is "<<ave<<endl;
    //Deallocate Memory
    delete[] array;
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    //Variables
    float *array;
    int nTests;
    float ave, ave2; //Average and average after dropping lowest score
    //Input Data & Allocate Memory
    cout<<"Input amount of tests: ";
    cin>>nTests;
    if(nTests<1){
        cout<<"Invalid amount."<<endl;
        cout<<endl<<endl;
        return;
    }
    array=new float[nTests];
    getArry(array,nTests);
    
    //Process Data
    if(nTests<2){
        cout<<"Test #"<<nTests<<"'s score: "<<array[0]<<endl;
        delete[] array;
        cout<<endl<<endl;
        return;
    }
    cout<<"Test scores before sorting:"<<endl;
    display(array,nTests);
    sort(array,nTests);
    ave=average(array,nTests);
    ave2=average(array,nTests-1);
            
    //Output Data
    cout<<"Test scores after sorting:"<<endl;
    display(array,nTests);
    cout<<"The average test score: "<<ave<<endl;
    cout<<"Average after dropping the lowest test: "<<ave2<<endl;
    //Deallocate Memory
    delete[] array;
    
    cout<<endl<<endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    //Variables
    float *array;
    string *names;
    int nTests;
    float ave; //Average score
    //Input Data & Allocate Memory
    cout<<"Input amount of tests: ";
    cin>>nTests;
    if(nTests<1){
        cout<<"Invalid amount."<<endl;
        cout<<endl<<endl;
        return;
    }
    array=new float[nTests];
    names=new string[nTests];
    getArry(array,names,nTests);
    
    //Process Data
    cout<<"Test scores before sorting:"<<endl;
    display(array,names,nTests);
    sort(array,names,nTests);
    ave=average(array,nTests);
            
    //Output Data
    cout<<"Test scores after sorting:"<<endl;
    display(array,names,nTests);
    cout<<"Average test score: "<<showpoint<<setprecision(2)<<ave<<endl;
    //Deallocate Memory
    delete[] array;
    delete[] names;
    
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
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

    cout<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    //Variables
    int n;        //Number of donations
    int *origPtr; //Original array of donations
    int *newPtr;  //Sorted array of donations
    //Input Data
    cout<<"Input amount of donations: ";
    cin>>n;
    origPtr=new int[n];
    newPtr=new int[n];
    getArr(origPtr,newPtr,n);
    //Process Data
    arrSort1(newPtr,n);
    //Output Data
    cout<<"The Donations, sorted in ascending order:"<<endl;
    showArr(newPtr,n);
    cout<<"The Donations in their original order:"<<endl;
    showArr(origPtr,n);
    //Deallocate Memory
    delete []newPtr;
    delete []origPtr;
    
    cout<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    //Variables
    int n;        //Number of donations
    int *origPtr; //Original array of donations
    int *newPtr;  //Sorted array of donations
    //Input Data
    cout<<"Input amount of donations: ";
    cin>>n;
    origPtr=new int[n];
    newPtr=new int[n];
    getArr(origPtr,newPtr,n);
    //Process Data
    arrSort2(newPtr,n);
    //Output Data
    cout<<"The Donations, sorted in descending order:"<<endl;
    showArr(newPtr,n);
    cout<<"The Donations in their original order:"<<endl;
    showArr(origPtr,n);
    //Deallocate Memory
    delete []newPtr;
    delete []origPtr;
    
    cout<<endl<<endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    //Variables
    int SIZE=10;
    int array[SIZE]={0,9,1,8,2,7,3,6,4,5};
    int *ptr;
    //Input Data
    ptr=copy(array,SIZE);
    //Output Data
    cout<<"Original Array:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<"New Array with Elements Reversed:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    //Deallocate Memory
    delete[] ptr;
    
    cout<<endl<<endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    //Variables
    const int SIZE=10;
    int origArr[SIZE]={0,1,2,3,4,5,6,7,8,9};
    int *newArr;
    //Input Data
    newArr=shift(origArr,SIZE);
    //Process Data
    
    //Output Data
    cout<<"Original Array:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<origArr[i]<<" ";
    }
    cout<<endl<<"New Array:"<<endl;
    for(int i=0;i<(SIZE+1);i++){
        cout<<newArr[i]<<" ";
    }
    //Deallocate Memory
    delete[] newArr;
    
    cout<<endl<<endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    //Variables
    int size;    //Size of the number array
    int m;       //Number of unique numbers
    int *array;  //Number array
    int *modeArr;//Mode Array
    float ave;   //Average
    float med;   //Median
    int nModes;  //Number of modes
    
    //Input Data
    cout<<"Input number of elements in the number array: ";
    cin>>size;
    if(size<1){
        cout<<"Error: There must be at least 1 element in the array"<<endl;
        cout<<endl<<endl;
        return;
    }
    cout<<"Input number of unique elements: ";
    cin>>m;
    if(m<1){
        cout<<"Error: There must be at least one unique element"<<endl;
        cout<<endl<<endl;
        return;
    }
    if(m>size){
        cout<<"Error: You can not have more unique elements than elements"<<endl;
        cout<<endl<<endl;
        return;
    }
    array=fillAry(size,m);
    
    //Process Data
    cout<<"Original Array:"<<endl;
    display(array,size);
    sort(array,size);
    ave=average(array,size);
    med=median(array,size);
    modeArr=mode(array,size,m,nModes);
    
    //Output Data
    cout<<"Sorted Array:"<<endl;
    display(array,size);
    cout<<"Average = "<<ave<<endl<<"Median = "<<med<<endl;
    cout<<"Mode Array with Number of modes, Frequency of mode(s), "
            "and mode(s):"<<endl;
    display(modeArr,2+nModes);
    
    //Deallocate Memory
    delete[] array;
    delete[] modeArr;
    
    cout<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

int *getArry(int n){
    //Allocate Memory
    int *a= new int[n];
    //Input Data and Return pointer
    for(int i=0;i<n;i++){
        a[i]=rand()%9;
    }
    return a;
}

void display(float *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if((i+1)%10==0)cout<<endl;
    }
    cout<<endl;
}

void getArry(float *a,int n){
    //Input Data
    for(int i=0;i<n;i++){
        cout<<"Input Score of test #"<<i+1<<": ";
        cin>>a[i];
    }
}

void sort(float *a,int n){
    //Variables
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
                flag=true;
            }
        }
    }while(flag==true);
}

void display(float *a,string *name,int n){
    //Output Data
    cout<<"Num Name    Score"<<endl;
    for(int i=0;i<n;i++){
        name[i]=name[i].substr(0,8);//Truncating name to 8 chars
        cout<<left;
        cout<<setw(4)<<i+1;
        cout<<setw(8)<<name[i]<<" ";
        cout<<setw(3)<<a[i]<<endl;
    }
    cout<<endl;
}

void getArry(float *a,string *name,int n){
    //Input Data
    for(int i=0;i<n;i++){
        cout<<"Input Score of test #"<<i+1<<": ";
        cin>>a[i];
        cin.ignore();
        cout<<"Input name of test #"<<i+1<<": ";
        getline(cin,name[i]);
    }
}

void sort(float *a,string *b,int n){
    //Variables
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
                swap(b[i],b[i+1]);
                flag=true;
            }
        }
    }while(flag==true);
}

float average(float *a,int n){
    //Variables
    float ave=0;
    //Process Data
    for(int i=0;i<n;i++){
        ave+=a[i];
    }
    ave/=n;
    return(ave);
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

void getArr(int *a,int *b,int n){
    //Input Data
    for(int i=0;i<n;i++){
        a[i]=(rand()%10+1)*5;
        b[i]=a[i];
    }
}

void showArr(int *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<"$"<<setw(2)<<*(a+i)<<".00 ";
        if((i+1)%10==0)cout<<endl;
    }
    cout<<endl;
}

void arrSort1(int *a,int n){
    //Variables
    int start, minIndx; //Start scan, Minimum index
    int minElem;       //Minimum Element
    //Process Data
    for(start=0;start<(n-1);start++){
        minIndx=start;
        minElem=a[start];
        for(int index=(start+1);index<n;index++){
            if(a[index]<minElem){
                minElem=a[index];
                minIndx=index;
            }
        }
        a[minIndx]=a[start];
        a[start]=minElem;
    }
}

void arrSort2(int *a,int n){
    //Variables
    int start, minIndx; //Start scan, Minimum index
    int minElem;       //Minimum Element
    //Process Data
    for(start=0;start<(n-1);start++){
        minIndx=start;
        minElem=a[start];
        for(int index=(start+1);index<n;index++){
            if(a[index]>minElem){
                minElem=a[index];
                minIndx=index;
            }
        }
        a[minIndx]=a[start];
        a[start]=minElem;
    }
}

int *copy(int a[],int n){
    //Variables and Allocate Memory
    int *pointer=new int[n];
    //Input Data
    for(int i=0;i<n;i++){
        pointer[i]=a[(n-1)-i];
    }
    return pointer;
}

int *shift(int a[],int n){
    //Variables
    int *array=new int[n+1]{}; //Initialize to 0
    //Input Data
    for(int i=0;i<n;i++){
        array[i+1]=a[i];
    }
    //Output Data
    return array;
}

int *fillAry(int n,int m){
    //Variables and Allocate Memory
    int a=1;
    int *array=new int[n];
    //Input Data
    for(int i=0,j=0;i<n;i++,j++){
        array[i]=j;
        if(j==(m-1))j=-1;
    }
    return array;
}

void sort(int *a,int n){
    //Variables
    bool flag;
    //Process Data
    do{
        flag=false;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                a[i]=a[i]^a[i+1];
                a[i+1]=a[i]^a[i+1];
                a[i]=a[i]^a[i+1];
                flag=true;
            }
        }
    }while(flag);
}

float average(int *a,int n){
    //Variables
    float ave=0;
    //Process Data
    for(int i=0;i<n;i++){
        ave+=a[i];
    }
    ave/=n;
    return ave;
}

float median(int *a,int n){
    //Variables
    float med;
    //Process Data
    if(n%2==1){
        int temp=(n/2);
        med=a[temp];
    }else{
        int temp=n/2;
        med=(a[temp]+a[temp-1])/2.0f;
    }
    return med;
}

int *mode(int *a,int n,int m,int &nModes){
    //Variables
    int *ptrArr;     //Pointer array to Mode Array
    int *tempArr[n]; //Temp array to store modes
    int freq=1;      //Frequency of numbers
    int maxFreq=1;   //Max frequency of mode(s)
    nModes=0;
    //Process Data
    if(m==1){
        maxFreq=n;
        nModes=1;
    }
    else if(m==n){
        maxFreq=0;
        nModes=0;
    }else{
        for(int i=0;i<n;i++){
            if(a[i]==a[i+1]){ //If consecutive numbers match add to frequency
                freq+=1;
            }
            else{             //If numbers don't match calculate if mode or not
                if(freq>maxFreq){       //If new max frequency, new mode is a[i]
                    maxFreq=freq;
                    nModes=1;
                    tempArr[0]=&a[i];
                }else if(freq==maxFreq){//If max frequency matches, add a[i]to modes
                    tempArr[nModes]=&a[i];
                    nModes++;
                }
                freq=1; //Reset Frequency count
            }
        }
    }
    //Allocate Memory
    ptrArr=new int[2+nModes];
    //Input Data into pointer array
    ptrArr[0]=nModes;
    ptrArr[1]=maxFreq;
    for(int i=0;i<nModes;i++){
        ptrArr[2+i]=*tempArr[i];
    }
    return ptrArr;
}

void display(int *a,int n){
    //Output Data
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}