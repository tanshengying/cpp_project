#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

/**
 * @class Date file
 * @brief  Manages all Dates object
 *
 * Date class contain methods to get the date, month and year of
 * the dates. .
 *
 * @author Tan Sheng Ying
 * @version 01
 * @date 21/06/2022, Started
 *
 * @bug My program currently has no bugs...
 */


class Date
{
public:
    /**
    * @brief Default Constructor
    *
    * Set day, month and year to 0
    *
    * @param none
    */
    Date();

    /**
    * @brief Constructor that take a string date
    *
    * Set day, month and year
    *
    * @param date
    */
    Date(string date);

    /**
    * @brief Constructor that take a int day, int month and int year for date
    *
    * Set day, month and year
    *
    * @param day, month, year
    */
    Date(int day, int month, int year);

    /**
    * @brief Setter for m_day
    *
    * Set the day
    *
    * @param day
    * @return void
    */
    void SetDay(int day);

    /**
    * @brief Getter for m_day
    *
    * Return the day
    *
    * @param none
    * @return m_day
    */
    int GetDay() const;

    /**
    * @brief Setter for m_month
    *
    * Set the month
    *
    * @param month
    * @return void
    */
    void SetMonth(int month);

    /**
    * @brief Getter for m_month
    *
    * Return the month
    *
    * @param none
    * @return m_month
    */
    int GetMonth() const;

    /**
    * @brief Setter for m_year
    *
    * Set the year
    *
    * @param year
    * @return void
    */
    void SetYear(int year);

    /**
    * @brief Getter for m_year
    *
    * Return the year
    *
    * @param none
    * @return m_year
    */
    int GetYear() const;

    /**
    * @brief Operator overloading <
    *
    * Overload the operator < so that Dates can be checked which
    * date is bigger or smaller than the other.
    *
    * @param &date - A reference to the Date object
    * @return bool
    */
    bool operator < (const Date &date);

    /**
    * @brief Operating overloading ==
    *
    * Overload the operator == so that Dates can be checked if
    * they are equal to one another.
    *
    * @param none
    * @return bool
    */
    bool operator == (const Date &date);


private:
    /** Private variable, day*/
    int m_day;

    /** Private variable, month*/
    int m_month;

    /** Private variable, year*/
    int m_year;



};

ostream & operator <<( ostream& os, const Date& D );
istream & operator >>( istream& input, Date& D );

#endif // DATE_H_INCLUDED
