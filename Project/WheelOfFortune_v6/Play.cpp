/* File:   Play.h
 * Author: Javier B
 * Created on December 5, 2016, 8:56 PM
 * Purpose: Class Implementation File for play class
 */

//User Libraries
#include "Play.h"

void Play::play(Game *a){
    //Variables
    win=false;
    int index=(rand()%a->counter); //Index to choose clue
    cout<<"index = "<<index<<endl;
    cout<<"counter = "<<a->counter<<endl;
    unsigned int c; //Temp char
    char   s[SIZE]; //Temp string
    cout<<a->getName()<<" is now playing test test test"<<endl<<endl;
    
    //Input Data
    a->in.seekg(a->arr[index],ios::beg); //Go to position in file to get phrase and clue
    a->in.get();
    a->in>>c;
    cout<<"c = "<<c<<endl;
    a->in.getline(s,SIZE,'.');
    cout<<"s = "<<s<<endl;
    clue.setCat(c);
    clue.setPhrase(s);
    
    //Create a phrase
    //Phrase *p = new Phrase(c,s);
    Phrase p(strlen(s),s);
    p.display();
}

void Play::spin(){
    
}

void Play::buy(){
    
}

void Play::guess(){
    
}

void Play::display(){
    //Output Data
    clue.showCat();
    //p->display();
    k.display();
}

void Play::menu(Game *a){
    //Output Data
    display();
    cout<<"Your money = $"<<a->getMoney()*10<<".00"<<endl;
    cout<<endl<<endl<<"What would you like to do?"<<endl;
    cout<<  " 1. Spin the Wheel ✪\n"
    " 2. Buy a vowel ($500.00)\n"
    " 3. Solve the Puzzle ✉(Bad guess lose $300.00)\n"<<endl;
}