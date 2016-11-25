#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

Calculator::Calculator(): memory(0), useEnvVars(false),
			  setEnvVars(true), createVar(false),
			  lastCreateKey("") {}

int Calculator::eval(string expr) {
   Parser* parser = new Parser(new istringstream(expr));
   AST* tree = parser->parse();
   int result = tree->evaluate();   
   delete tree;
   delete parser;
   return result;
}

void Calculator::store(int val) { memory = val; }
int Calculator::recall() { return memory; }
void Calculator::set(string key, int value) {
  if (setEnvVars == false)
    vars[key] = value;
  else
    varsEnv[key] = value;
  createVar = true;
  lastCreateKey = key;
}
int Calculator::get(string key) {
  if (useEnvVars == true && isEnvVar(key) == true) {
    return varsEnv[key];
  } else {
    return vars[key];
  }
}
bool Calculator::isEnvVar(string key) {
  if (varsEnv[key])
    return true;
  else
    return false;
}
void Calculator::envConf() { useEnvVars = true; }
void Calculator::changeSetEnvVars() { setEnvVars = false; }
string Calculator::printVar() {
  string result = "";
  string lastKey = lastCreateKey;
  int lastVal = get(lastCreateKey);
  ostringstream convert;
  convert << lastVal;
  string strLastVal = convert.str();
  if (createVar == true) {
    result.append(" [");
    result.append(lastKey);
    result.append(" <- ");
    result.append(strLastVal);
    result.append("]");
    createVar = false;
  }
  return result;
}
