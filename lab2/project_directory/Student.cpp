#include "Student.h"

Student::Student(const string& _name) : name(_name) {}

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
}

string Student::getName() {
    return name;
}

vector<Course*> Student::getEnrolledCourses() {
    return enrolledCourses;
}

