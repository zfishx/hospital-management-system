#include <string>
#include <vector>

class Medicine {
private:
    string name;             // Name of the medication
    int dosage;              // Dosage of the medication: 每次多少
    int frequency;           // Frequency of medication：每日几次
    int duration;            // Duration of medication: 多少天

public:
    // Constructors
    Medicine();
    Medicine(string name, int dosage, int frequency, int duration);
    void printDetails();
    string getname();
    int getdosage();
    int getfrequency();
    int getduration();
};
