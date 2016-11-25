/*
 * fichero: ciclo04.cpp
 * compilar: $ g++ -o ciclo04 ciclo04.cpp
 *           $ make ciclo04
 * ejecutar: $ ./ciclo04
 */
#include <iostream>

using namespace std;

const int N = 10;

int main() {
  int i;

  i = 0;
  for (i = 0; i < N; ++i) {
    cout << "veces: " << i << endl;
  }
  cout << i << endl;
  return 0;
}
