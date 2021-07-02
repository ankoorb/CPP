#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

class Student {
private:
    string name;
    int grade;
    float GPA;
    void validateGrade();
    void validateGPA();

public:
    Student(string name, int grade, float gpa);

    string getName() const;
    int getGrade() const;
    float getGPA() const;

    void setName(string name);
    void setGrade(int grade);
    void setGPA(float gpa);
};

int main() {

    Student student("Alpha", 11, 3.6);

    assert(student.getName() == "Alpha");
    assert(student.getGrade() == 11);
    assert(abs(student.getGPA() - 3.6) < 1);

    bool caught {false};
    try {
        Student invalid("Invalid", -4, 10);
    } catch (...){
        caught = true;
    }
    assert(caught);

    return 0;
}


Student::Student(string name, int grade, float gpa) {
    setName(name);
    setGrade(grade);
    setGPA(gpa);
}

void Student::setName(string name) { this->name = name; }

void Student::setGrade(int grade) {
    this->grade = grade;
    validateGrade();
}

void Student::setGPA(float gpa) {
    this->GPA = gpa;
    validateGPA();
}

string Student::getName() const {
    return name;
}

int Student::getGrade() const {
    return grade;
}

float Student::getGPA() const {
    return GPA;
}

void Student::validateGrade() {
    if (grade < 0 || grade > 12){
        throw invalid_argument("Grade must be in range [0, 12] inclusive!");
    }
}

void Student::validateGPA() {
    if (GPA < 0 || GPA > 4){
        throw invalid_argument("GPA must be in range [0, 4] inclusive!");
    }
}
