// classes example
#include <iostream>
#include <string>

using namespace std;

class User {
  public:
    string name;
    int age = 1;
    int height;
    User();
};

User::User(void) {
   cout << "Object User is being created" << endl;
}