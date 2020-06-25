#include <iostream>
#include "md5.h"
#include "md5.cpp"
using namespace std;
using std::cin;
using std::cout; 
using std::endl;

int main(int argc, char *argv[])
{
    string password;
    cout << "Digite password: ";
    cin >> password;
    cout << "md5 of " + password + " is:" << md5(password) << endl;
    return 0;
}