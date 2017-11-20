#include "car.h"

namespace showroom {
	
	//Car -> Information Expert
	// High Cohesion
	//It has required attributes to test drive car, reserve a car and sell car

	Car::Car(string brand, string model, Color color, int price, 
			int no_of_seats, Fueltype fueltype, float mileage, 
			State state, Transmission trans) {
		this->brand = brand;
		this->model = model;
		this->color = color;
		this->price = price;
		this->no_of_seats = no_of_seats;
		this->fueltype = fueltype;
		this->mileage = mileage;
		this->state = state;
		this->trans = trans;
		this->type = CAR;
	}
	
	Car::Car(const Car &other) {
		brand = other.brand;
		model = other.model;
		color = other.color;
		price = other.price;
		no_of_seats = other.no_of_seats;
		fueltype = other.fueltype;
		mileage  = other.mileage;
		state  = other.state;
		trans  = other.trans;
		type  = other.type;
	}

	void Car::reserve_car() {
		state = Reserved;
	}
	
	void Car::test_drive_car() {
		if (state == Reserved || state == Sold) {
			//some error
			cout << "Cannot test drive current car since it's in " 
				<< state << " state\n";
		} else {
			state = TestDrive;	
		}
	}
	
	void Car::sell_car() {
		if (state == Reserved) {
			state = Sold;
		} else {
			//some error
			cout<<"Cannot sell car since it has not been booked yet\n";
		}
	}
	
	string Car::getmodel() {
		return model;
	}
	
	long Car::getprice() {
		return price;
	}
	
	Hatch_back::Hatch_back(string brand, string model, Color color, int price, 
			int no_of_seats, Fueltype fueltype, float mileage, 
			State state, Transmission trans)
			: Car(brand, model, color, price, no_of_seats, fueltype, 
					mileage, state, trans) {
		type = HATCHBACK;
	}
	
	Sedan::Sedan(string brand, string model, Color color, int price, 
			int no_of_seats, Fueltype fueltype, float mileage, 
			State state, Transmission trans)
			: Car(brand, model, color, price, no_of_seats, fueltype, 
					mileage, state, trans) {
		type = SEDAN;
	}
	
	Suv::Suv(string brand, string model, Color color, int price, 
			int no_of_seats, Fueltype fueltype, float mileage, 
			State state, Transmission trans)
			: Car(brand, model, color, price, no_of_seats, fueltype, 
					mileage, state, trans) {
		type = SUV;
	}
	
	ostream& operator<<(ostream &obj, const Car &c) {
		string t, s, f, co, tr;
		
		switch(c.type) {
			case 0: t = "CAR"; break;
			case 1: t = "HATCHBACK"; break;
			case 2: t = "SUV"; break;
			case 3: t = "SEDAN"; break;
		}
		
		switch(c.state) {
			case 0: s = "AVAILABLE"; break;
			case 1: s = "TestDrive"; break;
			case 2: s = "Reserved"; break;
			case 3: s = "Sold"; break;
		}
		
		switch(c.fueltype) {
			case 0: f = "PETROL"; break;
			case 1: f = "DIESEL"; break;
		}
		
		//enum Color { Red,Blue,Black,Green,Yellow,Orange,Grey,Purple, White };
		switch(c.color) {
			case 0: co = "Red"; break;
			case 1: co = "Blue"; break;
			case 2: co = "Black"; break;
			case 3: co = "Green"; break;
			case 4: co = "Yellow"; break;
			case 5: co = "Orange"; break;
			case 6: co = "Grey"; break;
			case 7: co = "Purple"; break;
			case 8: co = "White"; break;
		}
		
		switch(c.trans) {
			case 0: tr = "Manual"; break;
			case 1: tr = "Automatic"; break;
		}
		
		return obj << "\n\n Type: " << t << "\n Car brand: " << c.brand 
				<< "\n Car model: " << c.model << "\n Car color: " << co 
				<< "\n Transmission: " << tr << "\n Fuel type: " << f 
				<< "\n Price: " << c.price << "\n Number of Seats: " 
				<< c.no_of_seats << "\n Type of fuel: " << f 
				<< "\n Car mileage: " << c.mileage 
				<< "\n Car state: " << s << endl;
	}
}
