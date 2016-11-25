#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>


Parser::Parser(istream* in) { scan = new Scanner(in); }

Parser::~Parser() { try { delete scan; } catch (...) {} }
AST* Parser::parse() { return Prog(); }

AST* Parser::Prog() {
  AST* result = Expr();
  Token* t = scan->getToken();

  if (t->getType() != eof) {
    cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
    throw ParseError;
  }

  return result;
}

AST* Parser::Expr() { return RestExpr(Term()); }

AST* Parser::RestExpr(AST* e) {
  Token* t = scan->getToken();

  if (t->getType() == add)
    return RestExpr(new AddNode(e,Term()));

  if (t->getType() == sub)
    return RestExpr(new SubNode(e,Term()));

  scan->putBackToken();

  return e;
}

AST* Parser::Term() { return RestTerm(Storable()); }

AST* Parser::RestTerm(AST* e) {
  Token* t = scan->getToken();

  if (t->getType() == times)
    return RestTerm(new TimesNode(e,Storable()));

  if (t->getType() == divide)
    return RestTerm(new DivideNode(e,Storable()));

  if (t->getType() == mod)
    return RestTerm(new ModNode(e,Storable()));
   
  scan->putBackToken();
  return e;
}

AST* Parser::Storable() {
  return MemOperation(Factor());
}
AST* Parser::MemOperation(AST* e) {
  Token* t = scan->getToken();

  if (t->getType() == keyword) {
    if (t->getLex() == "S")
      return new StoreNode(e);
    
    if (t->getLex() == "P")
      return new PlusNode(e);

    if (t->getLex() == "M")
      return new MinusNode(e);
    cout << "Syntax error: found " << t->getLex()
	 << " at " << t->getLine() << ":" << t->getCol()
	 << " expected S, P or M"
	 << endl;
    throw ParseError;
  }
  
  scan->putBackToken();
  return e;
}
AST* Parser::Factor() {
  Token* t = scan->getToken();

  if (t->getType() == number) {
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val); 
  }

  if (t->getType() == keyword) {
    if (t->getLex() == "R")
      return new RecallNode();
    if (t->getLex() == "C")
      return new ClearNode();
    cout << "System error: found " << t->getLex()
	 << " at " << t->getLine() << ":" << t->getCol() 
	 << " expected R or C"
	 << endl;
    throw ParseError;
  }
  
  if (t->getType() == lparen) {
    AST* r = Expr();
    t = scan->getToken();
    if (t->getType() == rparen)
      return r;
    cout << "System error expected ) at "
	 << t->getLine() << ":" << t->getCol()
	 << endl;
    throw ParseError;
  }

  if (t->getType() == identifier) {
    istringstream in(t->getLex());
    string ident;
    in >> ident;
    return Assignable(ident);
  }

  cout << "System error expected Factor" << endl;
  throw ParseError;
}

AST* Parser::Assignable(string key) {
  Token* t = scan->getToken();
  if (t->getType() == assign)
    return Assign(key);
    
  scan->putBackToken();
  return new GetNode(key);
}

AST* Parser::Assign(string key) {
  AST* value = Expr();
  return new SetNode(value, key);
  scan->putBackToken();
}
