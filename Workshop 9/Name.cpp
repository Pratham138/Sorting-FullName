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
#include<iostream>
#include <cstring>
#include"Name.h"

using namespace std;

namespace sdds {
	Name::Name() {
		m_value = nullptr;
	}
	Name::Name(const char* name) 
	{
		m_value = new char[strlen(name) + 1];
		strcpy(m_value, name);
	}
	Name::Name(const Name& src) 
	{
		dynamicAlloc(src);
	}
	Name& Name::operator=(const Name& src) 
	{
		delete[] m_value;
		if (this != &src) {
			dynamicAlloc(src);
		}
		return *this;
	}
	Name& Name::dynamicAlloc(const Name& src) 
	{
		m_value = new char[strlen(src.m_value) + 1];
		strcpy(m_value, src.m_value);
		return *this;
	}
	Name::~Name() 
	{
		delete[] m_value;
		m_value = nullptr;
	}
	Name::operator const char* ()const 
	{
		return m_value;
	}
	Name::operator bool()const {
		if (m_value != nullptr && m_value[0] != '\0') 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	std::ostream& Name::display(std::ostream& ostr)const 
	{
		if (m_value != nullptr && m_value[0] != '\0') 
		{
			ostr << m_value;
		}
		return ostr;
	}
	std::istream& Name::read(std::istream& istr) 
	{
		char temp[100] = { '\0' };
		istr >> temp;

		m_value = new char[strlen(temp) + 1];
		strcpy(m_value, temp);

		if (istr.fail() != 1) {
			istr.ignore(1);
		}
		return istr;
	}
	std::istream& operator>>(std::istream& istr, Name& src) 
	{
		src.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Name& src) 
	{
		src.display(ostr);
		return ostr;
	}
}