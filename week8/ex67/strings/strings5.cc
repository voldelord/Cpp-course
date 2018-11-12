#include "strings.ih"

Strings::Strings(Strings const &other)
:
    d_str(new string *[other.d_size]),
    d_size(other.d_size),
    d_capacity(other.d_size)
{
    for (size_t idx = 0; idx != d_size; ++idx)
        d_str[idx] = new string(*other.d_str[idx]);
}

