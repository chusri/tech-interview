#!/usr/bin/python3
#Object-Oriented Programming with Python

class Employee:
  num_emp = 0
  raise_amt = 1.04

  def __init__(self, fname, lname, pay):
    """ Employee class constructor """
    self.fname = fname
    self.lname = lname
    self.pay = pay
    self.email = Employee.emp_email(fname, lname)
    Employee.inc_num_emp()

  def print_emp_info(self):
    """ Print employee information """
    print(self.fname + ' ' + self.lname, self.pay, self.email)

  def apply_raise(self):
    """ Give employee a raise """
    self.pay = int(self.raise_amt * self.pay)

  @classmethod
  def inc_num_emp(cls):
    """ Increment number of employees """
    cls.num_emp += 1

  @classmethod
  def total_emp(cls):
    """ Return number of employees """
    return cls.num_emp

  @staticmethod
  def emp_email(fname, lname):
    """ Create employee email """
    return fname + '.' + lname + '@email.com'

class Developer(Employee):
  raise_amt = 1.10

  def __init__(self, fname, lname, pay, p_lang):
    """ Developer class constructor """
    super().__init__(fname, lname, pay)
    self.p_lang = p_lang

  def print_emp_info(self):
    """ Print employee information """
    super().print_emp_info()
    print(self.p_lang)

class Manager(Employee):
  def __init__(self, fname, lname, pay, employees=None):
    """ Manager class constructor """
    super().__init__(fname, lname, pay)
    if employees is None:
      self.employees = []
    else:
      self.employees = employees

  def add_emp(self, emp):
    """ Add employee to list of managed employees """
    if emp not in self.employees:
      self.employees.append(emp)

  def remove_emp(self, emp):
    """ Remove employee from list of managed employees """
    if emp in self.employees:
      self.employees.remove(emp)

  def print_emp_info(self):
    super().print_emp_info()
    for emp in self.employees:
      print('-->', emp.fname, emp.lname)

def main():
  emp1 = Employee('John', 'Smith', 40000)
  mgr1 = Manager('Jose', 'Carlos', 60000)
  dev1 = Developer('Sally', 'Smith', 50000, 'Python')

  emp1.print_emp_info()
  dev1.print_emp_info()

  dev1.apply_raise()
  dev1.print_emp_info()
 
  mgr1.add_emp(emp1)
  mgr1.add_emp(dev1)
  mgr1.print_emp_info()

  print(Employee.total_emp())
  #help(Developer)

if __name__ == '__main__':
  main()
