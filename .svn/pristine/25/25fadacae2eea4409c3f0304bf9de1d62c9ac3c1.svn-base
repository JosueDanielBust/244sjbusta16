#include <iostream>
#include <fstream>

const int MAXBUF = 256;

using namespace std;
int main(int argc, const char *argv[]) {
  char buffer[MAXBUF];
  ifstream filein(*argv);
  string name;
  float notaA, notaB, averageStudent, averageSum, averageTotal;
  int totalStudents = 0;

  while (filein.getline(buffer, MAXBUF)) {
    string buffer2(buffer);
    istringstream ins(buffer2);

    ins >> name >> notaA >> notaB;
    averageStudent = (notaA + notaB)/2;
    totalStudents++;

    cout << name << ": " << averageStudent << endl;

    averageSum += averageStudent;
  }
  
  averageTotal = averageSum/totalStudents;
  cout << "Total students: " << totalStudents << endl;
  cout << "Average grade: " << averageTotal << endl;
  return 0;
}
