#ifndef ADMIN
#define ADMIN
using namespace std;

class admin
{
private:
    int id;
    string name;
    string password;
    static int count;
public:
    admin();
    ~admin();
    void fillMap();
    void saveMap();
    void addAdmin();
    void removeAdmin();
    int getid();
    string getname();
    string getpassword();
};
#endif // !APPOINTMENT