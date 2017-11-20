#include <cstdlib>
#include "showroom.h"

namespace showroom {
	Showroom* Showroom::showroom_inst = 0;
	
	//Singleton Pattern
	Showroom& Showroom::get_showroom(string brand) {
		if (!showroom_inst) {
			showroom_inst = new Showroom(brand);
			srand((unsigned) time(0));
		}
		return *showroom_inst;
	}

	//Creator Principle 
	//if no cars exist
	Car& Showroom::get_car() {
		if (cars.empty()) {
			cout<<"\n\nRefilling showroom with cars\n\n";
			populate();
		}
		int r = rand() % cars.size();
		Car& c = cars[r];
		cars.erase(cars.begin() + r);
		return c;
	}


	void Showroom::populate() {
		for (int i = cars.size(); i < 20; i++) {
			int r = rand() % 3;
			if (r == 0) {
				cars.push_back(Hatch_back(brand, "Swift"));
			} else if (r == 1) {
				cars.push_back(Suv(brand, "Brezza"));
			} else {
				cars.push_back(Sedan(brand, "Ciaz"));
			}
		}
	}

	void Showroom::add_car(Car &c)
	{
		cars.push_back(c);
	}

	void Showroom::add_employee(Employee& e) {
		employees.push_back(e);
	}
	
	void Showroom::fire_employee() {
		// Fire some random guy
		employees.erase(employees.begin());
	}

	string& Showroom::get_name() {
		return name;
	}

	void Showroom::set_name(string& s) {
		name = s;
	}

	string& Showroom::get_address() {
		return address;
	}

	void Showroom::set_address(string& s) {
		address = s;
	}

	string& Showroom::get_phoneno() {
		return phoneno;
	}

	void Showroom::set_phoneno(string& s) {
		phoneno = s;
	}

	ostream& operator<<(ostream& ost, const Showroom& s) {
		ost << "Car Showroom: \n\tBrand - " << s.brand 
			<< "\n\tName - " << s.name
			<< "\n\tAddress - " << s.address
			<< "\n\tPhone No. - " << s.phoneno
			<< endl;
		
		ost << "Cars: [";
		if (s.cars.size() > 0) 
			ost << s.cars[0];
		for (auto c = s.cars.begin()+1; c != s.cars.end(); c++) {
			ost << ", " << *c;
		}
		ost << "]" << endl;

		ost << "Employee: [";
		if (s.employees.size() > 0) 
			ost << s.employees[0];
		for (auto c = s.employees.begin()+1; c != s.employees.end(); c++) {
			ost << ", " << *c;
		}
		ost << "]" << endl;

		return ost;
	}
}
