#include "employee.h"

namespace showroom {
	Customer::Customer() {}

	Customer::Customer(string name, int age, string address) {
		this->name = name;
		this->age = age;
		this->address = address;
	}

	Customer::Customer(const Customer &other) {
		name = other.name;
		age = other.age;
		address = other.address;
	}

	string Customer::getname() {
		return name;
	}

	string Customer::getaddress() {
		return address;
	}

	ostream& operator<<(ostream& obj, const Customer& e) {
		return obj << "Customer \n name: " << e.name << "\n age: " << e.age 
				<< "\n Address: " << e.address << endl;
	}
}
