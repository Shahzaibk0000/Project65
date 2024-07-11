#pragma once

#include <iostream>
using namespace std;

char* deepCopy(const char* src);
int length(const char* src);

class Mystring
{
private:
	char* buffer;
	int size;
public:
	Mystring();
	Mystring(const char*);
	Mystring(const Mystring& obj);
	Mystring& operator=(const Mystring& obj);
	Mystring operator+(const Mystring& obj);
	bool operator ==(const Mystring& obj)const;
	bool operator !=(const Mystring& obj)const;
	Mystring& operator++();
	Mystring operator++(int);
	Mystring& operator--();
	Mystring operator--(int);
	bool operator>(const Mystring& obj);
	bool operator>=(const Mystring& obj);
	bool operator<(const Mystring& obj);
	bool operator<=(const Mystring& obj);
	void setname(char*);
	void setSize(int);
	const char* getname()const;
	double getsize()const;
	void copy(const char* src);
	void append(const char* _str);
	void append(const Mystring& ms);
	int count() const;
	int compare(const char* _str) const;
	bool isEmpty() const;
	void input();
	void display() const;

};
ostream& operator <<(ostream& wr, const Mystring& ms);
istream& operator>>(istream& rd, Mystring& d);
Mystring concatenate(const Mystring& s1, const Mystring& s2);
bool isEqual(const Mystring& s1, const Mystring& s2);

