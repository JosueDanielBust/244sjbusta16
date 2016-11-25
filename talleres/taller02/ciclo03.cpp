/*
 * fichero: ciclo03.cpp
 * compilar: $ g++ -o ciclo03 ciclo03.cpp
 *           $ make ciclo03
 * ejecutar: $ ./ciclo03
 */
#include <iostream>

using namespace std;

const int N = 10;

int main() {
  int i;

  i = 0;
  for (i = 0; i < N; i++) {
    cout << "veces: " << i << endl;
  }

  cout << i << endl;
  return 0;
}
