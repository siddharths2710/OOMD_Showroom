#ifndef ENUMS
#define ENUMS

namespace showroom {
	enum Color { Red,Blue,Black,Green,Yellow,Orange,Grey,Purple, White };
	enum Fueltype { Petrol,Diesel };
	enum State {Available, TestDrive, Reserved, Sold };
	enum Transmission { Manual, Automatic};

	enum Car_Type {CAR, HATCHBACK, SUV, SEDAN};

	enum Emp_Type {	SALESPERSON, GENERALMANAGER, PORTER, CLOSER };
	enum Payment_Type { FULLFRONT, EMI };
	enum Payment_Method { CASH, CARD, CHEQUE };
}
#endif
