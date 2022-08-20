#include "Time.h"

Time::Time()
{
    m_hour = 0;
    m_mins = 0;
}

Time::Time(int hour, int mins)
{
    m_hour = hour;
    m_mins = mins;
}

void Time::SetHour(int hour)
{
    m_hour = hour;
}

void Time::SetMin(int mins)
{
    m_mins = mins;
}

//void Time::SetSec(int sec)
//{
//    m_sec = sec;
//}

int Time::GetHour() const
{
    return m_hour;
}

int Time::GetMin() const
{
    return m_mins;
}

//int Time::GetSec() const
//{
//    return m_sec;
//}


istream & operator >>( istream& input, Time& T )
{
    string tempString;

    getline (input, tempString, ':');
    T.SetHour(stoi(tempString));

    getline (input, tempString, ':');
    T.SetMin(stoi(tempString));

//    getline (input, tempString, ',');
//    T.SetSec(stoi(tempString));

    return input;
}

ostream & operator <<( ostream & os, const Time& T )
{

    os << T.GetHour() << ":" << T.GetMin();
    return os;
}

bool Time::operator<(const Time &time)
{
    if((m_hour < time.m_hour) ||
            (m_hour == time.m_hour && m_mins < time.m_mins))
        return true;
    else
        return false;
}
