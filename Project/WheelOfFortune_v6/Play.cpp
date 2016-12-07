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
    unsigned int c; //Temp char
    char   s[SIZE]; //Temp string
    
    //Input Data
    a->in.seekg(a->arr[index],ios::beg); //Go to position in file to get phrase and clue
    a->in.get();
    a->in>>c;
    a->in.getline(s,SIZE,'.');
    clue.setCat(c);
    clue.setPhrase(s);
    
    //Create a new Phrase
    Phrase *p = new Phrase;
    p->setArr(strlen(s),s);
    
    //Copy Phrase to pointer
    this->p=p;
}

void Play::spin(){
    
}

void Play::buy(){
    
}

void Play::guess(Game *a){
    //Variables
    string answer; //Player answer
    int counter=0; //Amount of empty letters in keyboard array
    int score=30;  //Points=score*counter
    bool win=true;
    
    //Input Data
    display();
    cout<<"Input the final answer: ";
    getline(cin,answer);
    
    //Process Data
    for(int i=0;i<clue.getSize();i++){ //Convert to uppercase
        answer[i]=static_cast<char>(toupper(answer[i]));
    }
    for(int i=0;i<clue.getSize();i++){
        cout<<p->getLetter(i);
        if((p->getLetter(i))!=(answer[i])){//Check to see if all letters match
            win=false;                 //Phrase did not match answer
        }
        if(i==clue.getSize()-1)cout<<"size= "<<clue.getSize()<<endl;
    }
    cout<<endl;
    for(int i=0;i<clue.getSize();i++){ //Go through phrase array to add
        if((p->getUsed(i))==false){     //points for each letter that is not used
            counter++;
        }
    }
    
    //Output Data
    if(win==true){
        score*=counter;
        cout<<"You gain 30 points for each hidden letter you guessed"<<endl;
        cout<<"You gain "<<score<<" points"<<endl;
        a->addScore(score);
        this->win=win;                 //Make private member win=local win;
    }else{
        cout<<"You did not guess correctly. You have lost $300.00\n";
        a->subMoney(30);
    }
}

void Play::display(){
    //Output Data
    clue.showCat();
    p->display();
    k.display();
    cout<<endl;
}

void Play::menu(Game *a){
    //Output Data
    cout<<"Your money = $"<<a->getMoney()*10<<".00"<<endl;
    cout<<endl<<endl<<"What would you like to do?"<<endl;
    cout<<  " 1. Spin the Wheel ✪\n"
    " 2. Buy a vowel ($500.00)\n"
    " 3. Solve the Puzzle ✉(Bad guess lose $300.00)\n"<<endl;
}