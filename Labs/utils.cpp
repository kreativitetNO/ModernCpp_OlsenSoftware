#include "utils.h"

#include <cstring>
#include <sstream>

std::string heading(std::string const& text)
{
	std::ostringstream ss;
	ss << '\n' << text << '\n' << std::string(text.length(), '=') << '\n';
	return ss.str();
}
