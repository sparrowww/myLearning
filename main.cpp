#include <iostream>

#include <algorithm>
#include <vector>
#include <time.h>

#include "class1.hpp"

using namespace std;

int funcInMain()
{
    firstClass fC(19);
    fC.setVar(189);
    firstClass fC1(fC);
    firstClass fC2(42);
    fC2 = fC1;
    firstClass fC3(fC2);
    cout << "Hello world!" << endl;
    addNumbers(1.0,5.2);
    addNumbers(1,5);

    int num1 = 4;
    int num2 = 47;
    cout << "FUNC_MAX = " << FUNC_MAX(num1,num2)<< endl;
    inFunc<float>(80,79.9);

    vector<int> vectrInt (10);
    vector<int>::iterator  vectrIntItr;
    vectrInt.push_back(16);
    vectrInt.at(0) = 1;
    vectrInt.push_back(10);
    vectrInt.push_back(18);
    vectrInt.at(3) = 777;

    vectrIntItr = vectrInt.begin();
    while (vectrIntItr != vectrInt.end())
    {
        cout << "VECTOR = "<< (*vectrIntItr) << endl;
        vectrIntItr++;
    }
    return 0;
};

bool funcMin (int i,int j)
{
    return (i<j);
};

int main()
{
    cout << "funcInMain START" << endl;
    funcInMain();
    cout << "funcInMain STOP" << endl;


    vector<int> myVector (50);

    srand(time(NULL));
    cout <<"AFTER GENERATE:"<< endl;
    generate(myVector.begin(), myVector.end(), [] () {return (rand()%100);});

    for_each ( myVector.begin(), myVector.end(), []( int arrElement ) { cout << arrElement <<"|"; } );

    cout << endl;
    cout <<"AFTER SORT (MIN > MAX):"<< endl;
    sort ( myVector.begin(), myVector.end(), funcMin);
    for_each ( myVector.begin(), myVector.end(), []( int arrElement ) { cout << arrElement <<"|"; } );
    cout << endl;

    cout <<"AFTER SORT (MAX > MIN):"<< endl;
    sort ( myVector.begin(), myVector.end(), [] (int i, int j) {return i > j;}); // NOTE with Lambda func
    for_each ( myVector.begin(), myVector.end(), []( int arrElement ) { cout << arrElement <<"|"; } );
    cout << endl;


    int arrI[] = {112,2,84};
    int * beginArrPtr = begin(arrI);
    int * endArrPtr = end(arrI);

    cout << "beginArr = " << *beginArrPtr << endl;
    cout << "endArr = " << *(endArrPtr-1) << endl;

    for_each ( beginArrPtr, endArrPtr, []( int arrElement ) { cout << arrElement <<"|"; } );
    cout << endl;

    cout << "return 0" << endl;
    return 0;
}


