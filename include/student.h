#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student{
public:
    int id;
    string name;
    int age;

    Student(int id,const string& name, int age);

    void display() const;

    void edit(const string& newName, int newAge);
};

#endif