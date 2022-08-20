#include "WindLogType.h"

WindLogType::WindLogType()
{
    m_speed = 0;
    m_solarRadiation = 0;
    m_airTemp = 0;
}

WindLogType::WindLogType(Date date, Time time, float speed, float solarRadiation, float airTemp)
{
    m_date = date;
    m_time = time;
    m_speed = speed * 3.6;
    m_solarRadiation = ((solarRadiation/6.0) / 1000);
    m_airTemp = airTemp;
}

void WindLogType::SetDate(Date &date)
{
    m_date = date;
}

void WindLogType::GetDate(Date &date) const
{
    date = m_date;
}

void WindLogType::SetTime(Time &time)
{
    m_time = time;
}

void WindLogType::GetTime(Time &time) const
{
    time = m_time;
}

void WindLogType::SetSpeed(float speed)
{
    m_speed = speed * 3.6;
}

float WindLogType::GetSpeed() const
{
    return m_speed;
}

void WindLogType::SetSolarRadiation(float solarRadiation)
{
    m_solarRadiation = ((solarRadiation/6) / 1000);
}

float WindLogType::GetSolarRadiation() const
{
    return m_solarRadiation;
}

void WindLogType::SetAirTemp(float airTemp)
{
    m_airTemp = airTemp;
}

float WindLogType::GetAirTemp() const
{
    return m_airTemp;
}

ostream & operator <<( ostream& os, const WindLogType &W )
{
    Date tempDate;
    W.GetDate(tempDate);
    Time tempTime;
    W.GetTime(tempTime);

    os  << tempDate << " "
        << tempTime << ","
        << W.GetSpeed() << ","
        << W.GetSolarRadiation() << ","
        << W.GetAirTemp();

    return os;
}
