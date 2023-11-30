#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
using namespace std;

#include "./patient.hh"
#include "./doctor.hh"
#include "./Medicine.hh"

class Prescription
{
private:
    int id;                          // Unique identifier for the prescription
    int patient_id;                  // ID of the patient
    int doctor_id;                   // ID of the prescribing doctor
    vector<Medicine> medicines;      // List of medicines prescribed
    static int count;                // Total number of prescriptions

public:
    // Constructors
    Prescription();
    ~Prescription();
    Prescription(int id, int p_id, int d_id, vector<Medicine> medicines);
    void fillMap();
    void saveMap();
    // Methods to manage prescription
    void createPrescription();       // Create a new prescription
    void viewPrescription();   // View details of the prescription
    void printDetails();               // Get details of the prescription

};


#endif // PRESCRIPTION_H
