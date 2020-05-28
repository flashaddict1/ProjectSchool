#pragma once
#include <string>
#include "Degree.h"
using namespace std;

class Student
{
public:
    const static int numStudents = 5;                 //Sets number of Students
    const static int countCourseDays = 3;             //The amount of courses
    int removed = 0;                                  //Sets removed to false

    Student();                                        //Student container
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]);
    ~Student();                                       //Student deconstructor

    string studentID = "";
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    int age = 0;
    int daysInCourse[countCourseDays];
    DegreeProgram degreeProgram;

    void setStudentID(string studentID);              //Start of mutators
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string email);
    void setAge(int age);
    void setDaysToComplete(int daysInCourse[]);
    void printStudentData();                          //End of mutators

    string getStudentID() const;                      //Start of accessors
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    void getDaysToComplete() const;
    virtual DegreeProgram getDegreeProgram() = 0;     //End of accessors
    virtual void print() {}; 
};

class studentSecurity : public Student                //Class for student with Security Degree
{
public:
    studentSecurity();
    studentSecurity(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
    ~studentSecurity();

    DegreeProgram getDegreeProgram();
    void print();
};

class studentNetwork : public Student                //Class for student with Network Degree 
{
public:
    studentNetwork();
    studentNetwork(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
    ~studentNetwork();

    DegreeProgram getDegreeProgram();
    void print();
};

class studentSoftware : public Student                //Class for student with Software Degree 
{
public:
    studentSoftware();
    studentSoftware(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
    ~studentSoftware();

    DegreeProgram getDegreeProgram();
    void print();
};