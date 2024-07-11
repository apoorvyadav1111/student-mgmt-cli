#include "student.h"
#include <iostream>
using namespace std;

Student::Student(int id, const string &name, int age):id(id), name(name), age(age)
{

}

void Student::display() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age << std::endl;
}

void Student::edit(const std::string &newName, int newAge) {
    name = newName;
    age = newAge;
}