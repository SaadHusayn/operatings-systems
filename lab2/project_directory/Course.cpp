#include "Course.h"
#include "Student.h"  // Include Student and Teacher headers to avoid any issues with methods
#include "Teacher.h"

Course::Course(string _name) : name(_name) {}

void Course::addStudent(Student* student) {
    students.push_back(student);
}

void Course::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}

string Course::getName() {
    return name;
}

vector<Student*>& Course::getStudents() {
    return students;
}

vector<Teacher*>& Course::getTeachers() {
    return teachers;
}

