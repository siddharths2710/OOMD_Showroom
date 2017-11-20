#include "employee.h"

namespace showroom {
	Employee::Employee() {}

	Employee::Employee(string name, int age, Emp_Type type, string address, 
						int salary) {
		this->name = name;
		this->age = age;
		this->type = type;
		this->address = address;
		this->salary = salary;
	}

	Employee::Employee(const Employee &other) {
		name  = other.name;
		age  = other.age;
		type  = other.type;
		address  = other.address;
		salary  = other.salary;
	}
	void Employee::make_sale(Car &car, Customer &c) {
		if(type == SALESPERSON || type == CLOSER)
			cout << "Employee '" << name << "' is making a sale for car " 
				<< car.getmodel() << " to customer "<< c.getname() << endl;
	}

	void Employee::deliver_car(Car &car, Customer &c) {
		if(type == PORTER)
			cout << "Porter '" << name << "' is delivering car " 
				<< car.getmodel() << " to customer "<< c.getname() << endl;
	}

	//Creator Principle
	/* 
		Customer wants to purchase car
		For this reason Employee needs to initiate payment for the sake of customer
	*/
	Payment Employee::process_payment(Customer &c, Employee &e, 
								Payment_Type type, Payment_Method method) {
		return Payment(c,e,type,method);
	}

	string Employee::getname() {
		return name;
	}

	string Employee::getaddress() {
		return address;
	}

	Emp_Type Employee::gettype() {
		return type;
	}

	ostream& operator<<(ostream& obj, const Employee& e) {
		string t;
		switch(e.type) {
			case 0: t = "SALESPERSON"; break;
			case 1: t = "GENERALMANAGER"; break;
			case 2: t = "PORTER"; break;
			case 3: t = "CLOSER"; break;
		}

		return obj << "Employee \n name: " << e.name << "\n age: " << e.age 
				<< "\n Address: " << e.address << "\nDesignation: " << t 
				<< "\n salary: " << e.salary << endl;
	}
}
