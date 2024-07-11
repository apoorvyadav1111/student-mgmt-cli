#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H

#include "student.h"
#include "database.h"
#include <vector>
using namespace std;

class StudentManagementSystem{
private:
    Database db;
    vector<Student> students;

public:
    StudentManagementSystem();
    ~StudentManagementSystem();
    bool addStudent(Student student);
    void displayAllStudents();
    Student* fetchStudent(int id);
    void fetchAllStudents();
    bool updateStudent(Student* student);
};

#endif