#include "Teacher.h"

Teacher::Teacher(const string& _name) : name(_name) {}

void Teacher::teachCourse(Course* course) {
    teachingCourses.push_back(course);
}

string Teacher::getName() {
    return name;
}

vector<Course*> Teacher::getTeachingCourses() {
    return teachingCourses;
}

