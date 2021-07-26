#ifndef CLASS3_HPP_INCLUDED
#define CLASS3_HPP_INCLUDED

template <typename T>
class CMyCleverPtr
{
   public:
    CMyCleverPtr(T * _ptr):ptr(_ptr){printf("CMyCleverPtr()\n");};
    ~CMyCleverPtr(){delete ptr;printf("~CMyCleverPtr()\n");};
    T * operator -> (){ return ptr;};
    T & operator * () {return *ptr;};
   private:
    T * ptr;
};

class CMy1
{
    public:
        CMy1(int _var = 0):myVar(_var){printf("CMy1()\n");};
        ~CMy1(){printf("~CMy1()\n");};
        void print(){printf("myVar=%d\n", myVar);};
        void setVar (int _var){myVar=_var;};
    private:
        int myVar;
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
