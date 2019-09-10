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
		 * @param employee_id Employee ID.
		 * @param pay Employee pay.
		 * @return None
		 */
		Employee(string first_name, string last_name, long employee_id, double pay=0.0);

		/**
		 * @brief Return Employee name.
		 * @param void
		 * @return Employee name
		 */
		string get_name(void) const;

		/**
		 * @brief Return Employee id.
		 * @param void
		 * @return Employee id
		 */
		long get_id(void) const;

		/**
		 * @brief Return Employee pay.
		 * @param void
		 * @return Employee pay
		 */
		double get_pay(void) const;

		void set_name(const string first_name, const string last_name);

		void set_pay(const double pay);

		virtual void apply_raise(void) = 0;

	private:
		string first_name;
		string last_name;
		long employee_id;
		double pay;
};

Employee::Employee(string first_name, string last_name, long employee_id, double pay):
									 first_name(first_name), last_name(last_name), employee_id(employee_id), pay(pay) {
}

string Employee::get_name(void) const {
	return(first_name + " " + last_name);
}

long Employee::get_id(void) const {
	return(employee_id);
}

double Employee::get_pay(void) const {
	return(pay);
}

void Employee::set_name(const string first_name, const string last_name) {
	this->first_name = first_name;
	this->last_name = last_name;
}

void Employee::set_pay(const double pay) {
	this->pay = pay;
}

#endif //EMPLOYEE_H
