#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class HxxString
{
	friend ostream& operator<<(ostream&, HxxString&);//<<
	friend istream& operator >> (istream&, HxxString&);//>>
public:
	HxxString(const char* str = NULL);
	HxxString(const HxxString& other);
	HxxString& operator=(const HxxString& other);
	HxxString operator+(const HxxString& other)const;
	bool operator==(const HxxString&);
	char& operator[](unsigned int);
	size_t size() { return strlen(m_data); };
	~HxxString(void) { delete[] m_data; }//????  ;

private:
	char* m_data;

};