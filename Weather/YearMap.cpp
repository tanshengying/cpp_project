#include "YearMap.h"

YearMap::YearMap()
{
    m_year = 0;
}

void YearMap::SetYear(int year)
{
    m_year = year;
}

int YearMap::GetYear() const
{
    return m_year;
}

void YearMap::SetDataMap(DataMap &dataMap)
{
    m_dataMap = dataMap;
}

void YearMap::GetDataMap(DataMap &dataMap)
{
    dataMap = m_dataMap;
}

bool YearMap::operator == (const YearMap &yearMap)
{
    if(m_year == yearMap.GetYear())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool YearMap::operator < (const YearMap &yearMap)
{
    if(m_year < yearMap.GetYear())
    {
        return true;
    }
    else
    {
        return false;
    }
}
