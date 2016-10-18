/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 17, 2016, 7:00 PM
 * Purpose: Counts number of vowels and consonants in a string
 */

//System Libraries
#include <iostream>  //Input/ Output Stream Library
#include <string>
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void count(string,int&,int&);
//Execution

int main(int argc, char** argv) {
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
    
    return 0;
}

void count(string input,int &nVowel,int &nCons){
    //Variables
    nVowel=0;
    nCons=0;
    //Process Data
        for(int i=0;i<input.length();i++){
        if(isalpha(input[i])){
            if(isupper(input[i])){
                tolower(input[i]);
                if(input[i]=='a'||input[i]=='e'||input[i]=='i'||
                   input[i]=='o'||input[i]=='u')nVowel++;
                else nCons++;
                toupper(input[i]);
            }else{
                if(input[i]=='a'||input[i]=='e'||input[i]=='i'||
                   input[i]=='o'||input[i]=='u')nVowel++;
                else nCons++;
            }
        }
    }
}