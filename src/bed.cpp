using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/bed.hh"
#include "./../include/hospital.hh"

bed::bed()
{
    id = -1;
    patientId = -1;
    isOccupied = false;
}
bed::~bed()
{
    id = -1;
    patientId = -1;
    isOccupied = false;
    return;
}
bed::bed(int id)
{
    this->id = id;
    patientId = -1;
    isOccupied = false;
}
bed::bed(int id, int patientId)
{
    this->id = id;
    this->patientId = patientId;
    isOccupied = true;
}
void bed::fillMap()
{
    for(int i=1;i<=hospital::bedsLimit;i++){
        bed b(i);
        hospital::bedsList[i] = b;
        //printf("bed occupied: %d\n", b.getisOccupied());
    }
    fstream f;
    f.open("./data/beds.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        bed b;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s2;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s2, ',');
        b.id = strToNum(s1);
        b.patientId = strToNum(s2);
        b.isOccupied = true;
        hospital::bedsList[b.id] = b;
    }
    f.close();
    return;
}
void bed::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "bedId,patientId\n";
    for (auto i : hospital::bedsList){
        if(i.second.getisOccupied()) f << i.second.id << "," << i.second.patientId << "\n";
    }
    f.close();
    remove("./data/beds.csv");
    rename("./data/temp.csv", "./data/beds.csv");
    return;
}
void bed::printDetails()
{
    if (id == -1)
    {
        return;
    }
    cout << "Bed id: " << id << "\n";
    cout << "Patient id: " << patientId << "\n";
    cout << "Occupied: " << (isOccupied ? "Yes" : "No") << "\n";
    return;
}
void bed::searchBed()
{
    int patiendId;
    cout << "Enter patient id: ";
    cin >> patiendId;
    for(auto i : hospital::bedsList){
        if(i.second.patientId == patiendId){
            i.second.printDetails();
        }
    }
    return;
}
int bed::getId()
{
    return id;
}
int bed::getpatientId()
{
    return patientId;
}
bool bed::getisOccupied()
{
    return isOccupied;
}
void bed::setpatientId(int patientId)
{
    this->patientId = patientId;
    return;
}
void bed::setisOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
    return;
}