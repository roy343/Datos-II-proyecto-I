#include <iostream>
#include <stdlib.h>

using namespace std;

class VSPointer
{
private:
    int *T;//Puntero
    int id;//Id del VSPointer
public:
    VSPointer(int,int);
    void New();//Reserva memoria
    void Free();//Libera memoria
};

VSPointer::VSPointer(int T1, int _id)// Metodo constructor
{
    *T = T1;
    id = _id;
}
void VSPointer::New(){
    T = new int; //Llama al metodo new para reservar memoria
}
void VSPointer::Free(){
    delete[] T;//Llama al metodo delete para liberar la memoria
}

