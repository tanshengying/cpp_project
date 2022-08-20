#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

using namespace std;

/**
 * @class Time file
 * @brief  Manages all Time object
 *
 * Time class contain methods to get the hour and mins of the time.
 *
 * @author Tan Sheng Ying
 * @version 01
 * @date 18/06/2022, Started
 *
 *@author Tan Sheng Ying
 *@version 02
 *@date 21/6/2022, Comment the secs since this project
 * is not required to stored the seconds.
 *
 * @bug My program currently has no bugs...
 */


class Time
{
public:
    /**
    * @brief Default Constructor
    *
    * Set hour and mins to 0.
    *
    * @param none
    */
    Time();

    /**
    * @brief Constructor that take a int hour and int mins
    *
    * Set hour and mins
    *
    * @param hour, mins
    */
    Time(int hour, int mins);

    /**
    * @brief Setter for m_hour
    *
    * Set the number of hour
    *
    * @param hour
    * @return void
    */
    void SetHour(int hour);

    /**
    * @brief Setter for m_mins
    *
    * Set the number of mins
    *
    * @param mins
    * @return void
    */
    void SetMin(int mins);


    //void SetSec(int secs);

    /**
    * @brief Getter for m_hour
    *
    * Return the hour
    *
    * @param none
    * @return m_hour
    */
    int GetHour() const;

    /**
    * @brief Getter for m_mins
    *
    * Return the mins
    *
    * @param none
    * @return m_mins
    */
    int GetMin() const;

    /**
    * @brief Operator overloading <
    *
    * Overload the operator < so that Time can be checked which
    * time is bigger or smaller than the other.
    *
    * @param &date - A reference to the Date object
    * @return bool
    */
    bool operator < (const Time &time);


    //int GetSec() const;

private:
    /** Private variable, hour*/
    int m_hour;

    /** Private variable, min*/
    int m_mins;

    //int m_sec;


};

ostream & operator <<( ostream & os, const Time & T );
istream & operator >>( istream & input, Time & T );

#endif // TIME_H_INCLUDED
