/* File:   time.h
 * Author: Javier B
 * Created on December 4, 2016, 9:24 PM
 * Purpose: Class Specification File for time class
 */

#ifndef TIME_H
#define TIME_H

//System Libraries
using namespace std; //Namespace of the System Libraries

//User Libraries

class Time{
    protected:
        int hour;
        int min;
        int sec;
    public:
        Time(){hour=0;min=0;sec=0;}
        Time(int h,int m,int s)
            {hour=h;min=m;sec=s;}
        int getHour() const
            {return hour;}
        int getMin() const
            {return min;}
        int getSec() const
            {return sec;}
};

#endif /* TIME_H */

