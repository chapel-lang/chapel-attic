config param INTERVALS = 255;
def calPI :real {
  var h1 = 1.0;
  for param i in 0..INTERVALS {
    h1 += (let xi = (1.0/INTERVALS)*(i+0.5) in 4.0/(1.0+xi*xi));
  }
  return h1;
}
var ysum: real = calPI;
var area = ysum*(1.0/INTERVALS);
writeln(area);
