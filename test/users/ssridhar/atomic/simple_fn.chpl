var x: uint(64);

def main() {
  var i, j: int;
  coforall i in 1..10 {
    //foo(i); // check if the non-transactional copy is called
    atomic {
      foo();
      j += 1;
     //  foo(i+2); // check if the cache works
    }
  }
}

def foo() {
  //  writeln(i);
  x = x + 1;
}