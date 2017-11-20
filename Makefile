Client: Client.o car.o customer.o employee.o payment.o showroom.o
	g++ -std=c++11 Client.o car.o customer.o employee.o payment.o showroom.o -o Client

Client.o: Client.cpp showroom.h enums.h employee.h car.h
	g++ -c -std=c++11 Client.cpp

car.o: car.cpp car.h enums.h employee.h
	g++ -c -std=c++11 car.cpp

customer.o: customer.cpp employee.h enums.h
        g++ -c -std=c++11 customer.cpp

employee.o: employee.cpp employee.h enums.h
        g++ -c -std=c++11 employee.cpp

payment.o: payment.cpp employee.h enums.h
        g++ -c -std=c++11 payment.cpp

showroom.o: showroom.cpp showroom.h employee.h enums.h
        g++ -c showroom.cpp -std=c++11 -o showroom.o

clean:
	rm -rf *.o
