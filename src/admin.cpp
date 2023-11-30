using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/hospital.hh"
#include "./../include/admin.hh"

admin::admin()
{
    name = -1;
    password = "";
}
admin::~admin()
{
    name = -1;
    password = "";
    return;
}
void admin::fillMap()
{
    fstream f;
    f.open("./data/admins.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        admin a;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s2, s3;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s2, ',');
        getline(s, s3, ',');
        a.id = strToNum(s1);
        a.name = s2;
        a.password = s3;
        hospital::adminsList[a.id] = a;
        count = max(count, a.id);
    }
    f.close();
    return;
}
void admin::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "adminId,adminName,password\n";
    for (auto i : hospital::adminsList)
    {
        f << i.second.id << "," << i.second.name << "," << i.second.password << "\n";
    }
    f.close();
    remove("./data/admins.csv");
    rename("./data/temp.csv", "./data/admins.csv");
    return;
}
void admin::addAdmin()
{
    admin a;
    cout << "Enter the name of the admin: ";
    cin >> a.name;
    for (auto i : hospital::adminsList)
    {
        if(i.second.name == a.name)
        {
            cout << "Admin already exists! Please use another name.\n";
            return;
        }
    }
    cout << "Enter the password of the admin: ";
    cin >> a.password;
    a.id = ++count;
    hospital::adminsList[a.id] = a;
    return;
}
void admin::removeAdmin()
{
    string name;
    cout << "Enter the name of the admin to be removed: ";
    cin >> name;
    for (auto i : hospital::adminsList)
    {
        if(i.second.name == name)
        {
            hospital::adminsList.erase(i.first);
            return;
        }
    }
}
int admin::getid()
{
    return id;
}
string admin::getname()
{
    return name;
}
string admin::getpassword()
{
    return password;
}