using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/hospital.hh"
#include "./../include/Prescription.hh"

// Constructor: Initializes a prescription with default values
Prescription::Prescription()
{
    id = -1;
    patient_id = -1;
    doctor_id = -1;
    medicines = {};
}
Prescription::~Prescription()
{
    id = -1;
    patient_id = -1;
    doctor_id = -1;
    medicines = {};
}
// Constructor: Initializes a prescription with given values
Prescription::Prescription(int id, int p_id, int d_id, vector<Medicine> medicines)
{
    this->id = id;
    patient_id = p_id;
    doctor_id = d_id;
    this->medicines = medicines;
}
void Prescription::fillMap()
{
    fstream fin;
    fin.open("./data/prescriptions.csv", ios::in);
    string line;
    getline(fin, line);
    while (getline(fin, line))
    {
        stringstream s(line);
        string word;
        getline(s, word, ',');
        cout<<id<<endl;
        id = stoi(word);   
        getline(s, word, ',');
        patient_id = stoi(word);
        getline(s, word, ',');
        doctor_id = stoi(word);
        getline(s, word, ',');
        medicines = {};
        stringstream ss(word);
        while (getline(ss, word, ';'))
        {
            stringstream sss(word);
            string name;
            int dosage, frequency, duration;
            getline(sss, name, ':');
            getline(sss, word, ':');
            dosage = stoi(word);
            getline(sss, word, ':');
            frequency = stoi(word);
            getline(sss, word, ':');
            duration = stoi(word);
            Medicine m(name, dosage, frequency, duration);
            medicines.push_back(m);
        }
        Prescription p(id, patient_id, doctor_id, medicines);
        hospital::PrescriptionList[id] = p;
        count = max(count, id);
    }
    fin.close();
    return;
}
void Prescription::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    f << "prescriptionId,patientId,doctorId,medicines\n";
    for (auto i : hospital::PrescriptionList)
    {
        f << i.second.id << "," << i.second.patient_id << "," << i.second.doctor_id << ",";
        for (auto j : i.second.medicines)
            f << j.getname() << ":" << j.getdosage() << ":" << j.getfrequency() << ":" << j.getduration() << ";";
        f << "\n";
    }
    f.close();
    remove("./data/prescriptions.csv");
    rename("./data/temp.csv", "./data/prescriptions.csv");
    return;
}
// Create a new prescription
void Prescription::createPrescription()
{
    // Get patient ID
    cout << "Enter patient ID: ";
    cin >> patient_id;

    // Get doctor ID
    cout << "Enter doctor ID: ";
    cin >> doctor_id;

    // Get medicines
    cout << "Enter number of medicines: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int dosage, frequency, duration;
        cout << "Enter medicine name: ";
        cin >> name;
        cout << "Enter dosage: ";
        cin >> dosage;
        cout << "Enter frequency: ";
        cin >> frequency;
        cout << "Enter duration: ";
        cin >> duration;
        Medicine m(name, dosage, frequency, duration);
        medicines.push_back(m);
    }
    id = ++count;
    hospital::PrescriptionList[id] = Prescription(id, patient_id, doctor_id, medicines);
    cout << "\nPrescription created successfully!" << endl;
    return;
}

// View details of the prescription
void Prescription::viewPrescription()
{
    // Get prescription ID
    cout << "Enter patient ID: ";
    int p_id;
    cin >> p_id;
    for (auto i : hospital::PrescriptionList)
    {
        if (i.second.patient_id == p_id)
        {
            i.second.printDetails();
        }
    }
    return;
}
void Prescription::printDetails()
{
    if(id == -1) return;
    cout << "Prescription ID: " << id << endl;
    cout << "Patient ID: " << patient_id << endl;
    cout << "Doctor ID: " << doctor_id << endl;
    cout << "Medicines: " << endl;
    for (auto j : medicines)
    {
        j.printDetails();
    }
    cout<<endl;
}