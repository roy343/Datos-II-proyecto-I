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


//#include <iostream>
//#include <new>
//#include "GarbageCollector.h"

//using namespace std;



/*int main() {

    GCPointer<int> p;
    
    try {
        p = new int;
    } catch(bad_alloc exc) {
        cout << "Allocation failure!\n";
        return 1;
    }
    *p = 88;
    cout << "Value at p is: " << *p << endl;
    int k = *p;
    cout << "k is " << k << endl;
    return 0;
}*/