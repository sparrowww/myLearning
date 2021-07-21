#ifndef CLASS3_HPP_INCLUDED
#define CLASS3_HPP_INCLUDED

template <typename T>
class CMyCleverPtr
{
   public:
    CMyCleverPtr(T * _ptr):ptr(_ptr){printf("CMyCleverPtr()\n");};
    ~CMyCleverPtr(){delete ptr;printf("~CMyCleverPtr()\n");};
   private:
    T * ptr;
};

class CTestClever
{
    public:
        CTestClever(){printf("CTestClever()\n");};
        ~CTestClever(){printf("~CTestClever()\n");};
};

class CMySingleton
{
    public:
        static CMySingleton * getInstance ()
        {
            static CMySingleton *obj = new CMySingleton();
            return obj;
        };
        void setVar ( int _var) {var = _var;};
        int getVar () {return var;};
    protected:
        int var;
        CMySingleton():var(0){printf("CMySingleton()\n");};

};


#endif // CLASS3_HPP_INCLUDED
