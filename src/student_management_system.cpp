#include "student_management_system.h"
#include "student.h"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;


void printStudent(MYSQL_ROW row){
    cout << "ID: " << row[0] << ", Name: " << row[1] << ", Age: " << row[2] << endl;
}

StudentManagementSystem::StudentManagementSystem(){
    if(!db.connect("localhost","student_db_app","password","student_db")){
        cout << "Error connecting to the database" << endl;
    }
}

StudentManagementSystem::~StudentManagementSystem(){
    // Close the database connection
}

bool StudentManagementSystem::addStudent(Student student){
    string query = "INSERT INTO STUDENTS(ID, NAME, AGE) VALUES("+to_string(student.id)+", '"+student.name+"', "+to_string(student.age)+")";
    return db.executeQuery(query);
}

bool StudentManagementSystem::updateStudent(Student* student){
    string query = "update students set name='"+student->name+"', age="+to_string(student->age)+" where id="+to_string(student->id);
    return db.executeQuery(query);
}

void StudentManagementSystem::displayAllStudents(){
    for(auto &student: students)
    {
        student.display();
    }
    cout<<endl;
}

void StudentManagementSystem::fetchAllStudents(){
    students.clear();
    MYSQL_RES *res = db.getQueryResult("SELECT * FROM STUDENTS");
    if(res == nullptr){
        cerr<<"Query Failed"<<endl;
        return;
    }
    MYSQL_ROW row;
    cout<<endl;
    while((row = mysql_fetch_row(res))){
        int id = stoi(row[0]);
        string name = row[1];
        int age = stoi(row[2]);
        students.emplace_back(id,name,age);
    }
    mysql_free_result(res);
}

Student* StudentManagementSystem::fetchStudent(int id){
    MYSQL_RES *res = db.getQueryResult("Select * from students where id="+to_string(id));
    if(res==nullptr){
        cerr<<"Student not found"<<endl;
        return nullptr;
    }
    MYSQL_ROW row;
    cout<<endl;
    while((row = mysql_fetch_row(res))){
        Student* student = new Student(stoi(row[0]),row[1],stoi(row[2]));
        mysql_free_result(res);
        return student;
    }
    return nullptr;
}

