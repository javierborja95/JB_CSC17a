/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 18, 2016, 2:30 PM
 * Purpose: Menu for assignment three
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <fstream>   //File I/O
#include <string>    //Strings
#include <vector>    //Vectors
#include <iomanip>   //Output Manipulation
#include <cstdlib>   //Random Library
#include <ctime>     //Time Library

using namespace std; //Namespace of the System Libraries

//User Libraries
#include "sales.h"

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

int length(string*);
void reverse(string*);
int count(string*);
void count(string*,int&,float&);
void count(string,int&,int&);
void read(fstream&);
void read2(fstream&);
void find(fstream&,string);
void read3(fstream&);
void lower(fstream&,fstream&);
void arrToFile(fstream&,int*,int);
void fileToArr(fstream&,int*,int);
void getSales(SaleDat*,int);
void display(const SaleDat*,int);
void write(const SaleDat*,int);
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
          " 1.   Gaddis_8thEd_Chap10_Prob01_StringLength\n"
          " 2.   Gaddis_8thEd_Chap10_Prob02_BackwardString\n"
          " 3.   Gaddis_8thEd_Chap10_Prob03_WordCounter\n"
          " 4.   Gaddis_8thEd_Chap10_Prob04_AveNumOfLetters\n"
          " 5.   Gaddis_8thEd_Chap10_Prob06_VowelsAndConsonants\n"
          " 6.   Gaddis_8thEd_Chap12_Prob05_LineNumbers\n"
          " 7.   Gaddis_8thEd_Chap12_Prob06_StringSearch\n"
          " 8.   Gaddis_8thEd_Chap12_Prob07_SentenceFilter\n"
          " 9.   Gaddis_8thEd_Chap12_Prob08_ArrayFileFunctions\n"
          "10.   Gaddis_8thEd_Chap12_Prob11_CorporateSalesData\n\n"
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
    string input;
    string *ptr;
    int nChar;
    //Input Data
    cout<<"This program counts the number of characters in a string excluding "
          "whitespace.\n"
          "Input a string: ";
    getline(cin,input);
    //Process Data
    ptr=&input;
    nChar=length(ptr);
    //Output Data
    cout<<"The length of the string is "<<input.length()<<endl;
    cout<<"There are "<<nChar<<" characters in this string"<<endl;
    
    cout<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    //Variables
    string input;
    string *ptr;
    int nChar;
    //Input Data
    cout<<"This program reverses a string and outputs it.\n"
          "Input a string: ";
    getline(cin,input);
    //Process Data
    ptr=&input;
    //Output Data
    reverse(ptr);
    
    cout<<endl<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    //Variables
    string   input; //String input
    string    *ptr; //Pointer to string
    int   nWords=0; //Number of words
    
    //Input Data
    cout<<"This program counts the number of words in a string\nInput a string: ";
    getline(cin,input);
    
    //Process Data
    ptr=&input;
    nWords=count(ptr);
    
    //Output Data
    cout<<"Number of words: "<<nWords<<endl;
    
    cout<<endl<<endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
    //Variables
    string   input; //String input
    string    *ptr; //Pointer to string
    int   nWords=0; //Number of words
    float aveLtr=0; //Ave number of letters in each word
    
    //Input Data
    cout<<"This program counts the number of words in a string and displays the "
          "average number of letters in each word.\nInput a string: ";
    getline(cin,input);
    
    //Process Data
    ptr=&input;
    count(ptr,nWords,aveLtr);
    
    //Output Data
    cout<<"Number of words: "<<nWords<<endl;
    cout<<"Average number of letters in each word: "<<aveLtr<<endl;
    
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    //Variables
    char choice;
    string input;
    int nVowel, nCons; //Number of vowels and consonants in string
    //Input Data
    cout<<"Input a string: ";
    getline(cin,input);
    do{
        cout<<"Select an option:\n"
              "1) Count the number of vowels in the string\n"
              "2) Count the number of consonants in the string\n"
              "3) Count both vowels and consonants in the string\n"
              "4) Input another string\n\n"
              "0) Exit\n";
        cin>>choice;
    //Process Data
        count(input,nVowel,nCons);
    //Output Data
            switch (choice){
            case '1': 
                cout<<"There are "<<nVowel<<" vowels in the string"<<endl;
                break;
            case '2':
                cout<<"There are "<<nCons<<" consonants in the string"<<endl;
                break;
            case '3':
                cout<<"There are "<<nVowel<<" vowels and\n"
                      "There are "<<nCons<<" consonants in the string"<<endl;
                break;
            case '4':
                cout<<"Input a string: ";
                cin.ignore();
                getline(cin,input);
                nVowel=0;nCons=0;
                break;
        }
    }while(choice>48&&choice<53);
    
    cout<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    //Variables
    string text; //Name of file
    fstream file;
    
    //Input Data
    cout<<"Input 'text1.txt' to open a file of the same name: \n";
    cin>>text;
    //Process Data
    file.open(text.c_str(),ios::in);
    if(file.fail()){
        cout<<text<<" does not exist."<<endl;
        return;
    }
    else cout<<text<<" opening success."<<endl;
    
    //Output Data
    read(file);
    file.close();
    
    cout<<endl<<endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    
    //Variables
    string text; //Name of file
    fstream file;
    
    //Input Data
    cout<<"Input 'text1.txt' to open a file of the same name: \n";
    cin>>text;
    //Process Data
    file.open(text.c_str(),ios::in);
    if(file.fail()){
        cout<<text<<" does not exist."<<endl;
        return;
    }
    else cout<<text<<" opening success."<<endl;
    
    //Output Data
    read2(file);
    //Search Data
    cout<<"Input a string(case-sensitive) to search for: ";
    cin.ignore();
    getline(cin,text);
    find(file,text);
    //Close File
    file.close();
    
    cout<<endl<<endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    
    //Variables
    fstream inOld; //In old file
    fstream inNew; //In new file
    fstream out;   //Write new file
    //Input Data
    inOld.open("sentences.txt",ios::in);
    read3(inOld);
    //Process Data
    inOld.open("sentences.txt",ios::in);
    out.open("revised.txt",ios::out);
    lower(inOld,out);
    //Output Data
    inNew.open("revised.txt",ios::in);
    read3(inNew);
    
    cout<<endl<<endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    
    //Variables
    fstream writeF;
    fstream readF;
    const int SIZE=10;
    int array[SIZE]={1,2,3,4,5,6,7,8,9,10}; //Int array
    int *ptr=array; //Pointer to int array
    int *newPtr= new int[SIZE]; //New array to read in binary content
    
    //Output Data to file
    arrToFile(writeF,ptr,SIZE);
    
    //Input Data from file
    fileToArr(readF,newPtr,SIZE);
    
    //Output Data
    cout<<"Old int array written to binary file:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<*(ptr+i)<<",";
    }
    cout<<endl<<"New int array read from binary file:"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<newPtr[i]<<",";
    }
    
    delete[] newPtr;
    
    cout<<endl<<endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    
    //Variables
    SaleDat array[QUARTER];      //Array of Sales Data structure
    
    //Input Data
    getSales(array,QUARTER);
    
    //Process Data
    
    //Output Data
    display(array,QUARTER);
    write(array,QUARTER);
    
    cout<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

int length(string *a){
    //Variables
    int count=0;
    //Process Data
    for(int i=0;i<(*a).length();i++){
        if(isalnum((*a)[i])){
            count++;
        }
    }
    //Output Data
    return count;
}

void reverse(string *a){
    //Output Data
    for(int i=(*a).length();i>0;i--){
        cout<<(*a)[i-1];
    }
    cout<<endl;
}

int count(string *ptr){
    //Variables
    string word;
    int counter=1;
    //Process Data
    
    for(int i=0,j=1;i<(*ptr).length();i++,j++){ //Go through each character
        if((*ptr)[i]==' '){       //If there is a space then new word
            counter++;
        }
    }
    return counter;
}

void count(string *ptr,int &nW,float &aL){
    //Variables
    string word;
    int counter=1;
    //Process Data
    
    for(int i=0,j=1;i<(*ptr).length();i++,j++){ //Go through each character
        if(i==(*ptr).length()-1){ //If last character in string
            aL+=j;                //Add j to ave number of letters
        }
        if((*ptr)[i]==' '){       //If there is a space then new word
            counter++;
            aL+=--j;
            j=0;
        }
    }
    nW=counter;
    aL/=nW;
}

void count(string input,int &nVowel,int &nCons){
    //Variables
    nVowel=0;
    nCons=0;
    //Process Data
    for(int i=0;i<input.length();i++){
        if(isalpha(input[i])){ //If letter
            if(isupper(input[i])){ //If uppercase
                tolower(input[i]); //To lowercase
                if(input[i]=='a'||input[i]=='e'||input[i]=='i'||
                   input[i]=='o'||input[i]=='u')nVowel++;
                else nCons++;
                toupper(input[i]); //Go back to upper
            }else{
                if(input[i]=='a'||input[i]=='e'||input[i]=='i'||
                   input[i]=='o'||input[i]=='u')nVowel++;
                else nCons++;
            }
        }
    }
}

void read(fstream &file){
    //Variables
    string line;
    string temp;
    //Output Data
    cin.ignore();
    do{
        int count=0;
        while(!file.eof()&&count<24){
            count++;
            cout<<count<<":";
            getline(file,line);
            cout<<line<<endl;
        }
        cout<<endl<<"Input anything to continue";
        cin.get();
        cout<<endl<<endl<<endl;
    }while(!file.eof());
}

void read2(fstream &file){
    //Variables
    string line;
    string temp;
    int count=0;
    //Output Data
    while(!file.eof()){
        count++;
        cout<<count<<":";
        getline(file,line);
        cout<<line<<endl;
    }
    cout<<endl<<endl<<endl;
}

void find(fstream &file,string a){
    //Variables
    vector<int> vArray; //Array of lines where string is found
    string line;
    int *count, //Array of occurences
           n=0; //Number of occurences
    //Input Data
    file.clear();           //Clear eof flag
    file.seekg(0L,ios::beg);//Go back to beginning
    cout<<"Searching for '"<<a<<"'..."<<endl<<endl;
    //Process Data
    for(int i=0;(!file.eof());i++){
        bool found=false;
        getline(file,line);
        if(line.find(a)!=string::npos){ //Check if line string is in a string
            found=true;
            n++;
        }
        if(found==true){
            vArray.push_back(i);
        }
    }
    //Output Data
    cout<<"'"<<a<<"' found in "<<n<<" lines"<<endl;
    if(vArray.size()==0) return;
    else{
        int temp=0, //temp index counter
               i=0; //index
        file.clear();           //Clear eof flag
        file.seekg(0L,ios::beg);//Go back to beginning
        while(!file.eof()&&temp<vArray.size()){
            getline(file,line);
            if(vArray[temp]==i){
                cout<<i+1<<":"<<line<<endl;
                temp++;
            }
            i++;
        }
    }
}

void read3(fstream &in){
    //Variables
    string line;
    //Output Data
    if(in.fail()){
        cout<<"File Opening Error"<<endl;
        in.close();
        return;
    }else while(!in.eof()){
        getline(in,line,'.');
        cout<<line<<endl;
    }
    //Close File
    in.close();
}

void lower(fstream &in,fstream &out){
    //Variables
    string line;
    //Check for Errors
    if(in.fail()){
        cout<<"File Opening Error"<<endl;
        in.close();
        return;
    }
    //Input Data
    while(!in.eof()){
        getline(in,line,'.');
    //Output Data
        for(int i=0;i<(line.length());i++){
            if(i==0){
                if(islower(line[i])){
                    line[i]=toupper(line[i]);
                }
            }else{
                if(isupper(line[i])){
                    line[i]=tolower(line[i]);
                }
            }
        }
        out<<line<<".";
    }
    //Close Files
    in.close();
    out.close();
}

void arrToFile(fstream &out,int *a,int n){
    //Open File
    out.open("binary.dat",ios::out|ios::binary);
    //Output Data
    for(int i=0;i<n;i++){
        out.write(reinterpret_cast<char *>(a+i),sizeof(*(a+i)));
    }
    //Close File
    out.close();
}

void fileToArr(fstream &in,int *a,int n){
    in.open("binary.dat",ios::in|ios::binary);
    if(in.fail()){
        cout<<"File opening failed"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        in.read(reinterpret_cast<char *>(a+i),sizeof(*(a+i)));
    }
    in.close();
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
            switch (i){
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

void write(const SaleDat *a,int n){
    //Variables
    fstream out;
    //Open files
    out.open("sales.dat",ios::out);
    //Output Data to file
    for(int i=0;i<n;i++){
        out<<"Division: ";
        switch (a[i].divName){
            case  0:out<<"East\n";break;
            case  1:out<<"West\n";break;
            case  2:out<<"North\n";break;
            default:out<<"South\n";break;
        }
        for(int j=0;j<n;j++){
            switch (i){
                case  0:out<<"First ";break;
                case  1:out<<"Second ";break;
                case  2:out<<"Third ";break;
                default:out<<"Fourth ";break;
            }
            out<<"Quarter Sales: $";
            out<<fixed<<showpoint<<setprecision(2)<<a[i].sales[j]<<endl;
        }
        out<<"Total Annual Sales: $";
        out<<fixed<<showpoint<<setprecision(2)<<a[i].totSale<<endl;
        out<<"Average Quarterly Sales: $";
        out<<fixed<<showpoint<<setprecision(2)<<a[i].aveSale<<endl<<endl;
    }
    //Close files
    out.close();
    cout<<"Results written to sales.dat"<<endl;
}