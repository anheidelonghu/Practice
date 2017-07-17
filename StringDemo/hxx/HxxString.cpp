#include "HxxString.h"
#pragma warning(disable:4996)

HxxString::HxxString(const char * str)
{
	if (!str) m_data = 0;
	else 
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}

HxxString::HxxString(const HxxString & other)
{
	if (!other.m_data) m_data = 0;
	else
	{
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	}
}

HxxString & HxxString::operator=(const HxxString & other)
{
	if (this != &other)
	{
		delete[] m_data;
		if (!other.m_data) m_data = 0;
		else
		{
			m_data = new char[strlen(other.m_data) + 1];
			strcpy(m_data, other.m_data);
		}
	}
	return *this;
}

HxxString HxxString::operator+(const HxxString & other) const
{
	HxxString newString;
	if (!other.m_data) newString = *this;
	else if (!m_data) newString = other;
	else
	{
		newString.m_data = new char[strlen(m_data) + strlen(other.m_data) + 1];
		strcpy(newString.m_data, m_data);
		strcat(newString.m_data, other.m_data);
	}
	return newString;
}

bool HxxString::operator==(const HxxString & s)
{
	if (strlen(s.m_data) != strlen(m_data)) return false;
	return strcmp(m_data, s.m_data) ? false : true;
	return false;
}

char & HxxString::operator[](unsigned int e)
{
	if (e >= 0 && e <= strlen(m_data)) {
		return m_data[e];
	}
}

ostream & operator<<(ostream & os, HxxString & str)
{
	os << str.m_data;
	return os;
}

istream & operator >> (istream & input, HxxString & s)
{
	char temp[255];
	input >> setw(255) >> temp;
	s = temp;
	return input;
}
