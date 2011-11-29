// This test case shows that there is a memory leak due to the second assignment
// to s.  s should be freed just before it is assigned to again.

use Memory;

config const n = 1;

proc foo () {
  var s1 = "Good bye",
      s2 = s1;
  if n > 0 then
    s2 = "Nos vemos";
  writeln(s2);
}

var m1 = memoryUsed();
foo(); 
var m2 = memoryUsed();

writeln("Amount of leaked memory after calling foo(): ", m2:int - m1:int);
