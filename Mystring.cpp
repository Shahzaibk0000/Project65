#include <iostream>
#include "Mystring.h"
using namespace std;

Mystring::Mystring()
{
	buffer = nullptr;
	size = 0;
}

Mystring::Mystring(const char* name)
{
	if (name == nullptr)
	{
		this->size = 0;
		this->buffer = new char[1];
		this->buffer[0] = '\0'; // Ensure null-termination for an empty string
	}
	else
	{
		int nameSize = 0;
		for (nameSize = 0; name[nameSize] != '\0'; nameSize++) {}
		this->size = nameSize;
		this->buffer = new char[this->size + 1];
		for (int i = 0; name[i] != '\0'; i++)
		{
			this->buffer[i] = name[i];
		}
		this->buffer[this->size] = '\0';
	}
}

Mystring::Mystring(const Mystring& obj)
{
	if (obj.size != 0)
	{
		this->size = obj.size;
		this->buffer = new char[this->size + 1];
		for (int i = 0; obj.buffer[i] != '\0'; i++)
		{
			this->buffer[i] = obj.buffer[i];
		}
		this->buffer[this->size] = '\0';
	}
	else
	{
		this->size = 0;
		this->buffer = nullptr;
	}
}

Mystring& Mystring:: operator=(const Mystring& obj)
{
	if (this->size > 0)
	{
		delete[] this->buffer;
		this->size = 0;
	}

	if (obj.size != 0)
	{
		this->size = obj.size;
		this->buffer = new char[this->size + 1];
		for (int i = 0; obj.buffer[i] != '\0'; i++)
		{
			this->buffer[i] = obj.buffer[i];
		}
		this->buffer[this->size] = '\0';
	}
	return *this;
}

void Mystring::setname(char* name)
{
	if (name == nullptr)
	{
		return;
	}
	delete[] this->buffer;
	int nameSize = 0;
	for (nameSize = 0; name[nameSize] != '\0'; nameSize++) {}
	this->size = nameSize;
	this->buffer = new char[this->size + 1];
	for (int i = 0; name[i] != '\0'; i++)
	{
		this->buffer[i] = name[i];
	}
	this->buffer[this->size] = '\0';
}

void Mystring::setSize(int s)
{
	this->size = s;
}

const char* Mystring::getname()const
{
	return this->buffer;
}

double Mystring::getsize()const
{
	return this->size;
}

ostream& operator<<(ostream& wr, const Mystring& ms)
{
	const char* s = ms.getname();
	wr << s << endl;
	return wr;
}
istream& operator>>(istream& rd, Mystring& d)
{
	char tStr[100];
	rd >> tStr;
	d.copy(tStr);
	return rd;
}



Mystring Mystring::operator+(const Mystring& other)
{
	Mystring result;
	result.size = this->size + other.size;
	result.buffer = new char[result.size + 1];
	int index = 0;
	for (int i = 0; i < this->size; i++)
	{
		result.buffer[i] = this->buffer[i];
		index++;
	}
	for (int i = index, j = 0; i < result.size; i++, j++)
	{
		result.buffer[i] = other.buffer[j];
		index++;
	}
	result.buffer[result.size] = '\0';
	cout << "Result of '" << this->buffer << "' + '" << other.buffer << "' = '" << result << "'" << endl;

	return result;

}

bool Mystring::operator==(const Mystring& obj) const
{
	if (obj.size != this->size)
	{
		return false;
	}
	else
	{
		for (int i = 0; obj.buffer[i] != '\0'; i++)
		{
			if (this->buffer[i] != obj.buffer[i])
			{
				cout << "'" << this->buffer << "' == '" << obj.buffer << "false" << endl;
				return false;
			}
		}
	}
	cout << "'" << this->buffer << "' == '" << obj.buffer << "true" << endl;
	return true;
}

bool Mystring::operator!=(const Mystring& obj) const
{
	if (obj.size == this->size)
	{
		for (int i = 0; obj.buffer[i] != '\0'; i++)
		{
			if (this->buffer[i] != obj.buffer[i])
			{
				cout << "'" << this->buffer << "' != '" << obj.buffer << "' true" << endl;
				return true;
			}
		}
		cout << "'" << this->buffer << "' != '" << obj.buffer << "false" << endl;
		return false;
	}
	cout << "'" << this->buffer << "' != '" << obj.buffer << "' true" << endl;
	return true;
}

Mystring& Mystring::operator++()
{
	cout << "Result of ++'" << this->buffer << "' = '";
	if (size != 0)
	{
		for (int i = 0; this->buffer[i] != '\0'; i++)
		{
			this->buffer[i] = this->buffer[i] + 1;
		}
	}
	cout << this->buffer << "'" << endl;
	return *this;
}

Mystring Mystring::operator++(int)
{
	Mystring temp;
	temp.size = this->size;
	temp.buffer = new char[this->size + 1];
	cout << "Result of '" << this->buffer << "'++ = '";
	for (int i = 0; i < temp.size; i++)
	{
		temp.buffer[i] = this->buffer[i] + 1;
		this->buffer[i]++;
	}
	temp.buffer[temp.size] = '\0';
	cout << temp << "'" << endl;
	return temp;
}

Mystring& Mystring::operator--()
{
	cout << "Result of --'" << this->buffer << "' = '";
	if (size != 0)
	{
		for (int i = 0; this->buffer[i] != '\0'; i++)
		{
			this->buffer[i] = this->buffer[i] - 1;
		}
	}
	cout << this->buffer << "'" << endl;
	return *this;
}

Mystring Mystring::operator--(int)
{
	Mystring temp;
	temp.size = this->size;
	temp.buffer = new char[this->size + 1];
	cout << "Result of '" << this->buffer << "'-- = '";
	for (int i = 0; i < temp.size; i++)
	{
		temp.buffer[i] = this->buffer[i] - 1;
		this->buffer[i]--;
	}
	temp.buffer[temp.size] = '\0';
	cout << temp << "'" << endl;
	return temp;
}

bool Mystring::operator>(const Mystring& obj)
{
	int thisAscii = 0, objAscii = 0;
	for (int i = 0; i < this->size; i++)
	{
		thisAscii = thisAscii + this->buffer[i];
	}
	for (int i = 0; i < obj.size; i++)
	{
		objAscii = objAscii + obj.buffer[i];
	}

	if (thisAscii > objAscii)
	{
		cout << "'" << this->buffer << "' > '" << obj.buffer << "' true" << endl;
		return true;
	}
	else
	{
		cout << "'" << this->buffer << "' > '" << obj.buffer << "' false" << endl;
		return false;
	}
}

bool Mystring::operator>=(const Mystring& obj)
{
	int thisAscii = 0, objAscii = 0;
	for (int i = 0; i < this->size; i++)
	{
		thisAscii = thisAscii + this->buffer[i];
	}
	for (int i = 0; i < obj.size; i++)
	{
		objAscii = objAscii + obj.buffer[i];
	}

	if (thisAscii >= objAscii)
	{
		cout << "'" << this->buffer << "' >= '" << obj.buffer << "' true" << endl;
		return true;
	}
	else
	{
		cout << "'" << this->buffer << "' >= '" << obj.buffer << "' false" << endl;
		return false;
	}
}

bool Mystring::operator<(const Mystring& obj)
{
	int thisAscii = 0, objAscii = 0;
	for (int i = 0; i < this->size; i++)
	{
		thisAscii = thisAscii + this->buffer[i];
	}
	for (int i = 0; i < obj.size; i++)
	{
		objAscii = objAscii + obj.buffer[i];
	}

	if (thisAscii < objAscii)
	{
		cout << "'" << this->buffer << "' < '" << obj.buffer << "' true" << endl;
		return true;
	}
	else
	{
		cout << "'" << this->buffer << "' < '" << obj.buffer << "' false" << endl;
		return false;
	}
}

bool Mystring::operator<=(const Mystring& obj)
{
	int thisAscii = 0, objAscii = 0;
	for (int i = 0; i < this->size; i++)
	{
		thisAscii = thisAscii + this->buffer[i];
	}
	for (int i = 0; i < obj.size; i++)
	{
		objAscii = objAscii + obj.buffer[i];
	}

	if (thisAscii <= objAscii)
	{
		cout << "'" << this->buffer << "' <= '" << obj.buffer << "' true" << endl;
		return true;
	}
	else
	{
		cout << "'" << this->buffer << "' <= '" << obj.buffer << "' false" << endl;
		return false;
	}
}
void Mystring::copy(const char* src)
{
	if (buffer)
	{
		cout << buffer << " is deleted\n";
		delete[] buffer;
	}
	buffer = deepCopy(src);
}

void Mystring::append(const char* src) // at the end of current CString
{
	int lenSrc = length(src);
	int lenDest = length(buffer);
	char* resultStr = nullptr;
	if (lenSrc != 0)
	{
		resultStr = new char[lenSrc + lenDest];
		for (int i = lenDest - 1; i < lenSrc + (lenDest - 1); i++)// start at the '\0' location
		{
			buffer[i] = src[i - (lenDest - 1)];
		}
	}
	buffer[lenSrc + lenDest - 1] = '\0'; // make sure to add this
}
void Mystring::append(const Mystring& ms)
{
	append(ms.buffer);
}
char* deepCopy(const char* src)
{
	if (!src)
	{
		cout << "Source is nullptr\n";
		return nullptr;
	}
	int len = length(src);
	char* newStr = new char[len];
	for (int i = 0; i < len; i++)
	{
		newStr[i] = src[i];
	}
	return newStr;
}

int length(const char* src)
{
	int result = 0;
	if (!src)
	{
		cout << "CString is nullptr\n";
		return result;
	}
	for (int i = 0; src[i] != '\0'; i++)
	{
		++result;
	}
	return result + 1;
}
int Mystring::count() const
{
	return length(buffer) - 1; // exclude '\0'
}

Mystring concatenate(const Mystring& s1, const Mystring& s2)
{
	Mystring newStr(s1);
	newStr.append(s2);
	return newStr;
}
bool isEqual(const Mystring& s1, const Mystring& s2)
{
	if (s1 == s2)
		return true;
	else
		return false;
}
void Mystring::input()
{
	if (buffer)
	{
		cout << "Enter a CString: ";
		cin >> buffer;
	}
	else
	{
		cout << "CString is nullptr\n";
	}
}
void Mystring::display() const
{
	if (buffer)
	{
		cout << buffer;
	}
	else
	{
		cout << "CString is nullptr\n";
	}
}

int Mystring::compare(const char* src) const
{
	int result = 0;
	if (!src)
	{
		cout << "CString is nullptr, can't compare\n";
		return -9; // 
	}
	int lenSrc = length(src);
	int lenStr = length(buffer);
	if (lenSrc < lenStr)
	{
		return -1;
	}
	if (lenSrc > lenStr)
	{
		return 1;
	}
	// both CStrings are of same length 
	// first check for equality
	for (int i = 0; i < lenStr; i++)
	{
		if (buffer[i] != src[i])
		{
			// CStrings are not equal
			// now check for < or >
			if (buffer[i] < src[i])
			{
				return -1;
			}
			if (buffer[i] > src[i])
			{
				return 1;
			}
		}
	}
	return result;
}
