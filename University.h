#pragma once

class University
{
private:
	Mystring name;
	Mystring* teacherNames;
	int* teacherId;
	int* teacherSalaries;
	int noOfTeachers;  //whereas noOfTeachers keep a record of exact number of teachers
	//to help keep a better code format
public:
	University();//Default
	//Parametrized
	University(const Mystring& _uniName, const Mystring* _teacherNames, const int* _teacherSalaries, const int* _teacherIds, const int& _noOfteachers);
	//Copy constructor
	University(const University&);
	//Destructor
	~University();
	University& operator=(const University&);
	//bool operator==(const University& other) const;
	void setName(const Mystring& s);
	void setTeacherNames(const Mystring* s);
	void setTeacherId(const int* _teacherSalaries);
	void setTeacherSalaries(const int* _teacherIds);
	void setNoOfTeachers(const int& _noOfteachers);
	const Mystring getName() const { return name; }
	const Mystring* getTeacherNames() const { return teacherNames; }
	const int* getTeacherId() const { return teacherId; }
	const int* getTeacherSalaries() const { return teacherSalaries; }
	const int getNoOfTeachers() const { return noOfTeachers; }
	int calculateSalary()const;
	Mystring find(const int& empID);
};

istream& operator>>(istream& is, University& u);
ostream& operator<<(ostream& os, const University& u);


ifstream& operator>>(ifstream& ifs, University& u);
ofstream& operator<<(ofstream& ofs, University& u);

