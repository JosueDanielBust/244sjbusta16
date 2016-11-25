/*
 * fichero: condicion01.cpp
 * compilar: $ g++ -o condicion01 condicion01.cpp
 *           $ make condicion01
 * ejecutar: $ ./condicion01
 */
#include <iostream>

using namespace std;

int
main() {
  int c;
  
  if (cin >> c && c == 0) {
    cout << "El usuario digito un valor de cero" << endl;
  }
  else {
    cout << "El usuario digito un valor diferente de cero" << endl;
  }

  return 0;
}
