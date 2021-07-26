#include <iostream>

#include <algorithm>
#include <vector>
#include <time.h>
#include <memory> ///unique_ptr

#include "class1.hpp"
#include "class2.h"
#include "class3.hpp"

using namespace std;

int funcInMain();
void lambdaTest ();
void cleverPtrTest ();
void mySingletonTest ();
void myCastTest();

int main()
{
    //funcInMain();
    //lambdaTest();
    //cleverPtrTest();
    //mySingletonTest();
    myCastTest();



    cout << "return 0" << endl;
    return 0;
};

typedef int TMyInt;

void myCastTest()
{
    cout << "myCastTest BEGIN" << endl;

    int iVar = 10;
    TMyInt MyVar = 11;
    float fVar = 10.15;
    printf("print1 = %ld\n", (long int)iVar);  // C type
    printf("print2 = %d\n", reinterpret_cast<int>(MyVar));  // reinterpret_cast type
    printf("print3 = %f\n", static_cast<double>(fVar));  // static_cast type
    cout << "myCastTest END" << endl;
};

void cleverPtrTest ()
{
    cout << "cleverPtrTest BEGIN MY" << endl;
    {
       CMyCleverPtr<CMy1> clever = CMyCleverPtr<CMy1>(new CMy1(42));
       clever->print();
       clever->setVar(43);
       (*clever).print();
    }

    cout << "cleverPtrTest BEGIN UNIQUE" << endl;
    {
       unique_ptr<CMy1> uniqPtr = unique_ptr<CMy1>(new CMy1(88));
       uniqPtr->print();
    }

    cout << "cleverPtrTest BEGIN SHARED" << endl;
    {
        auto ptrCMy1 = new CMy1(100);
        shared_ptr<CMy1> sharedPtr = shared_ptr<CMy1>(ptrCMy1);
        sharedPtr->print();
        shared_ptr<CMy1> sharedPtr2 = shared_ptr<CMy1>(sharedPtr);
        sharedPtr2->print();
        auto numPtr = sharedPtr.use_count();
        printf ("numPtr = %ld\n", numPtr);
    }

    cout << "cleverPtrTest END" << endl;
};

void mySingletonTest ()
{
    CMySingleton *oMySingle = CMySingleton::getInstance();
    oMySingle->setVar(42);
    cout << "oMySingle getVar=" << oMySingle->getVar() << endl;
    CMySingleton *oMySingle2 = CMySingleton::getInstance();
    cout << "oMySingle2 getVar=" << oMySingle2->getVar() << endl;
    oMySingle->setVar(11);
    CMySingleton *oMySingle3 = CMySingleton::getInstance();
    cout << "oMySingle3 getVar=" << oMySingle3->getVar() << endl;
};

int funcInMain()
{
    firstClass fC(19);
    fC.setVar(189);
    firstClass fC1(fC);
    firstClass fC2(42);
    fC2 = fC1;
    firstClass fC3(fC2);
    cout << "Hello world!!!" << endl;
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

void lambdaTest ()
{
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

    staticBindingChild * staticChild = new staticBindingChild;
    delete staticChild;
    staticChild = nullptr;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    staticBindingParent * staticParent = new staticBindingChild;
    delete staticParent;
    staticParent = nullptr;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    dynamicBindingChild * dynamicChild = new dynamicBindingChild;
    delete dynamicChild;
    dynamicChild = nullptr;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    dynamicBindingParent * dynamicParent = new dynamicBindingChild;
    delete dynamicParent;
    dynamicParent = nullptr;


    auto myLambda = [](int a, int b) -> int{return a*b;};
    int num = myLambda(6,11);

    int numToChange = 77;
    int num2 = ([](int a, int b, int &c) -> int{ c -=70;return a*b;})(8,8, numToChange);

    cout << "LAMBDA = " << num << endl;
    cout << "LAMBDA2 = " << num2 << endl;
    cout << "LAMBDA2, numToChange= " << numToChange << endl;
};


