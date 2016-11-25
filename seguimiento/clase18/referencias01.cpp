/*
 * fichero: referencias01.cpp
 * 
 * compilar: $ g++ -o referencias01 referencias01.cpp
 * ejecutar: $ ./referencias01
 *
 * proposito: Mostrar la inicializaci&oacute;n de referencias
 */
#include <iostream>

// variable global
int a = 10;
float b = 1.1f;

int
main(void) {

  int &ref_a = a;
  float &sref_b = b;

  // Incrementa
  ref_a++;
  sref_b++;

  std::cout << "a: " << a
	    << " ref_a: " << ref_a
	    << "Direccion de a: " << &a
	    << "Direccion de ref_a: " << &ref_a
	    << std::endl;

  std::cout << "b: " << b
	    << " sref_b " << sref_b
	    << "Direccion de b: " << &b
	    << "Direccion de sref_b: " << &sref_b
	    << std::endl;
  
  return 0;
}
