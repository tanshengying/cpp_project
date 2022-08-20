#include "Bst.h"
#include <iostream>
#include <fstream>

using namespace std;

typedef struct Student
{
    int id;
    int age;

    bool operator < (const Student &student)
    {
        if(id < student.id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator == (const Student &student)
    {
        if(id == student.id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

ostream & operator << (ostream &os, const Student &S)
{
    os << S.id << ","
       << S.age << "  ";

    return os;
}

BST<Student> studentTree;


int main()
{
    Student student1;
    student1.id = 1234;
    student1.age = 10;

    Student student2;
    student2.id = 2234;
    student2.age = 20;

    Student student3;
    student3.id = 1334;
    student3.age = 30;

    Student student4;
    student4.id = 1244;
    student4.age = 40;


    studentTree.ProcessInsert(student1);
    studentTree.ProcessInsert(student2);
    studentTree.ProcessInsert(student3);
    studentTree.ProcessInsert(student4);

    studentTree.ProcessNode(Print);
    cout << endl << endl;


    cout << "Replace student age" << endl;
    student2.age = 30;
    studentTree.ProcessReplace(student2);

    Student tempStudent;
    tempStudent.id = 1334;
    tempStudent.age = 60;
    studentTree.ProcessReplace(tempStudent);

    studentTree.ProcessNode(Print);

}
