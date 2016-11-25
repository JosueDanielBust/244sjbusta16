#pragma once

#include <string>
#include <map>
#include <iomanip>
 
using namespace std;


class Calculator {
 public:
   Calculator();

   int eval(string expr);
   void store(int val);
   int recall();
   void set(string key, int value);
   int get(string key);
   bool isEnvVar(string key);
   void envConf();
   void changeSetEnvVars();
   string printVar();
   

 private:
   int memory;
   map<string, int> vars;
   map<string, int> varsEnv;
   bool useEnvVars;
   bool setEnvVars;
   bool createVar;
   string lastCreateKey;
};

extern Calculator* calc;
