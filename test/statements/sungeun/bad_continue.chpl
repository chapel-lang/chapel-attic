config var I=10, J=10, K=10;
config var bi=5, bj=6, bk=7;
config var limit=10;
var i=I, j=J, k=K, l=limit;

do {
  label l1
  while (i>0) {
    i -=1;
    writeln("i=", i);
    if (i == bi) then continue l1;

    label l2
    while (j>0) {
      j -=1;
      writeln("j=", j);
      if (j == bj) then continue l2;
      if (j == bi) then continue l1;

      label l3
      while (k>0) {
	k -=1;
	writeln("k=", k);
	if (k == bk) then continue l3;
	if (k == bj) then continue l2;
	if (k == bi) then continue l1;
      }
      writeln("after l3 ", i, j, k);
      continue l3;
    }
    writeln("after l2 ", i, j, k);
    continue l2;
  }
  writeln("after l1 ", i, j, k);

  l +=1;
  continue l1;
 } while (l < limit);


