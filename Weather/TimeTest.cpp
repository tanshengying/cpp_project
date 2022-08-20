#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    cout << "Test ID 10" << endl;
    Time time1;
    cout << time1 << endl <<  endl;

    cout << "Test ID 11" << endl;
    Time time2(14,48);
    cout << time2 << endl <<  endl;

    cout << "Test ID 12 & 13" << endl;
    time2.SetHour(4);
    cout << time2.GetHour() << endl <<  endl;

    cout << "Test ID 14 & 15" << endl;
    time2.SetMin(30);
    cout << time2.GetMin() << endl <<  endl;



}
