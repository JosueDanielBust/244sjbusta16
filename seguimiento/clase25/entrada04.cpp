/*
 * fichero: entrada04.cpp
 * compilar: $ g++ -o entrada04 entrada04.cpp
 * ejecutar: $ ./entrada04
 * proposito: Mostrar como se leen datos de la entrada estandar.
 */
#include <iostream>

using namespace std;

int
main() {
  int unEntero;
  double unDouble;
  long unLong;

  cout << "Entre un entero, un doble y un entero largo"
       << " separado de espacios: ";
  while (cin >> unEntero >> unDouble >> unLong) {
    cout << "\n\nEntero:\t" << unEntero << endl;
    cout << "Doble:\t" << unDouble << endl;
    cout << "Entero largo:\t" << unLong << endl;
  }
  
  return 0;
}
// filename: entrada04.cpp
