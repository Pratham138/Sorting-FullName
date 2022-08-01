/*
*****************************************************************************
                          Workshop - #9 (P1)
Full Name  : Pratham Hemangbhai Pathak
Student ID#: 161688213
Email      : ppathak5@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
using namespace std;
namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();
        Name(const char* name);

       
        Name(const Name& src);
        Name& operator=(const Name& src);
        ~Name();
        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);

        Name& dynamicAlloc(const Name& src);
    };
    std::istream& operator>>(std::istream& istr, Name& src);
    std::ostream& operator<<(std::ostream& ostr, const Name& src);
}
#endif
