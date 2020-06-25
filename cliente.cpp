
#include "cliente.h"
#include <iostream>
#include "Windows.h"

using namespace std;

//! Metdodo run

//! El metodo run ejecuta la parte visual de la extension, 
//! creada en QT Creator
void Cliente::run()
{
    ShellExecute(NULL,"open","C:\\Users\\Dell\\Desktop\\Visualizer\\build-Visualizer-Desktop_Qt_5_15_0_MinGW_64_bit-Debug\\debug\\Visualizer.exe",NULL,NULL,SW_SHOWDEFAULT);
}