/*
 * fichero: apuntadores02.cpp
 *
 * compilar: $ g++ -o apuntadores02 apuntadores02.cpp
 * ejecutar: $ ./apuntadores
 *
 * proposito: Apuntadores de varios tipos
 */
#include <iostream>

using namespace std;

void print(int *);
void print(char *);
void print(double *);
void print(void *);

int
main(void) {
  int i = 10;
  char c = 'a';
  double d = 78.3e-100;

  int* pI = &i;
  char* pC = &c;
  double *pD = &d;

  print(pI);
  print(pC);
  print(pD);
  
  cout << "Tamaño apuntador entero: " << sizeof(pI) << endl;
  cout << "Tamaño pauntador char: " << sizeof(pC) << endl;
  cout << "Tamaño apuntador doble: " << sizeof(pD) << endl;
  cout << "Tamaño apuntador void: " << sizeof(void*) << endl;
  
  print((void*) pI);
  print((void*) pC);
  print((void*) pD);
  
  return 0;
}

void print(int *p) {

  cout << "Direccion: " << p
       << " contenido: " << *p
       << endl;
  return;
}

void print(char *p) {

  cout << "Direccion: " << p
       << " contenido: " << *p
       << endl;
  return;
}

void print(double *p) {

  cout << "Direccion: " << p
       << " contenido: " << *p
       << endl;
  return;
}

void print(void *p) {

  cout << "Direccion: " << p
       << endl;
  return;
}
