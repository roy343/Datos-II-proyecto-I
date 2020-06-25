#include <iostream>
#include "VSPointer.h"

using namespace std;
VSPointer Vsptr;

class Singleton {
   static Singleton *instance;
   int data;
 
   // Cosntructor privado de forma que no se creen nuevos objetos
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      if (!instance)
      instance = new Singleton;
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};

//Initializa el puntero a cero de modo que pueda ser inicializado en la primera llamada a getInstance
Singleton *Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}