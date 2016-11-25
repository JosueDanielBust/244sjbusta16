/*
 * fichero: condicion03.cpp
 * compilar: $ g++ -o condicion03 condicion03.cpp
 *           $ make condicion03
 * ejecutar: $ ./condicion03
 */
#include <iostream>

using namespace std;

int
main() {
  int a;
  int b;
  int suma;
  int diff;

  cin >> a;
  cin >> b;

  if ((suma = a + b) || (diff = a - b)) {
    cout << "suma: " << suma << " resta: " << diff << endl;
  }
  else {
    cout << "suma: " << suma << " resta: " << diff << endl;
  }

  return 0;
}
