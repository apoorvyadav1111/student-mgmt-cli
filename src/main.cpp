#include "student_management_system.h"
#include "student.h"
#include <iostream>

using namespace std;

int main() {
    StudentManagementSystem sms;
    int choice;
    cout<<"--------------------------------------------"<<endl;
    cout<<"        Student Management System           "<<endl;
    cout<<"--------------------------------------------"<<endl;
    do {
        cout<<endl<<endl;
        std::cout << "1. Add Student" << std::endl;
        cout<<"2. Find Student" <<endl;
        std::cout << "3. Display Students" << std::endl;
        std::cout << "4. Update Student" << std::endl;
        std::cout << "100. Exit" << std::endl;
        cout<<endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        cout<<endl;

        switch (choice) {
            case 1: {
                int id, age;
                std::string name;
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter Age: ";
                std::cin >> age;
                Student student(id,name,age);
                if (sms.addStudent(student)) {
                    std::cout << "Student added successfully\n";
                } else {
                    std::cout << "Failed to add student\n";
                }
                break;
            }
            case 2:{
                int id;
                cout<<"Enter ID:";
                cin>>id;
                Student* student =sms.fetchStudent(id);
                if (student == nullptr)
                {
                    cout<<"Student Not Found"<<endl;
                    break;
                }
                student->display();
                break;
            }
            case 3:
            {
                sms.fetchAllStudents();
                sms.displayAllStudents();
                break;
            }
            case 4:
            {
                int newAge = 0;
                int id;
                string newName = "";
                cout<<"Enter student id for update:";
                cin>>id;
                Student* updateStudent = sms.fetchStudent(id);
                if (updateStudent == nullptr){
                    cout<<"Student Not Found"<<endl;
                    break;
                }
                cout<<"Editing Student :"<<endl<<endl;
                cout<<"Name: "<< updateStudent->name<<endl;
                cout<<"Enter new name to update or s_k_i_p to skip"<<endl;
                cin>>newName;
                if (newName == "s_k_i_p"){
                    newName = updateStudent->name;
                }
                cout<<"Age: "<<updateStudent->age<<endl;
                cout<<"Enter new age to update or 0 to skip"<<endl;
                cin>>newAge;
                if(newAge == 0)
                {
                    newAge = updateStudent->age;
                }
                updateStudent->edit(newName, newAge);
                sms.updateStudent(updateStudent);
                break;
            }
            case 100:
            {
                std::cout << "Exiting...\n";
                break;
            }
            default:
            {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 100);

    return 0;
}
