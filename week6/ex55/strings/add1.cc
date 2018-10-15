#include "strings.ih"

void Strings::add(char *str)
{
	if (d_size == d_capacity)
		reserve(d_capacity * 2);
		
	new(d_str + d_size) string{str};

	++d_size;
}