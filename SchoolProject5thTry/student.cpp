#include <iostream>
#include <string>
#include "Student.h"
#include "Degree.h"
using namespace std;

//Function for Student container
Student::Student() 
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";

    for (int i = 0; i < countCourseDays; i++) {
        this->daysInCourse[i] = 0;
    }
}

//Function for Student container
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[]) 
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;

    for (int i = 0; i < countCourseDays; i++) 
    {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

//Function for setting StudentID
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

//Function for setting FirstName
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

//Function for setting LastName
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

//Function for setting EmailAddress
void Student::setEmailAddress(string email) {
    this->emailAddress = email;
}

//Function for setting Age
void Student::setAge(int age) {
    this->age = age;
}

//Function for setting Days in Course
void Student::setDaysToComplete(int daysInCourse[]) {
    for (int i = 0; i < countCourseDays; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

//Function for getting StudentID
string Student::getStudentID() const {
    return this->studentID;
}

//Function for getting FirstName
string Student::getFirstName() const {
    return this->firstName;
}

//Function for getting LastName
string Student::getLastName() const {
    return this->lastName;
}

//Function for getting EmailAddress
string Student::getEmailAddress() const {
    return this->emailAddress;
}

//Function for getting Age
int Student::getAge() const {
    return this->age;
}

//Function for getting Days in Course
void Student::getDaysToComplete() const { 
    int avg = 0;

    for (int i = 0; i < this->countCourseDays; i++) {
        avg += static_cast<double>(daysInCourse[i]);
    }

    avg = round(avg / this->countCourseDays);
    cout << avg << " days in a course." << endl;
}

//Function for printing Student Data
void Student::printStudentData() {
    cout << this->studentID  << "\t" << "First Name: " 
         << this->firstName  << "\t" << "Last Name: " 
         << this->lastName   << "\t" << "Age: " 
         << this->age        << "\t" << "DaysInCourse: {" 
         << this->daysInCourse[0] << ", " 
         << this->daysInCourse[1] << ", " 
         << this->daysInCourse[2] << "}" 
         << " Degree: ";
}

//Function for container student with Security Degree
studentSecurity::studentSecurity() :Student() {
    degreeProgram = DegreeProgram::SECURITY;
}

//Function for container student with Security Degree
studentSecurity::studentSecurity(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
    : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse) {
    degreeProgram = DegreeProgram::SECURITY;
}

//Function for getting student with Security Degree
DegreeProgram studentSecurity::getDegreeProgram() {
    return DegreeProgram::SECURITY;
}

//Function for printing student with Security Degree
void studentSecurity::print() {
    this->Student::printStudentData();
    cout << "SECURITY" << endl;
}

//Fuction for deconstructor for student with Security Degree
studentSecurity::~studentSecurity() {
    Student::~Student();
}

//Function for container student with Network Degree
studentNetwork::studentNetwork() :Student() {
    degreeProgram = DegreeProgram::NETWORK;
}

//Function for container student with Network Degree
studentNetwork::studentNetwork(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
    : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse) {
    degreeProgram = DegreeProgram::NETWORK;
}

//Function for getting student with Network Degree
DegreeProgram studentNetwork::getDegreeProgram() {
    return DegreeProgram::NETWORK;
}

//Function for printing student with Network Degree
void studentNetwork::print() {
    this->Student::printStudentData();
    cout << "NETWORK" << endl;
}

//Fuction for deconstructor for student with Network Degree
studentNetwork::~studentNetwork() {
    Student::~Student();
}

//Function for container student with Software Degree
studentSoftware::studentSoftware() :Student() {
    degreeProgram = DegreeProgram::SOFTWARE;
}

//Function for container student with Software Degree
studentSoftware::studentSoftware(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
    : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse) {
    degreeProgram = DegreeProgram::SOFTWARE;
}

//Function for getting student with Software Degree
DegreeProgram studentSoftware::getDegreeProgram() {
    return DegreeProgram::SOFTWARE;
}

//Function for printing student with Software Degree
void studentSoftware::print() {
    this->Student::printStudentData();
    cout << "SOFTWARE" << endl;
}

//Fuction for deconstructor for student with Software Degree
studentSoftware::~studentSoftware() {
    Student::~Student();
}

Student::~Student() {
}