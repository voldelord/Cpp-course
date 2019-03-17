// Generated by Flexc++ V2.06.04 on Tue, 12 Mar 2019 14:41:27 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"

enum TOKENS
{
    SUBL = 256,
    STRING_PART,
    STRING_DONE,
    INCLUDE,
    LINE_COMMENT,
    RAWSTRING,
    DONE
};

// This program accounts for the fact that unmatched input gets outputted
// So it only matches what it is required, on such a match it replaces the
// input when needed and outputs that to the stream the lexer outputs to.
class Scanner: public ScannerBase
{
    public:
        explicit Scanner(std::istream &in = std::cin,
                                std::ostream &out = std::cout);

        Scanner(std::string const &infile, std::string const &outfile);
        
        // when the lexer returns STRING_PART, this function
        // gathers all parts, (accounting for multiline strings).
        std::string gather_string();



        // $insert lexFunctionDecl
        int lex();

    private:
        std::string d_buffer;
        std::string d_delimiter;

        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum__ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.
};

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out)
{}

inline Scanner::Scanner(std::string const &infile, std::string const &outfile)
:
    ScannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex__();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::postCode([[maybe_unused]] PostEnum__ type) 
{
    // optionally replace by your own code
}

inline void Scanner::print() 
{
    print__();
}


#endif // Scanner_H_INCLUDED_
