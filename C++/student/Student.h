// This class models a student at a university.

#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<iostream>

using namespace std;
enum class year{FRESHMAN, SOPHOMORE, JUNIOR, SENIOR, GRADUATE};

class Student {
	protected:
		long id;
		string name;
		double gpa;
		year y;

	public:
		Student(long id, string name, double gpa, year y);
		int get_id(void) const;
		string get_name(void) const;
		double get_gpa(void) const;
		year get_year(void) const;
		void set_id(const long id);
		void set_name(const string name);
		void set_gpa(const double gpa);
		void set_year(const year y);
		virtual ostream& print(ostream& out) const;

		// Overload the << operator
		friend ostream& operator<< (ostream& out, const Student& s) {
			return(s.print(out));
		}
};

// Constructor
Student::Student(long id, string name, double gpa, year y):
								 id(id), name(name), gpa(gpa), y(y) {
}

int Student::get_id(void) const {
	return(id);
}

// Print the member variables
ostream& Student::print(ostream& out) const {
	out << id << "," << name << "," << gpa << ",";
	switch(y) {
		case year::FRESHMAN:
			out << "Freshman";
			break;
		case year::SOPHOMORE:
			out << "Sophomore";
			break;
		case year::JUNIOR:
			out << "Junior";
			break;
		case year::SENIOR:
			out << "Senior";
			break;
		case year::GRADUATE:
			out << "Graduate";
			break;
		default:
			break;
	}
	return(out);
}

#endif //STUDENT_H
