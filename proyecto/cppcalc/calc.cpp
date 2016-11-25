#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "calcex.h"
#include "calculator.h"

const int MAXBUF = 256;

using namespace std;

Calculator* calc;

void makeInteractiveCalc() {
  string line;
  cout << "> ";
  getline(cin, line);
  int result = calc->eval(line);
  string newVar = calc->printVar();
  cout << "=> " << result << newVar << endl;
  makeInteractiveCalc();
}

void readingFile(const char* file) {
  char buffer[MAXBUF];
  ifstream filein(file);

  while (filein.getline(buffer,MAXBUF)) {
    string buffer2(buffer);
    int result = calc->eval(buffer2);
    cout << "=> " << result << endl;
  }
}

int main(int argc, char* argv[], char** argenv) {
  try {
    calc = new Calculator();
    for (int i = 1; i < argc; i++) {
      string optionArg = argv[i];
      if (optionArg == "-e")
        calc->envConf();

      while (*argenv) {
        string a = *argenv;
        if (a.substr(0,7) == "CALCVAR")
          calc->eval(a.substr(7,a.size()));
        *argenv++;
      }
      calc->changeSetEnvVars();

      if (optionArg == "-v") {
        calc->eval(argv[i+1]);
        i++;
      } else {
        readingFile(argv[i]);
      }
    }
    calc->changeSetEnvVars();
    makeInteractiveCalc();
    delete calc;
  }
  catch(Exception ex) {
    cout << "=> Program Aborted due to exception!" << endl;
  }
}
