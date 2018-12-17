// This class models a graduate student at a university.

#ifndef GRAD_STUDENT_H
#define GRAD_STUDENT_H

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
		ostream& print(ostream& out) const;
};

// Constructor
GradStudent::GradStudent(long id, string name, double gpa, year y, support s,
												 string dept, string thesis):
												 Student(id, name, gpa, y),
												 s(s), dept(dept), thesis(thesis) {
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

#endif //GRAD_STUDENT_H
