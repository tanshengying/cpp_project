#ifndef YEARMAP_H_INCLUDED
#define YEARMAP_H_INCLUDED
#include "WindLogType.h"
#include <map>

typedef map <string, WindLogType> DataMap;      //store dateTimeString as key and WindLogType as data
using namespace std;

class YearMap
{
public:
    YearMap();
    void SetYear(int year);
    int GetYear() const;
    void SetDataMap(DataMap &dataMap);
    void GetDataMap(DataMap &dataMap);

    bool operator == (const YearMap &yearMap);
    bool operator < (const YearMap &yearMap);

private:
    int m_year;
    DataMap m_dataMap;
};

#endif // YEARMAP_H_INCLUDED
