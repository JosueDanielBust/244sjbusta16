/*
 * fichero: entrada08.cpp
 * compilar: $ g++ -o entrada08 entrada08.cpp
 * ejecutar: $ ./entrada08
 * proposito: Mostrar como se leen datos de la entrada estandar.
 *            utilizando flujos de tipo string
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAXBUF = 256;

using namespace std;

int
main() {

  char buffer[MAXBUF];
  ifstream filein("ficheroentrada08.txt");
  ofstream fileout("ficherosalida08.txt", ios_base::out | ios_base::app);

  while (filein.getline(buffer,MAXBUF)) {

    string buffer2(buffer);

    istringstream ins(buffer2);

    int number1;
    char c;
    int number2;
    char cadena2[MAXBUF];

    ins >> number1 >> c >> number2 >> cadena2;

    fileout << "Number1: " << number1
	 << " Caracter: " << c
	 << " Number2: " << number2
	 << " Cadena2: " << cadena2
	 << endl;

  }

  return 0;

}
// filename: entrada08.cpp
