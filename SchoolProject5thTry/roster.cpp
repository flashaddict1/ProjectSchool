#include <iostream>
#include <string>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"
using namespace std;

//Function for Roster container
Roster::Roster()
{
    this->studentIndex = -1;
    this->numStudents = -1;
    this->classRosterArray = nullptr;
}

//Function for Roster container
Roster::Roster(int numStudents) 
{
    this->numStudents = numStudents;
    this->studentIndex = -1; 
    this->classRosterArray = new Student * [numStudents];
}

//Function for parsing through Students
void Roster::parseAndAdd(string data) 
{
    if (studentIndex < numStudents) 
    {
        this->studentIndex++;
        DegreeProgram degree{};

        int lpos = 0;
        int rpos = 0;

        rpos = data.find(",");
        string studentID = data.substr(lpos, rpos);

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string firstName = data.substr(lpos, (rpos - lpos));

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string lastName = data.substr(lpos, (rpos - lpos));

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string emailAddress = data.substr(lpos, (rpos - lpos));

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        int age = stoi(data.substr(lpos, (rpos - lpos)));

        int daysInCourse[3] = { 0,0,0 };
        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        daysInCourse[0] = stoi(data.substr(lpos, (rpos - lpos)));

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        daysInCourse[1] = stoi(data.substr(lpos, (rpos - lpos)));

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        daysInCourse[2] = stoi(data.substr(lpos, (rpos - lpos)));

        lpos = rpos + 1;
        rpos = data.find(",", lpos);
        string selectedDegree = data.substr(lpos, (rpos - lpos));

        //Selects the degree to parse for Student
        if (selectedDegree == "NETWORK") 
        {
            degree = DegreeProgram::NETWORK;
        }
        else if (selectedDegree == "SOFTWARE") 
        {
            degree = DegreeProgram::SOFTWARE;
        }
        else if (selectedDegree == "SECURITY") 
        {
            degree = DegreeProgram::SECURITY;
        }
        //Adds info parsed
        Roster::add(studentID, firstName, lastName, emailAddress, age, daysInCourse[0], daysInCourse[1], daysInCourse[2], degree);
    }
}

//Fuction for adding Student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) 
{
    int daysToArray[Student::countCourseDays];
    daysToArray[0] = daysInCourse1;
    daysToArray[1] = daysInCourse2;
    daysToArray[2] = daysInCourse3;

    if (degreeProgram == DegreeProgram::NETWORK) 
    {
        classRosterArray[studentIndex] = new studentNetwork(studentID, firstName, lastName, emailAddress, age, daysToArray, degreeProgram);
    }
    else if (degreeProgram == DegreeProgram::SOFTWARE) 
    {
        classRosterArray[studentIndex] = new studentSoftware(studentID, firstName, lastName, emailAddress, age, daysToArray, degreeProgram);
    }
    else if (degreeProgram == DegreeProgram::SECURITY) 
    {
        classRosterArray[studentIndex] = new studentSecurity(studentID, firstName, lastName, emailAddress, age, daysToArray, degreeProgram);
    }
}

//Fuction for deleting Student
void Roster::remove(string studentID) 
{
    cout << "Removing " << studentID << ": " << endl;

    for (int i = 0; i < numStudents; i++) 
    {
        if (classRosterArray[i]->getStudentID() == studentID) 
        {
            delete this->classRosterArray[i];
            this->studentIndex--;

            for (int j = i; j <= this->studentIndex; j++) 
            {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            return;
        }
    }

    cout << "Student with the ID: " << studentID << " was not found." << endl;
}

//Function for printing all Students
void Roster::printAll() 
{
    for (int i = 0; i <= studentIndex; i++) 
    {
        (this->classRosterArray)[i]->print();
    }
    cout << endl;
}

//Function for printing Average Days in Course
void Roster::printAverageDaysInCourse(string studentID) 
{
    for (int i = 0; i <= studentIndex; i++) 
    {
        if (this->classRosterArray[i]->getStudentID() == studentID) 
        {
            cout << "Student " << this->classRosterArray[i]->getStudentID() << ": " << this->classRosterArray[i]->getFirstName() << " " << this->classRosterArray[i]->getLastName() << ", averages ";
            classRosterArray[i]->getDaysToComplete();
        }
    }
}

//Function for printing Invalid Emails
void Roster::printInvalidEmails() 
{
    cout << "Displaying invalid emails:" << endl;

    for (int i = 0; i <= studentIndex; i++) 
    {
        string invEmailCheck = classRosterArray[i]->getEmailAddress();

        if (invEmailCheck.find('@') == string::npos) 
        {
            cout << invEmailCheck << "\t - Missing @ symbol" << endl;
            continue;
        }
        else if (invEmailCheck.find('.') == string::npos) 
        {
            cout << invEmailCheck << "\t - Missing a period" << endl;
            continue;
        }
        else if (invEmailCheck.find(' ') != string::npos) 
        {
            cout << invEmailCheck << "\t - No Spaces allowed" << endl;
            continue;
        }

    }
    cout << endl;
}

//Function for printing Student being retrieved
string Roster::getStudentAt(int studentIndex) 
{
    return this->classRosterArray[studentIndex]->getStudentID();
}

//Function for printing Students by Degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) 
{
    cout << "Showing students in degree program: ";

    if (degreeProgram == DegreeProgram::SECURITY) 
    {
        cout << "SECURITY" << endl;
    }
    if (degreeProgram == DegreeProgram::NETWORK) 
    {
        cout << "NETWORK" << endl;
    }
    if (degreeProgram == DegreeProgram::SOFTWARE) 
    {
        cout << "SOFTWARE" << endl;
    }

    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->print();
        }
    }
}

//Function for Roster deconstructor
Roster::~Roster() {
}