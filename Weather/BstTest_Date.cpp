//Do it using recursive
//Insert, Delete tree, search
//inOrder, preOrder, postOrder

#include "Bst.h"
#include "Date.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    BST<Date> dateTree;
    string tempLine;
    fstream infile;
    infile.open("Data_Date.txt");

    while (!infile.eof())
    {
        getline(infile, tempLine);
        if (tempLine.empty())
        {
            getline(infile, tempLine);
        }
        dateTree.ProcessInsert(tempLine);

    }

    dateTree.ProcessNode(Print);
    cout << endl;

    string date = "14/4/2000";
    Date tempDate(date);

    if (dateTree.ProcessSearch(tempDate))
        cout << date << " Found" << endl;
    else
        cout << date << " Not Found" << endl;


    date = "14/4/2020";
    Date tempDate2(date);

    if (dateTree.ProcessSearch(tempDate2))
        cout << date << " Found" << endl;
    else
        cout << date << " Not Found" << endl;
}
