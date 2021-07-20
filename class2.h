#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED

#include "iostream"
using namespace std;

/// Раннее связывание early (static) binding
/// Связывание на этапе компилляции. Родитель ничего не знает о потомках.
/// Если удалить родителя, то объект потомка так и останется висеть в динамической памяти
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

/// Позднее связывание late (dynamic) binding
/// Связывание на этапе выполнения программы.
/// При разрушении объекта берется указатель на класс,
/// затем из таблицы виртуальных функций определяется адрес нужного нам деструктора,
/// а это деструктор производного класса, который после своей работы, как и полагается, вызывает деструктор базового
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
