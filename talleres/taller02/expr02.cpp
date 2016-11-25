#include <iostream>
using namespace std;

int getMin(int a, int b, int c) {
  int mina = min(a,b);
  int minb = min(mina,c);
  return minb;
}
int getMax(int a, int b, int c) {
  int maxa = max(a,b);
  int maxb = max(maxa,c);
  return maxb;
}
int getMed(int a, int b, int c, int fa, int fc) {
  int fb;
  if (fa == a) {
    if (fc == b) { fb = c; } else if (fc == c) { fb = b; }
  }
  if (fa == b) {
    if (fc == a) { fb = c; } else if (fc == c) { fb = a; }
  }
  if (fa == c) {
    if (fc == a) { fb = b; } else if (fb == b) { fb = a; }
  }
  return fb;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int fa = getMin(a,b,c);
  int fc = getMax(a,b,c);
  int fb = getMed(a,b,c,fa,fc);
  
  cout << fa << " " << fb << " " << fc << endl;
  
  return 0;
}
