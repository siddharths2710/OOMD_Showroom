#include "showroom.h"
using namespace showroom;
int main(int argc, char const *argv[])
{
	//Maruti Suzuki Showroom

	string suzuki = "Maruti Suzuki";
	
	/* sroom, sroom1 and sroom2 refer to the same showroom object.
	Singleton Pattern.*/

	Showroom sroom1 = Showroom::get_showroom(suzuki);
	Showroom sroom2 = Showroom::get_showroom(suzuki);
	Showroom sroom = Showroom::get_showroom(suzuki);
	string addr = "RMZ Ecospace, Bellandur, Bangalore - 500001";
	string phone = "8765432109";
	sroom.set_address(addr);
	sroom.set_phoneno(phone);
	

	Hatch_back swift(suzuki,"Swift",Red,450000,4,Petrol,20);
	Hatch_back eight_hundred(suzuki,"800");

	//Add 2 cars to showroom

	sroom.add_car( swift );
	sroom.add_car( eight_hundred );
	

	//Add employees to work in showroom

	Employee manager("Ram Gopal Verma",43,GENERALMANAGER,"#23, MG Rd, Mumbai",4000000);
	Employee sales("Anant",27,SALESPERSON,"13th Cross, Bangalore");
	Employee transporter("Rakesh",23,PORTER);

	sroom.add_employee(manager);
	sroom.add_employee(sales);
	sroom.add_employee(transporter);

	//Now 4 customers come to see cars

	Customer c1("Kiran P",28,"Jayanagar");
	Customer c2("Prakash",35,"Ayodh Marg");
	Customer c3("Suhas",41,"Gandhi Rd");
	Customer c4("Shantanu",62,"Ayodh Marg");

	
	

	//successful sale
	Car car1 = sroom.get_car();
	sales.make_sale(car1,c1);
	Payment p1 = manager.process_payment(c1,sales,EMI,CHEQUE);
	cout<<p1<<endl;
	transporter.deliver_car(car1,c1);


	//unsuccessful sale
	Car car2 = sroom.get_car();
	sales.make_sale(car2,c2);

	//no payment -> add car back to showroom
	sroom.add_car(car2);
	
	//successful sale
	Car car3 = sroom.get_car();
	sales.make_sale(car3,c3);
	Payment p3 = manager.process_payment(c3,sales,FULLFRONT,CARD);
	cout<<p3<<endl;
	transporter.deliver_car(car3,c3);

	//successful sale
	Car car4 = sroom.get_car();
	sales.make_sale(car4,c4);
	Payment p4 = manager.process_payment(c4,sales,EMI,CASH);
	cout<< p4 << endl;
	transporter.deliver_car(car4,c4);

	return 0;
}