#include "Ticket.h"

#include <algorithm>
#include <iterator>

Ticket::Ticket(std::initializer_list<int> numbers) :
	numbers_{ new int[numbers.size()] }, count_{ static_cast<int>(numbers.size()) }
{
	std::copy(numbers.begin(), numbers.end(), numbers_);
}

Ticket::Ticket(Ticket const& ticket)
	: numbers_{ new int[ticket.count_] }, count_{ ticket.count_ }
{
	std::copy(ticket.numbers_, ticket.numbers_ + ticket.count_, numbers_);
}

Ticket& Ticket::operator=(Ticket const& ticket)
{
	delete[] numbers_;
	numbers_ = new int[ticket.count_];
	std::copy(ticket.numbers_, ticket.numbers_ + ticket.count_, numbers_);
	count_ = ticket.count_;
	return *this;
}

Ticket::Ticket(Ticket&& ticket) noexcept
{
	numbers_ = ticket.numbers_;
	count_ = ticket.count_;
	ticket.numbers_ = nullptr;
	ticket.count_ = 0;
}

Ticket& Ticket::operator=(Ticket&& ticket)
{
	delete[] numbers_;
	numbers_ = new int[ticket.count_];
	std::copy(ticket.numbers_, ticket.numbers_ + ticket.count_, numbers_);
	count_ = ticket.count_;
	ticket.numbers_ = nullptr;
	ticket.count_ = 0;
	return *this;
}

Ticket::~Ticket()
{
	delete[] numbers_;
}

std::ostream& operator<<(std::ostream& os, Ticket const& ticket)
{
	os << "Numbers:";
	if (ticket.count_ == 0)
	{
		os << "(NONE)";
	}
	else
	{
		for (int i = 0; i < ticket.count_; ++i)
			os << " " << ticket.numbers_[i];
	}
	return os;
}
