

#include<iostream>

#include<fstream>
#include"Mystring.h"
#include"University.h"
using namespace std;

int main() 
{ // Create a University Object
    Mystring teacherNames[] = { "Teacher1", "Teacher2", "Teacher3", "Teacher4", "Teacher5" };
    int teacherSalaries[] = { 50000, 60000, 55000, 58000, 52000 };
    int teacherIDs[] = { 1, 2, 3, 4, 5 };

    University ucp("University of Central Punjab", teacherNames, teacherSalaries, teacherIDs, 5);

    // Display University Data
    cout << "University Data:\n" << ucp;

    // Call public find function and display results (Assuming a find function in University class)
    Mystring teacherInfo = ucp.find(3); // Assuming 3 is the ID for the teacher to find
    cout << "Teacher with ID 3: " << teacherInfo << std::endl;

    // Write University Object Data to File using >>
    ofstream outFile("university_data.txt");
    if (outFile.is_open())
    {
        outFile << ucp;
        outFile.close();
    }

    // Read University Data from another Text File in a new university object using <<
    University newUniversity;
    ifstream inFile("university_data.txt");
    if (inFile.is_open()) {
        inFile >> newUniversity;
        inFile.close();
    }
    
    // Display New University Data
    cout << "New University Data from File:\n";
    cout<<newUniversity;

    return 0;
}
