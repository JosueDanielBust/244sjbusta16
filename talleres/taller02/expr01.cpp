#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cout << "Lea tres valores enteros separados por espacios: " << endl;
  cin >> a >> b >> c;

  int res1 = (((a * b) - 10) + (c - a) * 10);
  int res2 = (((a << (2 * a) >> 1)) + (b + c << 2));

  int res11 = (a * b) - 10 + (c - a) * 10;
  int res21 = (a << 2 * a >> 1) + (b + c << 2);
  
  cout << "Res1: " << res1 << " - " << res11 << endl;
  cout << "Res2: " << res2 << " - " << res21 << endl;
  
  return 0;
}
