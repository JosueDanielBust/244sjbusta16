#include <iostream>
using namespace std;

int main() {
  int a, b, c;

  cin >> a >> b >> c;

  if (a == 0 || b == 0 || c == 0) {
    cout << "Parece que esto no es un triangulo" << endl;
  } else if (a == b && a == c) {
    cout << "equilatero" << endl;
  } else if (a == b || b == c || a == c) {
    cout << "isoceles" << endl;
  } else {
    cout << "escaleno" << endl;
  }

  return 0;
}
