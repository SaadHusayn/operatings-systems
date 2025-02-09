#include <iostream>
using namespace std;

#include "Course.h"
#include "Student.h"
#include "Teacher.h"

int main() {
    // Create instances
    Student s1("Alice");
    Student s2("Bob");
    Teacher t1("Professor Smith");
    Teacher t2("Professor Johnson");
    Course c1("Mathematics");
    Course c2("Physics");

    // Add students and teachers to courses
    c1.addStudent(&s1);
    c1.addTeacher(&t1);
    c2.addStudent(&s2);
    c2.addTeacher(&t2);

    // Display students in the course
    cout << "Students Enrolled in " << c1.getName() << ":\n";
    for (auto student : c1.getStudents()) {
        cout << student->getName() << endl;  // Access the student's name
    }

    // Display teachers teaching the course
    cout << "Teachers Teaching " << c1.getName() << ":\n";
    for (auto teacher : c1.getTeachers()) {
        cout << teacher->getName() << endl;  // Access the teacher's name
    }
    
    // Display students in the course
    cout << "Students Enrolled in " << c2.getName() << ":\n";
    for (auto student : c2.getStudents()) {
        cout << student->getName() << endl;  // Access the student's name
    }

    // Display teachers teaching the course
    cout << "Teachers Teaching " << c2.getName() << ":\n";
    for (auto teacher : c2.getTeachers()) {
        cout << teacher->getName() << endl;  // Access the teacher's name
    }

    return 0;
}

