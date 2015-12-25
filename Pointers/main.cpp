#include <iostream>

using namespace std;

int main() {

    // Example 1

    int  var1;
    char var2[10];

    cout << "Address of var1 variable: ";
    cout << &var1 << endl;

    cout << "Address of var2 variable: ";
    cout << &var2 << endl;


    // Example 2

    int  *var3;
    char *var4[10];

    cout << "Pointer of var3 variable: ";
    cout << var3 << endl;

    cout << "Pointer of var4 variable: ";
    cout << var4 << endl;


    // Example 3

    int  var = 20;   // actual variable declaration.
    int  *ip;        // pointer variable

    ip = &var;       // store address of var in pointer variable

    cout << "Value of var variable: ";
    cout << var << endl;

    // print the address stored in ip pointer variable
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // access the value at the address available in pointer
    cout << "Value of *ip variable: ";
    cout << *ip << endl;


    // Example 4

    // declare simple variables
    int    i;
    double d;

    // declare reference variables
    int&    r = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;

    return 0;
}