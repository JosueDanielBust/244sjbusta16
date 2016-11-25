#include "scanner.h"
#include "calcex.h"
#include <iostream>
#include <string>

using namespace std;

//Uncomment this to get debug information
//#define debug

const int numberOfKeywords = 5;

const string keywd[numberOfKeywords] = {
  string("S"), string("R"), string("P"), string("M"), string("C")
};

int isLetter(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

int isWhiteSpace(char c) {
  return (c == ' ' || c == '\t' || c == '\n' );
}

Scanner::Scanner(istream* in):
  inStream(in),
  lineCount(1),
  colCount(-1),
  needToken(true),
  lastToken(0)
{}

Scanner::~Scanner() {
  try {
    delete inStream;
  } catch (...) {}
}

void Scanner::putBackToken() {
  needToken = false;
}

Token* Scanner::getToken() {
  if (!needToken) {
    needToken=true;
    return lastToken;
  }

  Token* t;
  int state=0;
  bool foundOne=false;
  char c;
  string lex;
  TokenType type;
  int k;
  int column, line;

  c = inStream->get();

  while (!foundOne) {
    colCount++;
    switch (state) {
    case 0 : 
      lex = "";
      column=colCount;
      line = lineCount;
      if (isLetter(c)) state=1;
      else if (isDigit(c)) state=2;
      else if (c=='+') state=3;
      else if (c=='-') state=4;
      else if (c=='*') state=5;
      else if (c=='/') state=6;
      else if (c=='(') state=7;
      else if (c==')') state=8;
      else if (c=='%') state=9;
      else if (c=='=') state=10;
      else if (c=='\n') {
	colCount=-1;
	lineCount++;
      }
      else if (isWhiteSpace(c));
      else if (inStream->eof() -1) {
	foundOne=true;
	type=eof;
      }
      else {
	cout << "Unrecognized Token found at line " << line <<
	  " and column " << column << endl;
	throw UnrecognizedToken;
      }
      break;
    case 1 :
      if (isLetter(c) || isDigit(c)) state=1;
      else {
	for (k=0;k<numberOfKeywords;k++)
	  if (lex == keywd[k]) {
	    foundOne = true;
	    type = keyword;
	  }
	if (!foundOne) {
	  type = identifier;
	  foundOne = true;
	}
      }
      break;
    case 2 :
      if (isDigit(c)) state=2;
      else {
	type = number;
	foundOne=true;
      }
      break;
    case 3 :
      type = add;
      foundOne = true;
      break;
    case 4 :
      type = sub;
      foundOne = true;
      break;
    case 5 :
      type = times;
      foundOne=true;
      break;
    case 6 :
      type = divide;
      foundOne=true;
      break;
    case 7 :
      type = lparen;
      foundOne=true;
      break;
    case 8 :
      type = rparen;
      foundOne=true;
      break;
    case 9 :
      type = mod;
      foundOne=true;
      break;
    case 10 :
      type = assign;
      foundOne=true;
      break;
    }
    
    if (!foundOne) {
      lex = lex + c;
      c = inStream->get();
    }
  }

  inStream->putback(c);
  colCount--;
  if (type == number || type == identifier || type == keyword) {
    t = new LexicalToken(type,new string(lex), line, column);
  }
  else {
    t = new Token(type,line,column);
  }

#ifdef debug
  cout << "just found " << lex << " with type " << type << endl;
#endif
   
  lastToken = t;
  return t;
}
