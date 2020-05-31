#include <iostream>
#include <list>
#include <typeinfo>
#include <cstdlib>

using namespace std;


class FRangoExc{
};


template <class T> class Iterar {
    T *ptr;
    T *fin;
    T *inic;
    unsigned length;
public:
    Iterar(){
        ptr = fin = inic = NULL;
        lenght = 0;
    }
    Iterar(T *p, T *prim, T *ult){
        ptr = p;
        fin = ult;
        inic = prim;
        length = ult - prim;
    }
    unsigned size(){
        return length;
    }
    T &operator*(){
        if ((ptr >= fin)|| (ptr < inic))
            throw FRangoExc();
        return *ptr;                
    }
    T *operator->(){
        if( (ptr >= fin) || (ptr < inic) )
            throw FRangoExc();

    }
    Iterar operator++(){
        ptr++;
        return *this;
    }
    Iterar operator--(){
        ptr--;
        return *this;
    }

    Iterar operator++(int notused) {
        T *temp = ptr;
        ptr++;
        return Iterar<T>(temp, inic, fin);
    }
    Iterar operator--(int notused) {
        T *temp = ptr;
        ptr--;
        return Iterar<T>(temp, inic, fin);
    }
    T &operator[](int i) {
        if( (i < 0) || (i >= (fin-inic)) )
            throw FRangoExc();
        return ptr[i];
    }
    bool operator==(Iterar op2) {
        return ptr == op2.ptr;
    }
    bool operator!=(Iterar op2) {
        return ptr != op2.ptr;
    }
    bool operator<(Iterar op2) {
        return ptr < op2.ptr;
    }
    bool operator<=(Iterar op2) {
        return ptr <= op2.ptr;
    }
    bool operator>(Iterar op2) {
        return ptr > op2.ptr;
    }
    bool operator>=(Iterar op2) {
        return ptr >= op2.ptr;
    }
    Iterar operator-(int n) {
        ptr -= n;
        return *this;
    }
    Iterar operator+(int n) {
        ptr += n;
        return *this;
    }
    int operator-(Iterar<T> &itr2) {
        return ptr - itr2.ptr;
    }
};
template <class T> class GCInfo {
public:
    unsigned refcount;
    T *memoryP;
    bool isArray;
    unsigned TArray;
    GCInfo(T *mPt, unsigned size = 0) {
        refcount = 1;
        memoryP = mPt;
        if(size != 0)
            isArray = true;
        else
            isArray = false;
        TArray = size;
    }
};

template <class T> bool operator == (const GCInfo<T> &ob1, const GCInfo<T> &ob2) {
    return (ob1.memoryP == ob2.memoryP);
}
template <class T, int size=0> class GCPointer{
    static list<GCInfo<T> > gclist;
    T *addr;
    bool isArray;
    unsigned TArray;
    static bool prim;
public:
    typedef Iterar<T> GCiterator;
    GCPointer(T *t=NULL){
        if(prim)
            atexit(shutdown);
        prim = false;
        list<GCInfo<T> >::iterator p;
        p = findPtrInfo(t);
        if(p != gclist.end())
            p->refcount++;
        else {
            GCInfo<T> gcObj(t, size);
            gclist.push_front(gcObj);
        }
        addr = t;
        TArray = size;
        if(size > 0) 
            isArray = true;
        else 
            isArray = false;
        #ifdef DISPLAY
            cout << "Constructing GCPtr. ";
            if(isArray)
                cout << " Size is " << arraySize << endl;
            else
                cout << endl;
        #endif
    }
}