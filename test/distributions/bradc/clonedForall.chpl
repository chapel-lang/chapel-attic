use MultiBlockDist;

var B = new Block(rank=1, bbox=[1..numLocales:int(64)]);
var D: domain(1, int(64)) distributed B = [1..numLocales:int(64)];
var x: int;

forall i in D do
  x %= 1;
