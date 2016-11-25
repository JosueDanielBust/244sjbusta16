/*
 * fichero: entrada09.cpp
 * compilar: $ g++ -o entrada09 entrada09.cpp
 * ejecutar: $ ./entrada09
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
  ifstream filein("ficheroentrada09.txt");
  ofstream fileout("ficherosalida09.txt");

  while (filein.getline(buffer,MAXBUF)) {

    string buffer2(buffer);

    istringstream ins(buffer2);

    int number1;
    char c;
    int number2;
    char cadena1[MAXBUF], cadena2[MAXBUF];

    ins >> number1 >> c >> number2;

    ins.getline(cadena1, MAXBUF, ':');

    ins >> cadena2;

    fileout << "Number1: "  << number1
	    << " Number2: " << number2
	    << " Caracter: " << c
	    << " Cadena1: " << cadena1
	    << " Cadena2: " << cadena2
	    << endl;

  }

  return 0;

}
// filename: entrada09.cpp
