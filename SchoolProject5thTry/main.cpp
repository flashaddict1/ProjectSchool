#include <iostream>
#include <vector>
#include <string>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"
using namespace std;

int main()
{
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Sam,Gonzales,sgon230@wgu.edu,30,35,30,32,SOFTWARE"
    };

    cout << "WGU C867 Scripting and Programming " << endl;
    cout << "Programming Language: C++          " << endl;
    cout << "        Student Name: Sam Gonzales " << endl;
    cout << "          Student ID: 001097078    " << endl << endl;

    //Number of Students
    int numStudents = 5;

    Roster* classRoster = new Roster(numStudents);
    for (int i = 0; i < numStudents; i++) 
    {
        classRoster->parseAndAdd(studentData[i]);
    }

    //Prints all Students
    cout << "Displaying all Students:" << endl;
    classRoster->printAll();

    //Prints Invalid Email
    classRoster->printInvalidEmails();

    //Prints all Students Avg Days to complete Course
    cout << "Average Days to complete course: " << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i));
    }
    cout << endl;

    //Prints all Students with Software Degree
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    //Deletes Student with ID 'A3'
    classRoster->remove("A3");
    //Reprints All Students
    classRoster->printAll();
    cout << endl;

    //Attempts to delete Student with ID 'A3' once again
    classRoster->remove("A3");

    //ClassRoster Deconstructor
    classRoster->~Roster();

    return 0;
}