// This class models a student at a university.

#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<iostream>

using namespace std;
enum class year{FRESHMAN, SOPHOMORE, JUNIOR, SENIOR, GRADUATE};

class Student {
	protected:
		int id;
		string name;
		double gpa;
		year y;

	public:
		Student(int id, string name, double gpa, year y);
		int getID() const;
		string getName() const;
		double getGPA() const;
		year getYear() const;
		void setID(int id);
		void setName(string name);
		void setGPA(double gpa);
		void setYear(year y);

		// Overload the << operator
		friend ostream& operator<< (ostream& out, const Student& s) {
			out << s.id << "," << s.name << "," << s.gpa << ",";
			switch(s.y) {
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
				default:
					break;
			}
			return out;
		}
};

// Constructor
Student::Student(int id, string name, double gpa, year y):
								 id(id), name(name), gpa(gpa), y(y) {
}

int Student::getID() const {
	return(id);
}

#endif //STUDENT_H
