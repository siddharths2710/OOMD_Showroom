# AUTOMOBILE SHOWROOM 

## Object Oriented Modeling and Design Project

![alt tag](https://i.imgur.com/LEukHuj.jpg)


## Description

Our project is focused on emulating the working and various scenarios of a single **Automobile** Showroom.
A typical car showroom consists of some number of cars which are present to demo the car to the customers.
A showroom also consists of a fixed number of employees who perform different tasks ( such as manager, salesperson, transporter etc. ). 

A showroom is generally associated with only one company brand, which is why we have a “ brand name ” as attribute for a showroom, along with address and phone number as well. The responsibilities associated with a showroom are to add 
new cars, add new employee, remove sold car, fire employee, and refill showroom with cars if no car is present. 

A car is associated with several properties, such as brand, model, color, price, number of seats, type of fuel, mileage, state etc. The responsibilities associated with a car are to reserve a car, test drive car, and sell car. All these responsibilities involve change of state between available to test drive to booked to sold. Car serves as an “ Information Expert ” for these responsibilities.


## Principles Used ##

* Creator principle
* Low Coupling
* High Cohesion
* Information Expert
* SOLID - Open-Close, Single Responsibility, Liskov Substitution

## Patterns Used ##

* Strategy Pattern
* Singleton Pattern
