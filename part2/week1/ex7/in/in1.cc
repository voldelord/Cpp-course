#include "in.ih"

Strings::In::In(Strings *str, char const *delim)
{
    d_str = str;
    d_begin = 0;
    d_end = str->size();
    d_del = delim;
    d_funPtr = nullptr; //set to 0 to indicate insertDelim should be used
}
