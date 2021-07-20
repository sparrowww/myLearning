#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include "iostream"
using namespace std;

/// ������ ���������� early (static) binding
/// ���������� �� ����� �����������. �������� ������ �� ����� � ��������.
/// ���� ������� ��������, �� ������ ������� ��� � ��������� ������ � ������������ ������
class staticBindingParent
{
    public:
        staticBindingParent() { cout << "A()" << endl;};
        ~staticBindingParent() { cout << "~A()" << endl;};
};

class staticBindingChild : public staticBindingParent
{
    public:
        staticBindingChild() { cout << "B()" << endl;};
        ~staticBindingChild() { cout << "~B()" << endl;};
};

/// ������� ���������� late (dynamic) binding
/// ���������� �� ����� ���������� ���������.
/// ��� ���������� ������� ������� ��������� �� �����,
/// ����� �� ������� ����������� ������� ������������ ����� ������� ��� �����������,
/// � ��� ���������� ������������ ������, ������� ����� ����� ������, ��� � ����������, �������� ���������� ��������
class dynamicBindingParent
{
    public:
        dynamicBindingParent() { cout << "C()" << endl;};
        virtual ~dynamicBindingParent() { cout << "~C()" << endl;};
};

class dynamicBindingChild : public dynamicBindingParent
{
    public:
        dynamicBindingChild() { cout << "D()" << endl;};
        virtual ~dynamicBindingChild() { cout << "~D()" << endl;};
};


#endif // CLASS2_H_INCLUDED
