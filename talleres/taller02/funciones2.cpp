#include <iostream>
using namespace std;

int a, b, c;

int mcd(int a, int b) {
  if (b == 0) {
    cout << "MCD: " << a << endl;
    return a;
  } else {
    int c = a % b;
    mcd(b,c);
  }
}

int simpFrac(int a, int b) {
  int c = mcd(a,b);
  a = a/c;
  b = b/c;
  cout << "Simp: " << a << "/" << b << endl;
  return 0;
}

int main(void) {
  simpFrac(166,249);
  return 0;
}
