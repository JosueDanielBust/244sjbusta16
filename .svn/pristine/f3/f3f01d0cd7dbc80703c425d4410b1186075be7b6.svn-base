#include <iostream>
#include <fstream>
using namespace std;

int sumar(int a, int b) {
  int suma = 0;
  a--;
  while (a++ < b) {
    suma = suma + a;
  }
  return suma;
}


int main() {
  int result;
  ifstream file("input.txt");

  for(int a, b; file >> a >> b;) {
    result = sumar(a, b);
    cout << result << endl;
  }
  
  return 0;
}
