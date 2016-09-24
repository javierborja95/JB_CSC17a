/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on September 23, 2016, 5:00 PM
 * Purpose: Return average, median and mode from array.
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int,int);
void sort(int*,int);
float average(int*,int);
float median(int*,int);
int *mode(int*,int,int,int&);
void display(int*,int);
//Execution

int main(int argc, char** argv) {
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
        return 0;
    }
    cout<<"Input number of unique elements: ";
    cin>>m;
    if(m<1){
        cout<<"Error: There must be at least one unique element"<<endl;
        return 0;
    }
    if(m>size){
        cout<<"Error: You can not have more unique elements than elements"<<endl;
        return 0;
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
    cout<<"Mode Array with Number of mode(s), Frequency of mode(s), "
            "and mode(s):"<<endl;
    display(modeArr,2+nModes);
    
    //Deallocate Memory
    delete[] array;
    delete[] modeArr;
    
    return 0;
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