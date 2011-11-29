config const l = numLocales-1;
config const rl = 0;

on Locales(l) {
  extern class C { var x: int; }
  extern proc foo(c: C, x: int);
  var myC = new C(5);

  writeln(myC);

  on Locales(rl) {
    foo(myC, 3);
  }

  writeln(myC);
}

