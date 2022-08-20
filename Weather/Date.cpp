#include "Date.h"

//Default Constructor
Date::Date()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

//Non default constructor
Date::Date(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

Date::Date(string date)
{
    string tempDay, tempMonth, tempYear;

    stringstream ss(date);
    getline(ss, tempDay, '/');
    getline(ss, tempMonth, '/');
    getline(ss, tempYear);



    m_day = stoi(tempDay);
    m_month = stoi(tempMonth);
    m_year = stoi(tempYear);
}

void Date::SetDay(int day)
{
    m_day = day;
}

int Date::GetDay() const
{
    return m_day;
}

void Date::SetMonth(int month)
{
    m_month = month;
}

int Date::GetMonth() const
{
    return m_month;
}

void Date::SetYear(int year)
{
    m_year = year;
}

int Date::GetYear() const
{
    return m_year;
}


istream & operator >>( istream& input, Date& D )
{
    string tempDate, tempMonth, tempYear;
    getline(input, tempDate, '/');
    getline(input, tempMonth, '/');
    getline(input, tempYear, '\n');

    D.SetDay(stoi(tempDate));
    D.SetMonth(stoi(tempMonth));
    D.SetYear(stoi(tempYear));


    return input;
}

ostream & operator <<( ostream & os, const Date& D )
{
    os << D.GetDay()   << "/"
       << D.GetMonth() << "/"
       << D.GetYear();
    return os;
}

bool Date::operator < (const Date &date)
{
    if ((m_year < date.m_year) ||
            (m_year == date.m_year && m_month < date.m_month) ||
            (m_year == date.m_year && m_month == date.m_month && m_day < date.m_day))
        return true;
    else
        return false;
}

bool Date::operator == (const Date &date)
{
    if ((m_year == date.m_year) &&
            (m_month == date.m_month) &&
            (m_day == date.m_day))
        return true;
    else
        return false;
}
