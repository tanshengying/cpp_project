#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"

int main()
{

    cout << "Test ID 1" << endl;
    Date date1;
    cout << date1 << endl << endl;

    cout << "Test ID 2" << endl;
    Date date2("1/7/2022");
    cout << date2 << endl << endl;

    cout << "Test ID 3" << endl;
    Date date3(5,10,2021);
    cout << date3 << endl << endl;

    cout << "Test ID 4 & 5" << endl;
    date3.SetDay(8);
    cout << date3.GetDay() << endl << endl;

    cout << "Test ID 6 & 7" << endl;
    date3.SetMonth(9);
    cout << date3.GetMonth() << endl << endl;

    cout << "Test ID 8 & 9" << endl;
    date3.SetYear(1997);
    cout << date3.GetYear() << endl << endl;

}
