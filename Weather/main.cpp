#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <utility>

#include "WindLogType.h"
#include "YearMap.h"
#include "Bst.h"


using namespace std;

const int MAX_FACTORS = 17;  // Assuming first position factors is 0.
const int NO_OF_MONTHS = 12; // No of months in a year
const string MONTHS[12] = {"Jan","Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

typedef map <string, WindLogType> DataMap;      //store dateTimeString as key and WindLogType as data
DataMap::iterator itr;
DataMap::const_iterator cItr;

bool ReadFile(string filePath, int counter, BST<YearMap> &yearTree);
void GetLocation(int &locationOne, int &locationTwo, int &locationThree, int &locationFour, string fileName);
int GetUserInput(int input);
void OptionOne(BST<YearMap> &yearTree);
void OptionTwo(BST<YearMap> &yearTree);
void OptionThree(BST<YearMap> &yearTree);
void OptionFour(BST<YearMap> &yearTree);
void OptionFive(BST<YearMap> &yearTree);
void ErrorDefaultMessage();

int main()
{
    BST<YearMap> yearTree;
    BST<string> fileBST;

    ifstream infile;
    string fileList;
    string fileName;
    string filePath;
    int counter = 0;
    int counterTwo = 0;
    int input = 0;
    bool fileFound = false;


    fileList = "../data/met_index.txt";

    infile.open(fileList);

    while (getline(infile, fileName))
    {
        if(fileName.empty())
        {
            getline(infile, fileName, '\n');
        }

        if (fileBST.ProcessSearch(fileName))
        {
            cout << "Duplicate File" << endl;
        }
        else
        {
            filePath = "../data/" + fileName;
            cout << filePath << endl;
            ReadFile(filePath, counter, yearTree);
            fileFound = true;
            fileBST.ProcessInsert(fileName);
        }
    }

    if (fileFound == true)
    {
        cout << "All Data Stored" << endl<<endl;
    }
    else
    {
        cout << "File does not exist" << endl;
        return -1;
    }


    do
    {
        input = GetUserInput(input);
        switch(input)
        {
        case 1:
            OptionOne(yearTree);
            break;
        case 2:
            OptionTwo(yearTree);
            break;
        case 3:
            OptionThree(yearTree);
            break;
        case 4:
            OptionFour(yearTree);
            break;
        case 5:
            OptionFive(yearTree);
            break;
        case 6:
            cout << "You have enter the exit Button" << endl;
            break;
        default:
            ErrorDefaultMessage();
        }
    }
    while (input != 6);

    cout << "System is shutting down, thank you" << endl;

    infile.close();
}


bool ReadFile(string filePath, int counter, BST<YearMap> &yearTree)
{
    ifstream infile;
    infile.open(filePath);

    if (!infile)
    {
        cout << "File Not Found" << endl;
        cout << filePath << endl;
        return -1;
    }

    string tempLine;
    string tempLineTwo;
    string dateTimeString;
    string tempDay = " ";
    string tempMonth = " ";
    string tempYear = " ";
    string tempHours = " ";
    string tempMins = " ";
    int locationOne, locationTwo, locationThree, locationFour;


    int day = 0;
    int month = 0;
    int year = 0;
    int hours = 0;
    int mins = 0;
    int yearOfData = 0;
    float speed = 0;
    float solarRadiation = 0;
    float airTemp = 0;

    DataMap dataMap;
    YearMap yearMap;

    DataMap dataMapTwo;         //This is use when the data is different year
    YearMap yearMapTwo;         //This is use when the data is different year
    int differentYear = 0;

    GetLocation(locationOne,locationTwo, locationThree, locationFour, filePath); //Get location of required factors
    getline (infile, tempLine); //skip the first line

    while(getline(infile, tempLine))
    {
        if (tempLine.empty())
        {
        }
        else
        {
            stringstream ss(tempLine);
            for (int i = 0; i < MAX_FACTORS; i++)
            {
                getline(ss, tempLineTwo, ',');          //Per Column
                if (i == locationOne)
                {
                    dateTimeString = tempLineTwo;
                    stringstream sss(tempLineTwo);

                    getline(sss, tempDay, '/');
                    getline(sss, tempMonth, '/');
                    getline(sss, tempYear, ' ');

                    day = stoi(tempDay);
                    month = stoi(tempMonth);
                    year = stoi(tempYear);

                    getline(sss, tempHours, ':');
                    getline(sss, tempMins, ',');
                    hours = stoi(tempHours);
                    mins = stoi(tempMins);
                }

                else if (i == locationTwo)
                {
                    if(tempLineTwo != "N/A")
                    {
                        speed = stof(tempLineTwo);
                    }
                    else
                    {
                        speed = -1;
                    }
                }
                else if (i == locationThree)
                {
                    if(tempLineTwo != "N/A")
                    {
                        solarRadiation = stof(tempLineTwo);
                    }
                    else
                    {
                        solarRadiation = -1;
                    }
                }
                else if (i == locationFour)
                {
                    getline(ss, tempLineTwo);
                    if(tempLineTwo != "N/A")
                    {
                        airTemp = stof(tempLineTwo);
                    }
                    else
                    {
                        airTemp = -1;
                    }
                }

                if (!tempLine.empty() && yearOfData == 0)
                {
                    yearOfData = year;
                }
            }
        }

        Date date(day, month, year);
        Time time(hours, mins);
        WindLogType W(date, time, speed, solarRadiation, airTemp);

        if (year == yearOfData && speed != -1 && solarRadiation != -1 && airTemp != -1)
        {
            dataMap.insert(pair<string, WindLogType>(dateTimeString, W));
        }
        else if (year != yearOfData && speed != -1 && solarRadiation != -1 && airTemp != -1)
        {
            if(differentYear == 0)
            {
                differentYear = year;
            }
            dataMapTwo.insert(pair<string, WindLogType>(dateTimeString, W));
        }
    }

    yearMap.SetYear(yearOfData);
    if(yearTree.ProcessSearch(yearMap))
    {
        DataMap tempDataMap;
        yearMap.GetDataMap(tempDataMap);

        tempDataMap.insert(dataMap.begin(), dataMap.end());
        yearMap.SetDataMap(tempDataMap);
        yearTree.ProcessReplace(yearMap);
    }
    else
    {
        yearMap.SetDataMap(dataMap);
        yearTree.ProcessInsert(yearMap);
    }


    yearMapTwo.SetYear(differentYear);
    if(yearTree.ProcessSearch(yearMapTwo))
    {
        DataMap tempDataMap;
        yearMapTwo.GetDataMap(tempDataMap);

        tempDataMap.insert(dataMapTwo.begin(), dataMapTwo.end());
        yearMapTwo.SetDataMap(tempDataMap);
        yearTree.ProcessReplace(yearMapTwo);
    }
    else
    {
        yearMapTwo.SetDataMap(dataMapTwo);
        yearTree.ProcessInsert(yearMapTwo);
    }

    for(itr = dataMap.begin(); itr != dataMap.end(); ++itr)
    {
        counter++;
    }


    cout << yearOfData << " File: ";
    cout << counter << endl;

    counter = 0;
    infile.close();

}

void GetLocation(int &locationOne, int &locationTwo, int &locationThree, int &locationFour, string filePath)
{
    ifstream infile;
    infile.open(filePath);

    string tempLine;


    for (int i = 0; i < MAX_FACTORS; i++)
    {
        getline(infile, tempLine,',');
        if (tempLine == "WAST")
        {
            locationOne = i;
        }
        else if (tempLine == "S")
        {
            locationTwo = i;
        }
        else if (tempLine == "SR")
        {
            locationThree = i;
        }
        else if (tempLine == "Sx") // this is needed to find the last variable which is T
        {
            locationFour = i;
        }
    }
    infile.close();
}

int GetUserInput(int input)
{
    cout << "==================================================" << endl;
    cout << "Welcome to the Menu Option" << endl;
    cout << "Choose one option to continue, and Press 6 to exit" << endl;
    cout << "==================================================" << endl;
    cout << "Option 1: Average wind speed & average ambient air temperature for a specified month and year."  << endl;
    cout << "Option 2: Average wind speed & average ambient air temperature for each month of a specified year." << endl;
    cout << "Option 3: Total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "Option 4: Average wind speed (km/h), average ambient air temperature & total solar radiation in kWh/m2 \n" ;
    cout << "for each month of a specified year " << endl;
    cout << "Option 5: Highest Solar Radiation for that Date" << endl;
    cout << "==================================================" << endl;
    cout << "Your option: ";
    cin >> input;

    return input;
}

void OptionOne(BST<YearMap> &yearTree)
{
    int month = 0;
    int year = 0;
    int counter = 0;
    float totalSpeed = 0;
    float totalAirTemp = 0;
    float averageSpeed = 0;
    float averageAirTemp = 0;
    bool isFound = false;

    cout << "Please enter the month: ";
    cin >> month;

    cout << "Please enter the year: ";
    cin >> year;

    YearMap tempYearMap;
    tempYearMap.SetYear(year);
    //tempYearMap.year = year;

    if (yearTree.ProcessSearch(tempYearMap))
    {
        DataMap tempMap;
//        tempMap = tempYearMap.dataMap;
        tempYearMap.GetDataMap(tempMap);

        Date tempDate;
        for(itr = tempMap.begin(); itr != tempMap.end(); ++itr)
        {
            itr->second.GetDate(tempDate);
            if(tempDate.GetMonth() == month && tempDate.GetYear() == year)
            {
                counter++;
                totalSpeed += itr->second.GetSpeed();
                totalAirTemp += itr->second.GetAirTemp();
                isFound = true;
            }
        }
    }

    averageSpeed = totalSpeed / counter;
    averageAirTemp = totalAirTemp / counter;

    if (isFound != true)
    {
        cout << MONTHS[month - 1] << " " << year << ": No Data" << endl;
    }
    else
    {
        cout << MONTHS[month - 1] << " " << year << ": ";
        cout << fixed << setprecision(2) << averageSpeed << " km/h ";
        cout << fixed << setprecision(2) << averageAirTemp << " degrees C" << endl;
    }
}

void OptionTwo(BST<YearMap> &yearTree)
{
    int year = 0;
    int targetMonth = 0;
    int counterArr[NO_OF_MONTHS] = {0};
    float totalSpeedArr[NO_OF_MONTHS] = {0};
    float totalAirTempArr[NO_OF_MONTHS] = {0};

    cout << "Please enter the year: ";
    cin >> year;

    YearMap tempYearMap;
    tempYearMap.SetYear(year);

    if (yearTree.ProcessSearch(tempYearMap))
    {
        DataMap tempMap;
        //tempMap = tempYearMap.dataMap;
        tempYearMap.GetDataMap(tempMap);

        Date tempDate;
        for(itr = tempMap.begin(); itr != tempMap.end(); ++itr)
        {
            itr->second.GetDate(tempDate);
            if(tempDate.GetYear() == year)
            {
                targetMonth = tempDate.GetMonth();
                counterArr[targetMonth - 1] += 1;
                totalSpeedArr[targetMonth - 1] += itr->second.GetSpeed();
                totalAirTempArr[targetMonth - 1] += itr->second.GetAirTemp();
            }
        }
    }

    for (int i = 0; i < NO_OF_MONTHS; i++)
    {
        if (totalSpeedArr[i] != 0 && totalAirTempArr[i] != 0)
        {
            cout << MONTHS[i] << ":\t" << fixed << setprecision(2) << totalSpeedArr[i]/counterArr[i] << " Km/h"
                 << ", " << fixed << setprecision(2) << totalAirTempArr[i]/counterArr[i] << " degrees C " << endl;
        }
        else
        {
            cout << MONTHS[i] << ":\t" << "No Data" << endl;
        }
    }


}

void OptionThree(BST<YearMap> &yearTree)
{
    int year = 0;
    int targetMonth = 0;
    float minSolarRadiation = (100.0/6) / 1000;
    float totalSolarRadiationArr[NO_OF_MONTHS] = {0};

    cout << "Please enter the year: ";
    cin >> year;

    YearMap tempYearMap;
//    tempYearMap.year = year;
    tempYearMap.SetYear(year);

    if (yearTree.ProcessSearch(tempYearMap))
    {
        DataMap tempMap;
        //tempMap = tempYearMap.dataMap;
        tempYearMap.GetDataMap(tempMap);

        Date tempDate;
        for(itr = tempMap.begin(); itr != tempMap.end(); ++itr)
        {
            itr->second.GetDate(tempDate);
            if(tempDate.GetYear() == year && itr->second.GetSolarRadiation() >= minSolarRadiation)
            {
                targetMonth = tempDate.GetMonth();
                totalSolarRadiationArr[targetMonth - 1] += itr->second.GetSolarRadiation();
            }
        }
    }

    cout << year << endl;

    for (int i = 0; i < NO_OF_MONTHS; i++)
    {
        if (totalSolarRadiationArr[i] != 0)
        {
            cout << MONTHS[i] << ":\t"
                 << fixed << setprecision(2) << totalSolarRadiationArr[i] << " kWh/m2" <<  endl;
        }
        else
        {
            cout << MONTHS[i] << ":\t" << "No Data" << endl;
        }
    }
}

void OptionFour(BST<YearMap> &yearTree)
{
    int year = 0;
    int targetMonth = 0;
    int counterArr[NO_OF_MONTHS] = {0};
    float totalSpeedArr[NO_OF_MONTHS] = {0};
    float totalAirTempArr[NO_OF_MONTHS] = {0};
    float minSolarRadiation = (100.0/6) / 1000;
    float totalSolarRadiationArr[NO_OF_MONTHS] = {0};
    bool dataFound = false;

    cout << "Please enter the year: ";
    cin >> year;

    YearMap tempYearMap;
//    tempYearMap.year = year;
    tempYearMap.SetYear(year);

    if (yearTree.ProcessSearch(tempYearMap))
    {
        DataMap tempMap;
//        tempMap = tempYearMap.dataMap;
        tempYearMap.GetDataMap(tempMap);

        Date tempDate;
        for(itr = tempMap.begin(); itr != tempMap.end(); ++itr)
        {
            itr->second.GetDate(tempDate);
            if(tempDate.GetYear() == year && itr->second.GetSolarRadiation() >= minSolarRadiation)
            {
                targetMonth = tempDate.GetMonth();
                counterArr[targetMonth - 1] += 1;
                totalSpeedArr[targetMonth - 1] += itr->second.GetSpeed();
                totalAirTempArr[targetMonth - 1] += itr->second.GetAirTemp();
                totalSolarRadiationArr[targetMonth - 1] += itr->second.GetSolarRadiation();
            }
        }
    }

    ofstream ofile("WindTempSolar.csv");

    ofile << year << endl;

    for (int i = 0; i < NO_OF_MONTHS; i++)
    {
        if(totalSpeedArr[i] != 0 && totalAirTempArr[i] != 0
                && totalSolarRadiationArr[i] != 0)
        {
            ofile << MONTHS[i] << "," << fixed << setprecision(2) << totalSpeedArr[i]/counterArr[i] << ","
                  << fixed << setprecision(2) << totalAirTempArr[i]/counterArr[i] << ","
                  << fixed << setprecision(2) << totalSolarRadiationArr[i] << endl;
            dataFound = true;
        }
    }

    if (dataFound == false)
    {
        ofile << "No Data" << endl;
    }

    cout << "========== File is created ==========" << endl;


}

void OptionFive(BST<YearMap> &yearTree)
{
    string dateInput;
    int counter = 0;
    float largestSolarRadiation = 0;
    bool dataFound = false;

    cout << "Enter the date(In the format, d/m/yyyy): ";
    cin.ignore();
    getline(cin, dateInput);
    cout << endl;

    Date date(dateInput);
    DataMap tempMap;
    Date tempDate;
    Time tempTime;

    YearMap tempYearMap;
    tempYearMap.SetYear(date.GetYear());

    if (yearTree.ProcessSearch(tempYearMap))
    {
        //tempMap = tempYearMap.dataMap;
        tempYearMap.GetDataMap(tempMap);
        dataFound = true;

        for(itr = tempMap.begin(); itr != tempMap.end(); ++itr)
        {
            itr->second.GetDate(tempDate);
            if(tempDate == date && itr->second.GetSolarRadiation() > largestSolarRadiation )
            {
                largestSolarRadiation = itr->second.GetSolarRadiation();
            }
        }
    }

    if(dataFound == true)
    {
        cout << "Date: " << date << endl;
        cout << "Highest Solar Radiation for the day: " << largestSolarRadiation * 6000 << " W/m2" << endl;
        cout << "Time:" << endl;
        for(itr = tempMap.begin(); itr != tempMap.end(); ++itr)
        {
            itr->second.GetDate(tempDate);
            if( tempDate == date && itr->second.GetSolarRadiation() == largestSolarRadiation)
            {
                itr->second.GetTime(tempTime);
                cout << tempTime << endl;
            }
        }
    }
    else
    {
        cout << "No Data Found" << endl;
    }
}

void ErrorDefaultMessage()
{
    cout << "Error input, Please try Again" << endl;
    cout << "==================================================" << endl;
}
