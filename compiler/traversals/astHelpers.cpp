#include "traversal.h"
#include "baseAST.h"
#include "stmt.h"
#include "expr.h"
#include "symtab.h"


class ClearFileInfo : public Traversal {
public:
  int lineno;
  char* filename;

  ClearFileInfo(int iLineno = -1, char* iFilename = "<internal>") :
    lineno(iLineno),
    filename(iFilename)
  { }

  void preProcessStmt(Stmt* stmt) {
    stmt->lineno = lineno;
    stmt->filename = filename;
  }

  void preProcessExpr(Expr* expr) {
    expr->lineno = lineno;
    expr->filename = filename;
    if (DefExpr* defExpr = dynamic_cast<DefExpr*>(expr)) {
      defExpr->sym->lineno = lineno;
      defExpr->sym->filename = filename;
    }
  }
};


void clear_file_info(BaseAST* baseAST) {
  TRAVERSE(baseAST, new ClearFileInfo(), true);
}


void reset_file_info(BaseAST* baseAST, int lineno, char* filename) {
  TRAVERSE(baseAST, new ClearFileInfo(lineno, filename), true);
}


class ComputeCallSites : public Traversal {
 public:
  void preProcessExpr(Expr* expr) {
    if (CallExpr* call = dynamic_cast<CallExpr*>(expr)) {
      if (call->findFnSymbol()) {
        if (call->findFnSymbol()->calledBy) { // yuck, got some functions being called that are no longer in the tree, STOPGAP, this has to do with unions
          call->findFnSymbol()->calledBy->add(call);
          call->parentFunction()->calls->add(call);
        }
      }
    }
  }
};


void compute_call_sites() {
  Vec<FnSymbol*> fs;
  collect_functions(&fs);
  forv_Vec(FnSymbol, f, fs) {
    f->calledBy = new Vec<CallExpr*>();
    f->calls = new Vec<CallExpr*>();
  }
  Pass* pass = new ComputeCallSites();
  pass->run(Symboltable::getModules(MODULES_ALL));
}
