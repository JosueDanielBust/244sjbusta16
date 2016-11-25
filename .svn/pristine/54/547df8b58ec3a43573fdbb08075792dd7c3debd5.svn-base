#include "parityTest.h"

Parity parityTest(const char word[], int &nEven, int &nOdd) {
  int a, b;
  for (int i = 0; word[i] != 0; i++) {
    if (isEvenParity(word[i]) == 1) {
      a++;
    } else {
      b++;
    }
  }

  nEven = a;
  nOdd = b;
  
  if (a > b) { return even; }
  else if (a < b) { return odd; }
  else { return none; }
}
