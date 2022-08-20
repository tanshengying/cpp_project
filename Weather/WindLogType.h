#ifndef WINDLOGTYPE_H_INCLUDED
#define WINDLOGTYPE_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"  // your Date class from a previous lab
#include "Time.h"  // your Time class from this lab

using namespace std;

/**
	 * @class WindLogType file
	 * @brief  Manages all WindLogType object
	 *
	 * WindLogType class contain methods to get and set the
	 * date, time, speed, solarRadiation and airTemp.
	 *
	 * @author Tan Sheng Ying
	 * @version 01
	 * @date 23/07/2022, Started
	 *
	 * @bug My program currently has no bugs...
	 */

class WindLogType
{
public:
    /**
    * @brief Default Constructor
    *
    * Set speed, solarRadiation and airTemp to 0.
    *
    * @param none
    */
    WindLogType();

    /**
    * @brief Constructor that takes a Date object, Time object, speed, solarRadiation and airTemp.
    *
    * Set Date, Time, speed, solarRadiation and airTemp
    *
    * @param Date - Date object
    * @param Time - Time object
    * @param speed - speed of the data
    * @param solarRadiation - solarRadiation of the data
    * @param airTemp - airTemp of the data
    */
    WindLogType(Date date, Time time, float speed, float solarRadiation, float airTemp);

    /**
    * @brief Setter for m_date
    *
    * Set date
    *
    * @param &date - A reference to a Date object
    */
    void SetDate(Date &date);

    /**
    * @brief Getter for m_date
    *
    * Get date
    *
    * @param &date - A reference to a Date object
    */
    void GetDate(Date &date) const;

    /**
    * @brief Setter for m_time
    *
    * Set time
    *
    * @param &time - A reference to a Time object
    */
    void SetTime(Time &time);

    /**
    * @brief Getter for m_time
    *
    * Get time
    *
    * @param &time - A reference to a Time object
    */
    void GetTime(Time &time) const;

    /**
    * @brief Setter for m_speed
    *
    * Set the speed
    *
    * @param speed
    * @return void
    */
    void SetSpeed(float speed);

    /**
    * @brief Getter for m_speed
    *
    * Get the speed
    *
    * @param void
    * @return float
    */
    float GetSpeed() const;

    /**
    * @brief Setter for m_solarRadiation
    *
    * Set the solarRadiation
    *
    * @param solarRadiation
    * @return void
    */
    void SetSolarRadiation (float solarRadiation);

    /**
    * @brief Getter for m_solarRadiation
    *
    * Get the solarRadiation
    *
    * @param void
    * @return float
    */
    float GetSolarRadiation () const;

    /**
    * @brief Setter for m_airTemp
    *
    * Set the airTemp
    *
    * @param airTemp
    * @return void
    */
    void SetAirTemp(float airTemp);

    /**
    * @brief Getter for m_airTemp
    *
    * Get the airTemp
    *
    * @param void
    * @return float
    */
    float GetAirTemp() const;


private:
    /** Private variable, Date object*/
    Date m_date;
    /** Private variable, Time object*/
    Time m_time;
    /** Private variable, Speed*/
    float m_speed;
    /** Private variable, Solar Radiation*/
    float m_solarRadiation;
    /** Private variable, Air Temperature*/
    float m_airTemp;
};

ostream & operator <<( ostream& os, const WindLogType &W );


#endif // WINDLOGTYPE_H_INCLUDED
