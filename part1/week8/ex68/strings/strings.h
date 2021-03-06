#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <istream>

struct stringsData
{
	size_t size;
	std::string *strings;
};

class Strings
{
	size_t d_size;
    size_t d_nIter;
	std::string *d_str;
    void (Strings::*enlargeFunc)();

    public:
    	Strings();
        Strings(size_t nIterate, bool copy = true);
        ~Strings();
    
        void iterate(char **environLike);

        size_t size() const;
        std::string const *data() const;
    
        std::string &at(size_t idx);
      	std::string const &at(size_t idx) const;
    
        stringsData release();

    private:
    	void add(std::string const &str);
        void enlarge(bool copy);
        void enlargeByCopy();
        void enlargeByMove();
        size_t length(char **data) const;
        std::string &at_index(size_t idx) const;
};

inline size_t Strings::size() const
{
    return d_size;
}

inline std::string const *Strings::data() const
{
    return d_str;
} 
        
#endif
