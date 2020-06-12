#include <iostream>
#include <list>
#include <typeinfo>
#include <cstdlib>

using namespace std;


class FRangoExc{
};


template <class T> class Iterar {// Clase iterador para ciclar por arrays
    T *ptr;//Punteros del iterador
    T *fin;
    T *inic;
    unsigned length;//Largo del array
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
    unsigned size(){// Retorna el largo
        return length;
    }
    T &operator*(){//Retorna el valor apuntado por el puntero del iterador
        if ((ptr >= fin)|| (ptr < inic))
            throw FRangoExc();
        return *ptr;                
    }
    T *operator->(){//Retorna la distancia del puntero
        if( (ptr >= fin) || (ptr < inic) )
            throw FRangoExc();
        return ptr
    }
    Iterar operator++(){//Suma
        ptr++;
        return *this;
    }
    Iterar operator--(){//Resta
        ptr--;
        return *this;
    }

    Iterar operator++(int notused) {
        T *temp = ptr;
        ptr++;
        return Iterar<T>(temp, inic, fin);
    }
    Iterar operator--(int notused) {//Retorna la referencia al objeto en el index
        T *temp = ptr;
        ptr--;
        return Iterar<T>(temp, inic, fin);
    }
    T &operator[](int i) {
        if( (i < 0) || (i >= (fin-inic)) )
            throw FRangoExc();
        return ptr[i];
    }
    bool operator==(Iterar op2) {//Operadores relacionales
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
    Iterar operator-(int n) {//Resta un int a un iterador
        ptr -= n;
        return *this;
    }
    Iterar operator+(int n) {//Agrega un int a un iterador
        ptr += n;
        return *this;
    }
    int operator-(Iterar<T> &itr2) {//Numero de elementos entre iteradores
        return ptr - itr2.ptr;
    }
};
template <class T> class GCInfo {//Se definen los elementos que se definen en el garbage collector
public:
    unsigned refcount;//CUenta las referencias
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
template <class T, int size=0> class GCPointer{// Esta Clase debe ser cambiada por VSPointer
//Aqui se implementa el vspointer (Comparar con lo requerido en vspointer para saber que
// se queda y que se adapta)
    static list<GCInfo<T> > gclist;//lista del garbage collector
    T *addr;
    bool isArray;
    unsigned TArray;
    static bool prim;
    typename list<GCInfo<T> >::iterator findPtrInfo(T *ptr);
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
    GCPointer(const GCPointer &ob) {
        list<GCInfo<T> >::iterator p;
        p = findPtrInfo(ob.addr);
        p->refcount++;
        addr = ob.addr;
        TArray = ob.arraySize;
        if(TArray > 0) 
            isArray = true;
        else 
            isArray = false;
        #ifdef DISPLAY
            cout << "Constructing copy.";
            if(isArray)
                cout << " Size is " << arraySize << endl;
            else
                cout << endl;
        #endif
    }
    ~GCPointer();
    static bool collect();
    T *operator=(T *t);
    GCPointer &operator=(GCPointerr &rv);
    T &operator*() {
        return *addr;
    }
    T *operator->() {
         return addr; 
    }
    T &operator[](int i) {
        return addr[i];
    }
    operator T *() {
        return addr; 
    }
    Iterar<T> begin() {
        int size;
        if(isArray) 
            size = TArray;
        else 
            size = 1;
        return Iterar<T>(addr, addr, addr + size);
    }
    Iterar<T> end() {
        int size;
        if(isArray) 
            size = TArray;
        else 
            size = 1;
        return Iterar<T>(addr + size, addr, addr + size);
    }
    static int gclistSize() {
        return gclist.size(); 
    }
    static void showlist();
    static void shutdown();
};
template <class T, int size>
    list<GCInfo<T> > GCPointer<T, size>::gclist;

template <class T, int size>
    bool GCPointer<T, size>::first = true;

template <class T, int size>
GCPointer<T, size>::~GCPointer() {
    list<GCInfo<T> >::iterator p;
    p = findPtrInfo(addr);
    if(p->refcount) 
        p->refcount--;
    #ifdef DISPLAY
        cout << "GCPtr going out of scope.\n";
    #endif
}
template <class T, int size>
bool GCPtr<T, size>::collect() {
    bool memfreed = false;
    #ifdef DISPLAY
        cout << "Before garbage collection for ";
        showlist();
    #endif
    list<GCInfo<T> >::iterator p;
    do {
        for(p = gclist.begin(); p != gclist.end(); p++) {
            if(p->refcount > 0) continue;
            memfreed = true;
            gclist.remove(*p);
            if(p->memoryP) {
                if(p->isArray) {
                    #ifdef DISPLAY
                        cout << "Deleting array of size "
                            << p->arraySize << endl;
                    #endif
                    delete[] p->memoryP;
                }
                else {
                    #ifdef DISPLAY
                        cout << "Deleting: "
                        << *(T *) p->memPtr << "\n";
                    #endif
                    delete p->memoryP;
                }
            }
            break;
        }
    } while(p != gclist.end());
    #ifdef DISPLAY
        cout << "After garbage collection for ";
        showlist();
    #endif
    return memfreed;
}
template <class T, int size>
T * GCPtr<T, size>::operator=(T *t) {
    list<GCInfo<T> >::iterator p;
    p = findPtrInfo(addr);
    p->refcount--;
    p = findPtrInfo(t);
    if(p != gclist.end())
        p->refcount++;
    else {
        GCInfo<T> gcObj(t, size);
        gclist.push_front(gcObj);
    }
    addr = t;
    return t;
}
template <class T, int size>
GCPointer<T, size> & GCPtr<T, size>::operator=(GCPtr &rv) {
    list<GCInfo<T> >::iterator p;
    p = findPtrInfo(addr);
    p->refcount--;
    p = findPtrInfo(rv.addr);
    p->refcount++;
    addr = rv.addr;
    return rv;
}
template <class T, int size>
void GCPointer<T, size>::showlist() {
    list<GCInfo<T> >::iterator p;
    cout << "gclist<" << typeid(T).name() << ", "
        << size << ">:\n";
    cout << "memoryP    refcount    value\n";  
    if(gclist.begin() == gclist.end()) {
        cout << "      -- Empty --\n\n";
        return;
}
for(p = gclist.begin(); p != gclist.end(); p++) {
    cout << "[" << (void *)p->memoryP << "]"    << "    " << p->refcount << "    ";
    if(p->memoryP) 
        cout << "    " << *p->memoryP;
    else 
        cout << "    ---";
        cout << endl;
    }
    cout << endl;
}
template <class T, int size>
typename list<GCInfo<T> >::iterator
    GCPointer<T, size>::findPtrInfo(T *ptr) {
    list<GCInfo<T> >::iterator p;
    for(p = gclist.begin(); p != gclist.end(); p++)
        if(p->memoryP == ptr)
            return p;
    return p;
}
template <class T, int size>
void GCPointer<T, size>::shutdown() {
    if(gclistSize() == 0) return;
    list<GCInfo<T> >::iterator p;
    for(p = gclist.begin(); p != gclist.end(); p++) {
        p->refcount = 0;
    }
    #ifdef DISPLAY
        cout << "Before collecting for shutdown() for "
             << typeid(T).name() << "\n";
    #endif
    collect();
    #ifdef DISPLAY
        cout << "After collecting for shutdown() for "
             << typeid(T).name() << "\n";
    #endif
}




