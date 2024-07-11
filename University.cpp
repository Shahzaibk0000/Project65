#include<iostream>
#include<fstream>
#include"Mystring.h"
#include"University.h"

using namespace std;


University::University()
{
	noOfTeachers = 0;
	name = Mystring();
	noOfTeachers = 0;
	teacherId = nullptr;
	teacherNames = nullptr;
	teacherSalaries = nullptr;
}

University::University(const Mystring& _uniName, const Mystring* _teacherNames, const int* _teacherSalaries, const int* _teacherIds, const int& _noOfteachers)
{
	setNoOfTeachers(_noOfteachers);
	setName(_uniName);
	setTeacherNames(_teacherNames);
	setTeacherSalaries(_teacherSalaries);
	setTeacherId(_teacherIds);
}

University::University(const University& u)
{
	setNoOfTeachers(u.noOfTeachers);
	setName(u.name);
	setTeacherNames(u.teacherNames);
	setTeacherSalaries(u.teacherSalaries);
	setTeacherId(u.teacherId);
}

University::~University()
{
	delete[] teacherId;
	teacherId = nullptr;
	delete[] teacherNames;
	teacherNames = nullptr;
	delete[] teacherSalaries;
	teacherSalaries = nullptr;
}

void University::setNoOfTeachers(const int& _noOfteachers)
{
	noOfTeachers = _noOfteachers;
}

University& University:: operator=(const University& other)
{
	if (this != &other)
	{
		setTeacherId(other.teacherId);
		setNoOfTeachers(other.noOfTeachers);
		setName(other.name);
		setTeacherNames(other.teacherNames);
		setTeacherSalaries(other.teacherSalaries);

	}
	return *this;
}
void University::setName(const Mystring& s)
{
	name = s;
}
void University::setTeacherNames(const Mystring* s)
{
	if (s == nullptr)
	{
		return;
	}
	if (teacherNames != nullptr)
	{
		delete[] teacherNames;
	}
	teacherNames = new Mystring[noOfTeachers];
	for (int i = 0; i < noOfTeachers; i++)
	{
		teacherNames[i] = s[i];
	}

}
void University::setTeacherId(const int* _teacherIds)
{
	if (_teacherIds == nullptr)
	{
		return;
	}
	if (teacherId != nullptr)
	{
		delete[] teacherId;
	}
	teacherId = new int[noOfTeachers];
	for (int i = 0; i < noOfTeachers; i++)
	{
		teacherId[i] = _teacherIds[i];
	}

}
void University::setTeacherSalaries(const int* _teacherSalaries)
{
	if (_teacherSalaries == nullptr)
	{
		return;
	}
	if (teacherSalaries != nullptr)
	{
		delete[] teacherSalaries;
	}
	teacherSalaries = new int[noOfTeachers];
	for (int i = 0; i < noOfTeachers; i++)
	{
		teacherSalaries[i] = _teacherSalaries[i];
	}
}
Mystring University::find(const int& employeeID)
{
	for (int i = 0; i < noOfTeachers; ++i)
	{
		if (teacherId[i] == employeeID)
		{
			// Return the corresponding name when matching ID is found
			return teacherNames[i];
		}
	}
	return Mystring("Employee ID not found");
}
int University::calculateSalary() const
{
	int totalSalary = 0;
	for (int i = 0; i < noOfTeachers; ++i)
	{
		totalSalary += teacherSalaries[i];
	}
	return totalSalary;
}
istream& operator>>(istream& is, University& u)
{
	Mystring _name = Mystring();
	int _noOfTeachers = 0;
	Mystring* _teacherNames = nullptr;
	int* _teacherId = nullptr;
	int* _teacherSalaries = nullptr;

	cout << "\nEnter name of University: ";
	is >> _name;
	cout << "\nEnter number of Teachers: ";
	is >> _noOfTeachers;
	cout << "\nEnter Teacher Ids: ";
	_teacherId = new int[_noOfTeachers];
	for (int i = 0; i < _noOfTeachers; i++)
	{
		is >> _teacherId[i];
	}
	cout << "\nEnter Teacher Names: ";
	_teacherNames = new Mystring[_noOfTeachers];
	for (int i = 0; i < _noOfTeachers; i++)
	{
		is >> _teacherNames[i];
	}
	cout << "\nEnter Teacher Salaries: ";
	_teacherSalaries = new int[_noOfTeachers];
	for (int i = 0; i < _noOfTeachers; i++)
	{
		is >> _teacherSalaries[i];
	}

	u.setName(_name);
	u.setNoOfTeachers(_noOfTeachers);
	u.setTeacherId(_teacherId);
	u.setTeacherNames(_teacherNames);
	u.setTeacherSalaries(_teacherSalaries);
	// Cleanup memory
	delete[] _teacherNames;
	delete[] _teacherId;
	delete[] _teacherSalaries;
	return is;

}
/*
ifstream& operator>>(ifstream& ifs, University& u)
{
	char waste[100];
	Mystring _name;
	Mystring* _teacherNames;
	int* _teacherId;
	int* _teacherSalaries;
	int _noOfTeachers;
	cout << "\nEnter name of University: ";
	ifs.getline(waste, 99, ':');
	int i = 0;
	cout << "\nEnter number of Teachers: ";
	ifs >> waste;
	ifs >> _noOfTeachers;
	cout << "\nEnter Teacher Ids: ";
	ifs >> waste;
	_teacherId = new int[_noOfTeachers];
	for (int i = 0; i < _noOfTeachers; i++)
	{
		ifs >> _teacherId[i];
	}
	cout << "\nEnter Teacher Names: ";
	ifs >> waste;
	_teacherNames = new Mystring[_noOfTeachers];
	for (int i = 0; i < _noOfTeachers; i++)
	{
		ifs >> _teacherNames[i];
	}
	cout << "\nEnter Teacher Salaries: ";
	ifs >> waste;
	_teacherSalaries = new int[_noOfTeachers];
	for (int i = 0; i < _noOfTeachers; i++)
	{
		ifs >> _teacherSalaries[i];
	}

	u.setName(_name);
	u.setNoOfTeachers(_noOfTeachers);
	u.setTeacherId(_teacherId);
	u.setTeacherNames(_teacherNames);
	u.setTeacherSalaries(_teacherSalaries);
	// Cleanup memory
	delete[] _teacherNames;
	delete[] _teacherId;
	delete[] _teacherSalaries;
	return ifs;

}*/
ifstream& operator>>(ifstream& ifs, University& u) {
	char waste[100];
	int _noOfTeachers;
	Mystring _name;
	Mystring* _teacherNames;
	int* _teacherId;
	int* _teacherSalaries;
	

	// Read and discard initial lines until reaching the relevant data
	// Read University name
	ifs.getline(waste, 99, ':');
	ifs.getline(waste, 99); // Reading new line after ':'
	_name = Mystring(waste);

	// Read the number of teachers
	ifs.getline(waste, 99, ':');
	ifs >> _noOfTeachers;
	ifs.get(); // Consuming newline character

	// Allocate memory for teacher names, IDs, and salaries
	_teacherNames = new Mystring[_noOfTeachers];
	_teacherId = new int[_noOfTeachers];
	_teacherSalaries = new int[_noOfTeachers];

	// Read teacher IDs
	ifs.getline(waste, 99, ':');
	for (int i = 0; i < _noOfTeachers; ++i) 
	{
		ifs >> _teacherId[i];
	}
	ifs.get(); // Consuming newline character

	// Read teacher names
	ifs.getline(waste, 99, ':');
	waste[0] = '\0';
	for (int i = 0; i < _noOfTeachers; ++i) 
	{
		ifs.getline(waste, 99,' ');
		_teacherNames[i] = Mystring(waste);
	}
	ifs.get(); // Consuming newline character

	// Read teacher salaries
	ifs.getline(waste, 99, ':');
	for (int i = 0; i < _noOfTeachers; ++i)
	{
		ifs >> _teacherSalaries[i];
	}

	u.setName(_name);
	u.setNoOfTeachers(_noOfTeachers);
	u.setTeacherId(_teacherId);
	u.setTeacherNames(_teacherNames);
	u.setTeacherSalaries(_teacherSalaries);

	// Cleanup memory
	delete[] _teacherNames;
	delete[] _teacherId;
	delete[] _teacherSalaries;

	return ifs;
}

ostream& operator<<(ostream& os, const University& u)
{
	os << "\nName of University: " << u.getName();
	os << "\nThe Number Of Teachers are: " << u.getNoOfTeachers();
	os << "\nTeacher IDs: ";
	for (int i = 0; i < u.getNoOfTeachers(); ++i)
	{
		os << u.getTeacherId()[i] << " ";
	}
	os << "\nThe Names of the Teachers are: ";
	
	for (int i = 0; i < u.getNoOfTeachers(); ++i)
	{
		os << u.getTeacherNames()[i] << " ";
	}
	os << "\nThe Salaries of the Teachers are: ";

	for (int i = 0; i < u.getNoOfTeachers(); ++i) {
		os << u.getTeacherSalaries()[i] << " ";
	}
	return os;
}

ofstream& operator<<(ofstream& ofs, University& u)
{
	ofs << "\nName of University: " << u.getName();
	ofs << "\nThe Number Of Teachers are: " << u.getNoOfTeachers();
	ofs << "\nTeacher IDs: ";
	const int* teacherIds = u.getTeacherId();
	for (int i = 0; i < u.getNoOfTeachers(); ++i)
	{
		ofs << teacherIds[i] << " ";
	}
	ofs << "\nThe Names of the Teachers are: ";

	const Mystring* teacherNames = u.getTeacherNames();
	for (int i = 0; i < u.getNoOfTeachers(); ++i)
	{
		ofs << teacherNames[i].getname() << " ";
	}
	ofs << "\nThe Salaries of the Teachers are: ";
	const int* teacherSalaries = u.getTeacherSalaries();
	for (int i = 0; i < u.getNoOfTeachers(); ++i) 
	{
		ofs << teacherSalaries[i] << " ";
	}
	return ofs;
}