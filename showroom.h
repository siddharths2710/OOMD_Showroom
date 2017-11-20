#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include <vector>
#include "car.h"
#include "employee.h"

namespace showroom {
	using namespace std;
	class Showroom {
		static Showroom* showroom_inst; //Singleton Pattern
		Showroom(string brand_l) : brand(brand_l) {}
	protected:
		vector<Car> cars;
		vector<Employee> employees;
		string brand;
		string name;
		string address;
		string phoneno;
	public:
		static Showroom& get_showroom(string brand);
		Car& get_car();
		void populate();
		void add_car(Car &c);
		
		void add_employee(Employee& e);
		void fire_employee();
		
		string& get_name();
		void set_name(string& s);
		string& get_address();
		void set_address(string& s);
		string& get_phoneno();
		void set_phoneno(string& s);
		
		friend ostream& operator<<(ostream&, const Showroom&);
	};
};

#endif
