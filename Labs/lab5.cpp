#include "lab5.h"
#include "Ticket.h"

void Lab5::ex1()
{
	Ticket filledTicket{ 2, 3, 5, 7, 11, 13, 17 };
	Ticket copiedTicket{ filledTicket };

	std::cout << filledTicket << std::endl
	    	  << copiedTicket << std::endl;

	Ticket anotherTicket{ 2, 4, 6, 8, 10, 12 };
	copiedTicket = anotherTicket;

	std::cout << anotherTicket << std::endl
		      << copiedTicket << std::endl;

	Ticket hijackerTicket = std::move(copiedTicket);

	std::cout << hijackerTicket << std::endl
	    	  << copiedTicket << std::endl;

	Ticket counterTerroristTicket{ 31, 14, 15, 92, 6 };

	std::cout << hijackerTicket << std::endl
		      << counterTerroristTicket << std::endl;

	counterTerroristTicket = std::move(hijackerTicket);

	std::cout << hijackerTicket << std::endl
       		  << counterTerroristTicket << std::endl;

}