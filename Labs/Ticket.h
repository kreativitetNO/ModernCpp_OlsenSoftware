#ifndef TICKET_H
#define TICKET_H

#include <initializer_list>
#include <iostream>

class Ticket
{
public:
	// TODO: Define the following methods:
	//  - regular constructor (to initialize the ticket object originally, with a series of lottery numbers)
	//  - copy constructor and move constructor
	//  - copy assignment operator and move assignment operator
	//  - destructor

	Ticket(std::initializer_list<int> numbers);
	Ticket(Ticket const&);
	Ticket& operator=(Ticket const&);
	Ticket(Ticket&&) noexcept;
	Ticket& operator=(Ticket&&);
	~Ticket();

private:
	int* numbers_;
	int count_;

	friend std::ostream& operator<<(std::ostream& os, Ticket const&);
};

#endif
