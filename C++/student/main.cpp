// main.cpp

#include "Student.h"
#include "GradStudent.h"

int main(int argc, char** argv) {
	Student s1(2042, "Joe Smith", 3.49, year::FRESHMAN);
	GradStudent gs1(1455, "Linda Smith", 3.63, year::GRADUATE, support::TA,
									"CSE", "Performance Analysis of AI Workloads");

	cout << s1 << endl;
	cout << gs1 << endl;

	return(0);
}
