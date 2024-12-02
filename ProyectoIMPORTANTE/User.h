#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    int id;
    string name;
    string email;
    string joinDate;

    User(int id, string name, string email, string joinDate);
};

#endif // USER_H
