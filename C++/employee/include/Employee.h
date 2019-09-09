/**
 * @file Employee.h
 * @brief This file implements the Employee class.
 * @author Nawab Ali
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>
#include<iostream>

using namespace std;

/**
 * @class Employee
 * @brief This class implements Employee record.
 */
class Employee {
	public:
		/**
		 * @brief Constructor for the Employee class.
		 * @param first_name Employee first name.
		 * @param last_name Employee last name.
		 * @return None
		 */
		Employee(string first_name, string last_name, long employee_id, double pay=0.0);

	private:
		string first_name;
		string last_name;
		long employee_id;
		double pay;
};

#endif //EMPLOYEE_H
