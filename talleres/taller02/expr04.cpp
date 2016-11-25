#include <iostream>
using namespace std;

double getMin(double a, double b, double c) {
  double mina = min(a,b);
  double minb = min(mina,c);
  return minb;
}
double getMax(double a, double b, double c) {
  double maxa = max(a,b);
  double maxb = max(maxa,c);
  return maxb;
}
double getMed(double a, double b, double c, double fa, double fc) {
  double fb;
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
  double a, b, c;
  cin >> a >> b >> c;

  double fa = getMin(a,b,c);
  double fc = getMax(a,b,c);
  double fb = getMed(a,b,c,fa,fc);
  
  cout << fa << " " << fb << " " << fc << endl;
  
  return 0;
}
