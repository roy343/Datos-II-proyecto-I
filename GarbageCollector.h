#include <iostream>
#include <list>
#include <typeinfo>
#include <cstdlib>
//#define DISPLAY

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
        length = 0;
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
        if ((ptr >= fin)|| (ptr < inic)){
            throw FRangoExc();
        }
        return *ptr;                
    }
    T *operator->(){//Retorna la distancia del puntero
        if( (ptr >= fin) || (ptr < inic) ){
            throw FRangoExc();
        }
        return ptr;
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
        if( (i < 0) || (i >= (fin-inic)) ){
            throw FRangoExc();
        }
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
        if(size != 0){
            isArray = true;
        }
        else{
            isArray = false;
        }
        TArray = size;
    }
};

template <class T> bool operator==(const GCInfo<T> &ob1, const GCInfo<T> &ob2) {
    return (ob1.memoryP == ob2.memoryP);
}
template <class T, int size = 0 > class GCPointer{// Esta Clase debe ser cambiada por VSPointer
//Aqui se implementa el vspointer (Comparar con lo requerido en vspointer para saber que
// se queda y que se adapta)
    static list<GCInfo<T> > gclist;//lista del garbage collector
    T *addr;//Apunta hacia la memoria a la que cgpointer apunte
    bool isArray;
    unsigned TArray;//Atributo size de un array
    static bool prim;
    typename list<GCInfo<T> >::iterator findPtrInfo(T *ptr);
public:
    typedef Iterar<T> GCiterator;//Define un iterador para gcpointer
    GCPointer(T *t = NULL){//Constructor de objetos (no importa si no estan inicializados)
        if(prim){
            atexit(shutdown);//Registro de funcion de salida
        }
        prim = false;

        list<GCInfo<T> >::iterator p;//Dependiendo de la condicion aumenta el conteo de referencias
        p = findPtrInfo(t);
        if(p != gclist.end()){
            p->refcount++;//Aumento del conteo
        }
        else {
            GCInfo<T> gcObj(t, size);// Si no, crea y almacena la entrada
            gclist.push_front(gcObj);
        }

        addr = t;
        TArray = size;
        if(size > 0){
            isArray = true;
        }
        else{
            isArray = false;
        }
        #ifdef DISPLAY
            cout << "Construyendo GCPointer. ";
            if(isArray)
                cout << " Size es " << TArray << endl;
            else
                cout << endl;
        #endif
    }
    GCPointer(const GCPointer &ob) {//Se crea el copy constructor
        list<GCInfo<T> >::iterator p;
        p = findPtrInfo(ob.addr);
        p->refcount++;
        addr = ob.addr;
        TArray = ob.TArray;
        if(TArray > 0){
            isArray = true;
        }
        else{
            isArray = false;
        }
        #ifdef DISPLAY
            cout << "Construyendo copia.";
            if(isArray)
                cout << " El size es " << TArray << endl;
            else
                cout << endl;
        #endif
    }
    ~GCPointer();//Este es el destructor para el cgpointer
    static bool collect();//Recolecta la basura (Retorna true si un elemento fue liberado)
    T *operator=(T *t);

    GCPointer &operator=(GCPointer &rv);//Retorna la referencia del objeto apuntado
    T &operator*() {
        return *addr;
    }
    T *operator->() {//Retorna la direccion apuntada
         return addr; 
    }
    T &operator[](int i) {//Retorna una referencia al objeto que el indice apunta (i)
        return addr[i];
    }
    operator T *() {//Funcion conversora a T*
        return addr; 
    }
    Iterar<T> begin() {//Retorna un iterador al inicio de la memoria colocada
        int size;
        if(isArray){
            size = TArray;
        }
        else{
            size = 1;
        }
        return Iterar<T>(addr, addr, addr + size);
    }

    Iterar<T> end() {//Retorna un iterador a uno mas que el final de un array colocado
        int size;
        if(isArray){
            size = TArray;
        }
        else{
            size = 1;
        }
        return Iterar<T>(addr + size, addr, addr + size);
    }

    static int gclistSize() {//Retorna el size de un gclist para este tipo de puntero
        return gclist.size(); 
    }
    static void showlist();//Muestra la gclist
    static void shutdown();//Limpia la gclist
};
template <class T, int size>//Crea espacio para variables estaticas
    list<GCInfo<T> > GCPointer<T, size>::gclist;

template <class T, int size>
    bool GCPointer<T, size>::first = true;

template <class T, int size>//Destructor para Gcpointer
GCPointer<T, size>::~GCPointer() {
    list<GCInfo<T> >::iterator p;
    p = findPtrInfo(addr);
    if(p->refcount){
        p->refcount--;
    }
    #ifdef DISPLAY
        cout << "GCPointer se salio del alcance.\n";
    #endif
    collect();//REcolecta la basura cuando un puntero se sale de alcance
}

template <class T, int size>//Recolecta la basura
bool GCPointer<T, size>::collect() {
    bool memfreed = false;
    #ifdef DISPLAY
        cout << "Antes del garbage collection para ";
        showlist();
    #endif
    list<GCInfo<T> >::iterator p;

    do {//Escanea gclist en busca de punteros sin referenciar
        for(p = gclist.begin(); p != gclist.end(); p++) {
            if(p->refcount > 0) continue;
            memfreed = true;
            gclist.remove(*p);//Remueve entradas usadas del gclist
            if(p->memoryP) {//Libera la memoria a no ser que gcpointer sea null
                if(p->isArray) {
                    #ifdef DISPLAY
                        cout << "Borrando array de size "
                            << p->TArray << endl;
                    #endif
                    delete[] p->memoryP;//Borra el array
                }
                else {

                    #ifdef DISPLAY
                        cout << "Borrando: "
                        << *(T *) p->memoryP << "\n";
                    #endif
                    delete p->memoryP;//Borra un elemento
                }
            }

            break;//Break para reiniciar la busqueda
        }

    } while(p != gclist.end());
    #ifdef DISPLAY
        cout << "Despues del garbage collection para ";
        showlist();
    #endif
    return memfreed;
}

template <class T, int size>//Asignacion de overload de puntero a gcpointer
T * GCPointer<T, size>::operator=(T *t) {
    list<GCInfo<T> >::iterator p;
    p = findPtrInfo(addr);
    p->refcount--;
    p = findPtrInfo(t);
    if(p != gclist.end()){
        p->refcount++;
    }
    else {
        GCInfo<T> gcObj(t, size);
        gclist.push_front(gcObj);
    }

    addr = t;//Guarda la direccion
    return t;
}

template <class T, int size>//Asignacion de overload de gcpointer a gcpointer
GCPointer<T, size> & GCPointer<T, size>::operator=(GCPointer &rv) {
    list<GCInfo<T> >::iterator p;
    p = findPtrInfo(addr);
    p->refcount--;
    p = findPtrInfo(rv.addr);
    p->refcount++;
    addr = rv.addr;
    return rv;
}

template <class T, int size>//Muestra gclist
void GCPointer<T, size>::showlist() {
    list<GCInfo<T> >::iterator p;
    cout << "gclist<" << typeid(T).name() << ", "
        << size << ">:\n";
    cout << "memoryP    refcount    value\n";  
    if(gclist.begin() == gclist.end()) {
        cout << "      -- Empty --\n\n";
        return;
    }
}
for(p = gclist.begin(); p != gclist.end(); p++) {
    cout << "[" << (void *)p->memoryP << "]"    << "    " << p->refcount << "    ";
    if(p->memoryP){
        cout << "    " << *p->memoryP;
    }
    else{
        cout << "    ---";
        cout << endl;
    }
    cout << endl;
}

template <class T, int size>//Encuentra un puntero en gclist
typename list<GCInfo<T> >::iterator
    GCPointer<T, size>::findPtrInfo(T *ptr) {
    list<GCInfo<T> >::iterator p;
    for(p = gclist.begin(); p != gclist.end(); p++)
        if(p->memoryP == ptr)
            return p;
    return p;
    }
template <class T, int size>//Limpia la lista cuando el programa sale
void GCPointer<T, size>::shutdown() {
    if(gclistSize() == 0) return;
    list<GCInfo<T> >::iterator p;
    for(p = gclist.begin(); p != gclist.end(); p++) {
        p->refcount = 0;
    }
    #ifdef DISPLAY
        cout << "Antes de recolectar para shutdown() para "
             << typeid(T).name() << "\n";
    #endif
    collect();
    #ifdef DISPLAY
        cout << "Despues de recolectar para shutdown() para "
             << typeid(T).name() << "\n";
    #endif
}




