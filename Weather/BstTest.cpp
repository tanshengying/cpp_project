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
    cout << "Test ID 28" << endl;               //Default constructor
    BST<int> intBST;
    intBST.ProcessNode(Print);
    cout << endl;

    cout << "Test ID 29 & 30" << endl;          //ProcessInsert & Insert
    string tempLine;
    fstream infile;
    infile.open("Data.txt");

    while (!infile.eof())
    {
        getline(infile, tempLine, ',');
        intBST.ProcessInsert(stoi(tempLine));
    }

    intBST.ProcessNode(Print);
    cout << endl;


    cout << "Test ID 31 & 32" << endl;          //ProcessSearch & Search

    int number = 100;
    if (intBST.ProcessSearch(number))
        cout << number << " Found" << endl;
    else
        cout << number << " Not Found" << endl;

    number = 25;
    if (intBST.ProcessSearch(number))
        cout << number << " Found" << endl;
    else
        cout << number << " Not Found" << endl;

    cout << endl;

    cout << "Test ID 33, 34, 35, 36" << endl;   //ProcessNode, InOrderTraversal, PreOrderTraversal, PostOrderTraversal
    intBST.ProcessNode(Print);




    return 0;
}
