#include <iostream>
#include "funciones.h"
using namespace std;

int a, b, c;

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  // Operacion interna
  int d = multEnt(a,b);
  int e = sumaEnt(d,c);
  int f = multEnt(c,e);
  int g = restaEnt(a,b);
  int h = multEnt(f,g);
  // Operacion externa
  int i = sumaEnt(a,b);
  int j = sumaEnt(h,i);
  // Salida final
  cout << j << endl;
  return 0;
}
