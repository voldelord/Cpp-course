#ifndef INCLUDED_DATA_
#define INCLUDED_DATA_

#include <string>
#include <iosfwd>

#include "../strings/strings.h"



union Data
{
    enum Type
    {
        WORDS,
        WORD,
        VALUE
    };

    private:
        Strings u_words;
        std::string u_word;
        double u_value;

        static void (Data::*s_copy[])(Data const &data);
        static void (Data::*s_destroy[])();
        static void (Data::*s_swap[][3])(Data &data);

    public:
        Data(int argc, char **argv);
        Data(char **environ);
        Data(std::istream &in);
        Data(Strings const &words);
        Data(char const *ntbs);
        Data(std::string const &word);
        Data(double value);
        ~Data();

        Data(Data const &data, Type type);
        Data(Data &&data, Type type);

        Strings const &words() const;
        std::string const &word() const;
        double value() const;

        Data &copy(Type current, Data const &other, Type next);
        Data &move(Type current, Data &&other, Type next);
        void swap(Type current, Data &other, Type next);
        void destroy(Type type);

    private:
        void destroy_words();
        void destroy_word();
        void destroy_value(); // for completeness.
        
        void copy_words(Data const &data);
        void copy_word(Data const &data);
        void copy_value(Data const &data);

        void swap_words_words(Data &data);
        void swap_words_word(Data &data);
        void swap_words_value(Data &data);
        void swap_word_words(Data &data);
        void swap_word_word(Data &data);
        void swap_word_value(Data &data);
        void swap_value_words(Data &data);
        void swap_value_word(Data &data);
        void swap_value_value(Data &data);
};

inline Data::Data(int argc, char **argv)
:   u_words(argc, argv)
{ }

inline Data::Data(char **environ)
:   u_words(environ)
{ }

inline Data::Data(std::istream &in)
:   u_words(in)
{ }

inline Data::Data(Strings const &words)
:   u_words(words)
{ }

inline Data::Data(char const *ntbs)
:   u_word(ntbs)
{ }

inline Data::Data(std::string const &word)
:   u_word(word)
{ }

inline Data::Data(double value)
:   u_value(value)
{ }

inline Strings const &Data::words() const
{
    return u_words;
}

inline std::string const &Data::word() const
{
    return u_word;
}

inline double Data::value() const
{
    return u_value;
}

inline Data::Data(Data const &data, Type type)
{
    (this->*s_copy[type])(data);
}

inline Data::Data(Data &&data, Type type)
{
    move(VALUE, std::move(data), type);
}

inline void Data::swap(Type current, Data &other, Type next)
{
    (this->*s_swap[current][next])(other);
}

inline void Data::destroy(Type type)
{
    (this->*s_destroy[type])();
}

inline void Data::destroy_words()
{
    u_words.~Strings();
}

inline void Data::destroy_word()
{
    u_word.~basic_string();
}

inline void Data::destroy_value()
{
    //nothing needs to happen here
}

inline void Data::copy_words(Data const &data)
{
    new (&u_words) Strings(data.u_words);
}

inline void Data::copy_word(Data const &data)
{
    new (&u_word) Data(data.u_word, Type::WORD);
}

inline void Data::copy_value(Data const &data)
{
    u_value = data.u_value;
}

inline void Data::swap_words_words(Data &data)
{
    u_words.swap(data.u_words);
}

inline void Data::swap_word_word(Data &data)
{
    u_word.swap(data.u_word);
}

#endif
