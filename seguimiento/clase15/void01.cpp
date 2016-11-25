/*
 * fichero: void01.cpp
 * compilar: $ g++ -o void01 void01.cpp
 * ejecutar: $ ./void01
 * proposito: Ejemplo de tipo void
 */
#include <iostream>

void funcion(void);

int
main(void) {
  funcion();
  return 0;
}

void funcion() {
  
  std::cout << "Esto es un efecto colateral" << std::endl;
}
