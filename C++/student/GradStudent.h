// This class models a graduate student at a university.

#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include "Student.h"

enum class support{TA, RA, FELLOW, OTHER};

class GradStudent: public Student {
	protected:
		support s;
		string dept;
		string thesis;

	public:
		GradStudent(long id, string name, double gpa, year y, support s,
								string dept, string thesis);
		support get_support(void) const;
		string get_dept(void) const;
		string get_thesis(void) const;
		void set_support(const support s);
		void set_dept(const string dept);
		void set_thesis(const string thesis);
		ostream& print(ostream& out) const;
};

// Constructor
GradStudent::GradStudent(long id, string name, double gpa, year y, support s,
												 string dept, string thesis):
												 Student(id, name, gpa, y),
												 s(s), dept(dept), thesis(thesis) {
}

support GradStudent::get_support(void) const {
	return(s);
}

string GradStudent::get_dept(void) const {
	return(dept);
}

string GradStudent::get_thesis(void) const {
	return(thesis);
}

void GradStudent::set_support(const support s) {
	this->s = s;
}

void GradStudent::set_dept(const string dept) {
	this->dept = dept;
}

void GradStudent::set_thesis(const string thesis) {
	this->thesis = thesis;
}

// Print the member variables
ostream& GradStudent::print(ostream& out) const {
	Student::print(out);
	out << ",";

	switch(s) {
		case support::TA:
			out << "TA";
			break;
		case support::RA:
			out << "RA";
			break;
		case support::FELLOW:
			out << "Fellow";
			break;
		case support::OTHER:
			out << "Other";
			break;
		default:
			break;
	}

	out << "," << dept << "," << thesis;
	return(out);
}

#endif //GRADSTUDENT_H
