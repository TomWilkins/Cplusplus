#include <iostream>

using namespace std;

void usingForLoop(){
    char theString[] = "Hello, World";

    // size of the char array, -1 for null terminator.
    int size = sizeof(theString)-1;

    char reversedString[size];

    for(int i = 0; i < size; i++){
        char a = theString[size-1-i];
        reversedString[i] = a;
    }

    cout << "The original string was: '" << theString << "'." << endl;
    cout << "The reversed string was: '" << reversedString << "'." << endl;
}

void usingPointers(){
    char theString[] = "Hello, World";
    cout << "The original string was: '" << theString << "'." << endl;

    int nChars = sizeof(theString) -1;
    char *pStart = theString;
    char *pEnd = theString + nChars - 1;

    while(pStart < pEnd){

        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        pStart++;
        pEnd--;
    }


    cout << "The reversed string was: '" << theString << "'." << endl;
}


int main() {

    usingPointers();
    return 0;
}