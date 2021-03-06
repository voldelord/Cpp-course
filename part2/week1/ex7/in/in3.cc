#include "in.ih"

Strings::In::In(Strings *str, char const *delim, size_t begin, size_t end)
{
    d_str = str;
    d_begin = ((begin > 0) ? begin : 0);
    d_end = ((end <= str->size()) ? end : str->size());
    d_del = delim;
    d_funPtr = nullptr; //set to 0 to indicate insertDelim should be used
}
