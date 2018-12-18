#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <vector>
#include <string>
#include <stdexcept>

class Strings
{
    std::vector<std::string> d_strings;

    public:
        Strings() = default;
        Strings(const Strings &) = default;
        Strings(Strings &&) = default;

        Strings &operator=(const Strings &) = default;
        
        size_t size() const;
        size_t capacity() const;

        void resize(size_t size);
        void reserve(size_t size);
        void operator+=(std::string str);

        std::string at(size_t idx);
        std::string operator[](size_t idx);
        std::string const at(size_t idx) const;
        std::string const operator[](size_t idx) const;
    private:
        std::string safeAt(size_t idx) const;
};

inline size_t Strings::size() const
{
    return d_strings.size();
}

inline size_t Strings::capacity() const
{
    return d_strings.capacity();
}

inline void Strings::resize(size_t size)
{
    d_strings.resize(size);
}
        
inline void Strings::reserve(size_t size)
{
    d_strings.reserve(size);
}

inline void Strings::operator+=(std::string str)
{
    d_strings.push_back(str);
}

inline std::string Strings::operator[](size_t idx)
{
    return at(idx);
}

inline std::string const Strings::operator[](size_t idx) const
{
    return at(idx);
}

inline std::string const Strings::at(size_t idx) const
{
    return safeAt(idx);
}

inline std::string Strings::at(size_t idx)
{
    return safeAt(idx);
}

#endif
