#include "employee.h"

namespace showroom {
	Payment::Payment(Customer& c, Employee& e, Payment_Type type, 
				Payment_Method method) {
		this->c = c;
		this->e = e;
		this->type = type;
		this->method = method;
	}

	Payment::Payment(const Payment &other) {
		c  = other.c;
		e  = other.e;
		type  = other.type;
		method  = other.method;
	}

	ostream& operator<<(ostream& obj, const Payment& p) {
		string m,t;
		switch( p.method )
		{
			case 0: m = "CASH"; break;
			case 1: m = "CARD"; break;
			case 2: m = "CHEQUE"; break;
		}
		switch( p.type )
		{
			case 0: t = "FULL FRONT"; break;
			case 1: t = "EMI ( Equated Montly Installments )"; break;
		}
		return obj << "Payment between Customer \n" << p.c 
				<< "\n & \n Employee\n" << p.e << "\n Payment Method:" 
				<< m << "\n Payment type: " << t << endl;
	}
}
