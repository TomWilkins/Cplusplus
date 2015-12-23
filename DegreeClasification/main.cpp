#include <iostream>

using namespace std;

static string findClassification1(int mark){

    if(mark >= 0 && mark <=39)
        return "Fail";
    else if(mark >= 40 && mark <=49)
        return "III";
    else if(mark >= 50 && mark <=59)
        return "II(2)";
    else if(mark >= 60 && mark <=69)
        return "I(1)";
    else if(mark >= 70 && mark <=100)
        return "I";
    else
        return "Invalid mark.";

}

static string findClassification2(int mark){

    string result;

    switch(mark) {
        case 0 ... 39:
            result = "Fail";
            break;
        case 40 ... 49:
            result = "III";
            break;
        case 50 ... 59:
            result = "II(2)";
            break;
        case 60 ... 69:
            result = "II(1)";
            break;
        case 70 ... 100:
            result = "I";
            break;
        default: result = "Invalid mark";
    }
    return result;
}

int main() {
    cout << "Degree Classification" << endl;
    cout << "Using if statements...." << endl;
    cout << "With a mark of 10, you got: " << findClassification1(10) << endl;
    cout << "With a mark of 40, you got: " << findClassification1(40) << endl;
    cout << "With a mark of 50, you got: " << findClassification1(50) << endl;
    cout << "With a mark of 60, you got: " << findClassification1(60) << endl;
    cout << "With a mark of 70, you got: " << findClassification1(70) << endl;
    cout << "With a mark of 100, you got: " << findClassification1(100) << endl;
    cout << "With a mark of -50, you got: " << findClassification1(-50) << endl;
    cout << "Using switch statements...." << endl;
    cout << "With a mark of 10, you got: " << findClassification2(10) << endl;
    cout << "With a mark of 40, you got: " << findClassification2(40) << endl;
    cout << "With a mark of 50, you got: " << findClassification2(50) << endl;
    cout << "With a mark of 60, you got: " << findClassification2(60) << endl;
    cout << "With a mark of 70, you got: " << findClassification2(70) << endl;
    cout << "With a mark of 100, you got: " << findClassification2(100) << endl;
    cout << "With a mark of -50, you got: " << findClassification2(-50) << endl;


    return 0;
}