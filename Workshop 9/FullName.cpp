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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include"FullName.h"

using namespace std;

namespace sdds {
    FullName::FullName() 
    {
        m_value = nullptr;
    }
    FullName::FullName(const char* name, const char* lastName) : Name(name) 
    {
        m_value = new char[strlen(lastName) + 1];
        strcpy(m_value, lastName);
    }
    FullName::~FullName() {
        delete[] m_value;
        m_value = nullptr;
    }
    FullName::FullName(const FullName& src) : Name(src) 
    {
        m_value = new char[strlen(src.m_value) + 1];
        strcpy(m_value, src.m_value);
    }
    FullName& FullName::operator=(const FullName& src) 
    {
        if (this != &src) {
            Name::operator=(src);
            delete[] m_value;
            m_value = new char[strlen(src.m_value) + 1];
            strcpy(m_value, src.m_value);
        }
        return *this;
    }
    FullName::operator const char* ()const 
    {
        return m_value;
    }
    FullName::operator bool()const {
        if (m_value != nullptr && Name::operator bool()) 
        {
            return true;
        }
        else {
            return false;
        }
    }
    std::ostream& FullName::display(std::ostream& ostr)const 
    {
        if (operator bool()) {
            Name::display(ostr);
            ostr << " ";
            ostr << m_value;
        }
        return ostr;
    }
    std::istream& FullName::read(std::istream& istr) 
    {
        Name::read(istr);

        char temp[100];
        istr.getline(temp, 1000, '\n');

        m_value = new char[strlen(temp) + 1];
        strcpy(m_value, temp);

        return istr;
    }

}