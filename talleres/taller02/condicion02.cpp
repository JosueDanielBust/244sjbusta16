/*
 * fichero: condicion02.cpp
 * compilar: $ g++ -o condicion02 condicion02.cpp
 *           $ make condicion02
 * ejecutar: $ ./condicion02
 */
#include <iostream>

using namespace std;

int
main() {
  int a;
  int b;

  cin >> a >> b;

  if (a != 0 || b != 0) {
    cout << "Ambos valores son diferentes de cero" << endl;
  } else {
    cout << "Uno de los valores es cero" << endl;
  }

  return 0;
}
