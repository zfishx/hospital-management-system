#ifndef BED
#define BED
using namespace std;

#include "./patient.hh"

class bed
{
private:
    int id;
    int patientId;
    bool isOccupied;
public:
    bed();
    ~bed();
    bed(int id);
    bed(int id, int patientId);
    void fillMap();
    void saveMap();
    void printDetails();
    void searchBed();
    int getId();
    int getpatientId();
    bool getisOccupied();
    void setpatientId(int patientId);
    void setisOccupied(bool isOccupied);
};
#endif // !BED