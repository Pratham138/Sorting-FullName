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

#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
#include <iostream>
#include "Name.h"
using namespace std;
namespace sdds {
    class FullName : public Name 
    {
        char* m_value;
    public:
        FullName();
        FullName(const char* name, const char* lastName);
        ~FullName();
        FullName(const FullName& src);
        FullName& operator=(const FullName& src);
        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
}
#endif