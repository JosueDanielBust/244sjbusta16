/*
 * fichero: entrada02.cpp
 * compilar: $ g++ -o entrada02 entrada02.cpp
 *
 * ejecutar: $ ./entrada02
 *
 * proposito: Mostrar como se leen datos de la entrada estandar
 *            sin formato.
 */
#include <iostream>

using namespace std;


int
main() {
  const streamsize TOTALDATOS = 50;
  char* elementos = new char[TOTALDATOS];

  cout << "Entre un conjunto de caracteres: ";
  cin.read(elementos, TOTALDATOS);

  if (cin.fail()) {
    cerr << "Problemas en el flujo de entrada" << endl;
    cin.clear();
  }
  else {
    cout << elementos << endl;
  }

  delete []elementos;

  return 0;
}
// filename: entrada02.cpp
