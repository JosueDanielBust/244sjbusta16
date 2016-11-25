#include "intercalate.h"
#include <iostream>

using namespace std;

int*
intercalate(const int arr1[],
	    const int arr2[],
	    const int nbr,
	    const int fact) {

  int* arr3 = new int[nbr];
  int count;
  if (nbr == fact) {
      for (int i = 0; i < nbr; i++) {
	arr3[i] = arr2[i];
      }
    return arr3;
  }
  
  while (count < nbr) {
    for (int i = 0; i < fact; i++) {
      arr3[i+count] = arr2[i+count+fact];
    }
    
    for (int i = 0; i < fact; i++) {
      arr3[i+count+fact] = arr1[i+count];
    }
    count += (fact*2);
  }
  return arr3;
}
