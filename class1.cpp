#include "class1.hpp"

firstClass::firstClass( int num )
{
    myVar = 0;
    cout << "HELLO, MATHERFUCKER!!! num = "<< num << endl;
    cout << "arrSize = "<< arrSize << endl;
    cout << "name1 = "<< name1 << endl;
    cout << "name2 = "<< name2 << endl;
    cout << "constVar = "<< constVar << endl;
};

firstClass::firstClass( firstClass & fClass )
{
    myVar = fClass.myVar;
    cout << "HELLO, MATHERFUCKER!!! COPY, myVar = " << myVar << endl;
};

firstClass& firstClass::operator=(firstClass & fClass)
{
    myVar = fClass.myVar;
    cout << "HELLO, MATHERFUCKER!!! operator=, myVar = " << myVar << endl;
    return fClass;
};

firstClass::~firstClass()
{

};

void firstClass::setVar (int _var)
{
    myVar = _var;
};

const int firstClass::constVar = 88;
