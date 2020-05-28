#pragma once
#include <iostream>
#include <string>
#include "Degree.h"
#include "Student.h"
using namespace std;

class Roster {
private:
    int studentIndex;
    int numStudents;
    Student** classRosterArray;

public:
    Roster();                                                     //Roster Container
    Roster(int numStudents);                                      //Roster Container
    ~Roster();                                                    //Roster Deconstructor

    string getStudentAt(int studentIndex);                        //Retrieves a Student
    void parseAndAdd(string data);                                //Parses through string provided
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);                                //Deletes a Student
    void printAll();                                              //Prints the list of Students
    void printAverageDaysInCourse(string studentID);              //Prints avg days in all courses
    void printInvalidEmails();                                    //Prints email if they contain a space or don't have a '@' or '.'
    void printByDegreeProgram(DegreeProgram degreeProgram);       //Prints Students by Degree
};