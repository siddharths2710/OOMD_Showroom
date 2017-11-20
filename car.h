#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <typeinfo>
#include "enums.h"
#include <string>
using namespace std;

namespace showroom {
	
	// Information Expert
	// High Cohesion
	class Car {
	protected:
		string brand;
		string model;
		Car_Type type;
		Color color;
		long price;
		int no_of_seats;
		Fueltype fueltype; 
		float mileage;
		State state;
		Transmission trans;
		
	public:
		Car(string brand, string model, Color color=White, int price=360000, 
			int no_of_seats=4, Fueltype fueltype=Petrol, float mileage=15, 
			State state=Available, Transmission trans=Manual);
		Car(const Car &);
		void reserve_car();
		void test_drive_car();
		void sell_car();
		string getmodel();
		long getprice();

		friend ostream& operator<<(ostream&, const Car&);
	};
	
	class Hatch_back : public Car {
	public:
		Hatch_back(string brand, string model, Color color=White, 
				int price=360000, int no_of_seats=4, Fueltype fueltype=Petrol, 
				float mileage=23, State state=Available, 
				Transmission trans=Manual);
		
		friend ostream& operator<<(ostream&, const Car&);
	};
	
	class Suv : public Car {
	public:
		Suv(string brand, string model, Color color=White, int price=1500000,
			int no_of_seats=5, Fueltype fueltype=Diesel, float mileage=8,
			State state=Available, Transmission trans=Manual);
		
		friend ostream& operator<<(ostream&, const Car&);
	};
	
	class Sedan : public Car {
	public:
		Sedan(string brand, string model, Color color=White, int price=780000,
				int no_of_seats=5, Fueltype fueltype=Petrol, float mileage=13,
				State state=Available, Transmission trans=Automatic);
		
		friend ostream& operator<<(ostream&, const Car&);
	};
}

#endif
