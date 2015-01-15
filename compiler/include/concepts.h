#ifndef _CONCEPTS_H_
#define _CONCEPTS_H_

#include "baseAST.h"
#include "expr.h"
#include "vec.h"

//class Model : BaseAST {

//};

class Constraint : BaseAST {
  public:
  
  const char* interfaceName;
  Expr* typeVar;
  
  FnSymbol* constrainedFn;
  
  Constraint() : BaseAST(E_Constraint), interfaceName(NULL), typeVar(NULL) {}
  Constraint(const char* interfaceName, Expr* typeVar) :
    BaseAST(E_Constraint), interfaceName(interfaceName), typeVar(typeVar) {}
  
  DECLARE_COPY(Constraint);
  
  GenRet codegen();
  bool inTree();
  Type* typeInfo();
  void verify();
}; 

struct WhereUnion {
  enum {
    WU_None,
    WU_Expr,
    WU_Cons
  } tag;
  
  union WhereUnionInt {
    Expr* expr;
    Vec<Constraint*>* cons;
    
    WhereUnionInt()                       : expr(NULL) {}
    WhereUnionInt(Expr* expr)             : expr(expr) {}
    WhereUnionInt(Vec<Constraint*>* cons) : cons(cons) {}
  } value;
  
  WhereUnion()                       : tag(WU_None) {}
  WhereUnion(Expr* expr)             : tag(WU_Expr), value(expr) {}
  WhereUnion(Vec<Constraint*>* cons) : tag(WU_Cons), value(cons) {}
  
  bool isValid() { return this->tag != WU_None; }
  bool isExpr()  { return this->tag == WU_Expr; }
  bool isCons()  { return this->tag == WU_Cons; }
  
  Expr* getExpr() {
    return this->tag == WU_Expr ? this->value.expr : NULL;
  }
  
  Vec<Constraint*>* getCons() {
    return this->tag == WU_Cons ? this->value.cons : NULL;
  }
};

#endif
