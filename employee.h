#include "car.h"

namespace showroom {
	class Payment;
	class Customer;

	class Employee {
	protected:
		string name;
		int age;
		string address;
		Emp_Type type;
		int salary;
	public:
		Employee();
		Employee(string name, int age, Emp_Type type, string address="N.A.", 
					int salary=50000);
		Employee(const Employee &);
		void make_sale(Car &car, Customer &c);
		Payment process_payment(Customer &c, Employee &e, 
					Payment_Type type=EMI, Payment_Method method=CASH);
		void deliver_car(Car &car, Customer &c);
		string getname();
		string getaddress();
		Emp_Type gettype();
		
		friend ostream& operator<<(ostream&, const Employee&);
	};

	class Customer {
	protected:
		string name;
		int age;
		string address;
	public:
		Customer();
		Customer(string name, int age, string address="N.A.");
		Customer(const Customer&);
		string getname();
		string getaddress();

		friend ostream& operator<<(ostream&, const Customer&);
	};

	class Payment {
	protected:
		Customer c;
		Employee e;
		Payment_Type type;
		Payment_Method method;
		
	public:
		Payment(Customer& c, Employee& e, Payment_Type type, Payment_Method method);
		Payment(const Payment&);
		friend ostream& operator<<(ostream&, const Payment&);
	};
}
