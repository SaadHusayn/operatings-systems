#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

// Forward declarations
class Student;
class Teacher;

using namespace std;

class Course {
private:
    string name;
    vector<Student*> students;
    vector<Teacher*> teachers;
public:
    Course(string name);
    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);
    string getName();
    vector<Student*>& getStudents();
    vector<Teacher*>& getTeachers();
};

#endif

