#include <iostream>
#include <vector>

using namespace std;

class firstClass
{
    public:
        firstClass( int num = 2);
        firstClass( firstClass & fClass);
        firstClass & operator=(firstClass & fClass);
        ~firstClass();
        void setVar (int _var);
    private:
        int myVar;
        static const int arrSize = 50;
        int arrNums[arrSize];

        enum { arrSize2 = 3 };
        int arrNums2[arrSize2];

        static const int constVar;

};

template <typename T> T addNumbers (T n1, T n2)
{
    T num3 = 0;
    num3 = n1 +n2;
    cout << "templateFunc, num3 = " << num3 << endl;
    return num3;
};

//template <typename T> inline void funcMax (T )

#define FUNC_MAX(a,b)  ((a) > (b)? (a): (b))

const char* const name1 = "12345678";
const string name2 = "123456789";

template <typename T>
inline void inFunc ( const T& arg1, const T& arg2 )
{
    string res = "";
    (arg1 > arg2)? res="arg1": res="arg2";
    cout << "inFunc RES = "<< res << endl;
}


