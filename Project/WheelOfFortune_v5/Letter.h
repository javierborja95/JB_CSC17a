/* File:   Letter.h
 * Author: Javier B
 * Created on December 5, 2016, 6:08 PM
 * Purpose: Class Specification File for Letter class
 */

#ifndef LETTER_H
#define LETTER_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries

class Letter{
    protected:
        char letter;
        bool isUsed;
        static int calls;
    public:
        Letter(char a){
            letter=a;
            isUsed=false;
            calls++;
        }
        Letter(){
            letter=' ';
            isUsed=false;
            calls++;
        }
        //Mutators
        void setChar(char a)
        {char a=letter;}
        void use()
        {isUsed=true;}
        
        //Accessors
        bool isUsed(){return isUsed;}
        static int calls(){return calls;}
        virtual void display();
};

#endif /* LETTER_H */

