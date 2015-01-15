#include "concepts.h"

GenRet Constraint::codegen() {
  return GenRet();
}

Constraint* Constraint::copyInner(SymbolMap* map) {
  return new Constraint(this->interfaceName, this->typeVar);
}

bool Constraint::inTree() {
  return this->constrainedFn != NULL;
}

Type* Constraint::typeInfo() {
  return NULL;
}

void Constraint::verify() {
  return;
}
