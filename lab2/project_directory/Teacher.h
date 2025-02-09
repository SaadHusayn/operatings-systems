#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Course.h"  // Include Course to define relationship between Teacher and Course

using namespace std;

class Course;  // Forward declare Course

class Teacher {
private:
    string name;
    vector<Course*> teachingCourses;
public:
    Teacher(const string& name);
    void teachCourse(Course* course);
    string getName();
    vector<Course*> getTeachingCourses();
};

#endif

