#pragma once

#include <sstream>
#include <string>

namespace utils
{

template < typename T >
std::string to_string( const T& n )
{
	std::ostringstream stm ;
	stm << n ;
	return stm.str() ;
}

} // namespace utils
