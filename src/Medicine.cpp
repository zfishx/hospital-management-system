using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/Medicine.hh"

// Constructor: Initializes a medicine with default values
Medicine::Medicine()
{
    name = "";
    dosage = -1;
    frequency = -1;
    duration = -1;
}
Medicine::Medicine(string name, int dosage, int frequency, int duration)
{
    this->name = name;
    this->dosage = dosage;
    this->frequency = frequency;
    this->duration = duration;
}
void Medicine::printDetails()
{
    cout << "Name: " << name << endl;
    cout << "Dosage: " << dosage << " for one time" << endl;
    cout << "Frequency: " << frequency << " for one day" << endl;
    cout << "Duration: " << duration << " days" << endl;
    return;
}
string Medicine::getname()
{
    return name;
}
int Medicine::getdosage()
{
    return dosage;
}
int Medicine::getfrequency()
{
    return frequency;
}
int Medicine::getduration()
{
    return duration;
}
