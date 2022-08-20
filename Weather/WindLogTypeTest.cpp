#include <iostream>
#include <fstream>
#include <string>
#include "WindLogType.h"

int main()
{
    cout << "Test ID 16" << endl;
    WindLogType w1;
    cout << w1 << endl << endl;

    cout << "Test ID 17" << endl;
    Date date1(5,10,2021);
    Time time1(14,48);
    WindLogType w2(date1, time1, 12, 2400, 36);
    cout << w2 << endl << endl;

    cout << "Test ID 18 & 19" << endl;
    Date tempDate;
    Date date2("8/9/1997");
    w2.SetDate(date2);
    w2.GetDate(tempDate);
    cout << tempDate << endl << endl;

    cout << "Test ID 20 & 21" << endl;
    Time tempTime;
    Time time2(12,40);
    w2.SetTime(time2);
    w2.GetTime(tempTime);
    cout << tempTime << endl << endl;

    cout << "Test ID 22 & 23" << endl;
    w2.SetSpeed(24);
    cout << w2.GetSpeed() << endl << endl;

    cout << "Test ID 24 & 25" << endl;
    w2.SetSolarRadiation(4800);
    cout << w2.GetSolarRadiation() << endl << endl;

    cout << "Test ID 26 & 27" << endl;
    w2.SetAirTemp(48);
    cout << w2.GetAirTemp() << endl << endl;

}
