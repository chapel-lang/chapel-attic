config var n : int = 8;

var D : domain(1) = [1..n];

var A : [D] int;

[i in D] A(i) = i;

writeln(A);
