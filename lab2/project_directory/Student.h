#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h"  // Include Course to define relationship between Student and Course

using namespace std;

class Course;  // Forward declare Course

class Student {
private:
    string name;
    vector<Course*> enrolledCourses;
public:
    Student(const string& name);
    void enrollCourse(Course* course);
    string getName();
    vector<Course*> getEnrolledCourses();
};

#endif

