class Foo {
  var s: sync int;

  proc init(val) {
    s = val;
  }
}

var foo1 = new unmanaged Foo(3);
writeln(foo1.s.readFF());
delete foo1;
