#include <iostream>
#include <string>
using namespace std;

struct Student{
    string id;
    string name;
    int age;
    string course;
    double gpa;
};

int main(){
    Student s[5];
    int count = 5;

    for (int i=0; i<count; i++){
        cout << "Student #" << i+1 << endl;
        cout << "Input your student ID: "; cin >> s[i].id;
        cout << "Input your name: "; cin >> s[i].name;
        cout << "Input your age: "; cin >> s[i].age;
        cout << "Input your course: "; cin >> s[i].course;
        cout << "Input your GPA: "; cin >> s[i].gpa;
        cout << endl;
    }

    for (int i=0; i<count; i++){
        cout << s[i].id << endl;
        cout << s[i].name << endl;
        cout << s[i].age << endl;
        cout << s[i].course << endl;
        cout << s[i].gpa << endl;
    }

    string id;
    cout << "Search student ID: "; cin >> id;
    bool found = false;

    for (int i=0; i<count; i++){
        if (s[i].id == id){
            cout << "Input your student ID: "; cin >> s[i].id;
            cout << "Input your name: "; cin >> s[i].name;
            cout << "Input your age: "; cin >> s[i].age;
            cout << "Input your course: "; cin >> s[i].course;
            cout << "Input your GPA: "; cin >> s[i].gpa;

            int option;

            cout << "1. Update student ID" << endl;
            cout << "2. Update studnet name" << endl;
            cout << "3. Update studnet age" << endl;
            cout << "4. Update studnet course" << endl;
            cout << "5. Update studnet GPA" << endl;
            cout << "Enter option: " << "\n" << endl;

            switch(option){
                case 1: cout << "New student ID: "; cin >> s[i].id; break;
                case 2: cout << "New student name: "; cin >> s[i].name; break;
                case 3: cout << "New student age: "; cin >> s[i].age; break;
                case 4: cout << "New student course: "; cin >> s[i].course; break;
                case 5: cout << "New student GPA: "; cin >> s[i].gpa; break;
                default: cout << "Invalid option." << endl; break;
            }

            cout << "Student information successfully updated" << endl;
            found = true;
        }
        if (found == true) break;   
    }

    return 0;
};