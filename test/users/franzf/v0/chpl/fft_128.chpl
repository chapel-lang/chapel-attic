/***************************************************************
This code was generated by  Spiral 5.0 beta, www.spiral.net --
Copyright (c) 2005, Carnegie Mellon University
All rights reserved.
The code is distributed under a BSD style license
(see http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
  notice, reference to Spiral, this list of conditions and the
  following disclaimer.
  * Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the following
  disclaimer in the documentation and/or other materials provided
  with the distribution.
  * Neither the name of Carnegie Mellon University nor the name of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*AS IS* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/

use omega;
var  buf2: [0..127] complex;
var  dat3: [0..55] complex;
var  dat4: [0..55] complex;

proc init_fft128() {
  for i3883 in 0..6 {
    for i3898 in 0..3 {
      dat3(((i3883*8) + (i3898*2))) = omega(128, ((i3883 + 1)*i3898));
      dat3(((i3883*8) + (i3898*2) + 1)) = omega(128, ((i3883 + 1)*(i3898 + 4)));
    }
  }
  for i3884 in 0..6 {
    for i3908 in 0..3 {
      dat4(((i3884*8) + (i3908*2))) = omega(128, ((9 + i3884)*i3908));
      dat4(((i3884*8) + (i3908*2) + 1)) = omega(128, ((9 + i3884)*(i3908 + 4)));
    }
  }

}

proc fft128(Y: [] complex, X: [] complex) {
  var a6079, s2448, s2449, s2450, s2451, t6445, t6446, t6447, t6448, t6449, t6450, t6451, t6452, t6453, t6454, t6455:complex;
  t6445 = (X(0) + X(64));
  t6446 = (X(0) - X(64));
  t6447 = (X(32) + X(96));
  t6448 = (t6445 + t6447);
  t6449 = (t6445 - t6447);
  a6079 = (1.0i*(X(32) - X(96)));
  t6450 = (t6446 + a6079);
  t6451 = (t6446 - a6079);
  t6452 = (X(16) + X(80));
  s2448 = ((0.70710678118654757 + 1.0i * 0.70710678118654757)*(X(16) - X(80)));
  t6453 = (X(48) + X(112));
  s2449 = ((-0.70710678118654757 + 1.0i * 0.70710678118654757)*(X(48) - X(112)));
  t6454 = (t6452 + t6453);
  s2450 = (1.0i*(t6452 - t6453));
  t6455 = (s2448 + s2449);
  s2451 = (1.0i*(s2448 - s2449));
  buf2(0) = (t6448 + t6454);
  buf2(64) = (t6448 - t6454);
  buf2(16) = (t6450 + t6455);
  buf2(80) = (t6450 - t6455);
  buf2(32) = (t6449 + s2450);
  buf2(96) = (t6449 - s2450);
  buf2(48) = (t6451 + s2451);
  buf2(112) = (t6451 - s2451);
  for i3883 in 0..6 {
    var a6151, s2492, s2493, s2494, s2495, s2496, s2497, s2498, s2499, s2500, s2501, s2502, s2503, t6504, t6505, t6506, t6507, t6508, t6509, t6510, t6511, t6512, t6513, t6514:complex;
    var a6147, a6148, a6149, a6150, a6152, a6153, a6154, a6155, a6156:int;
    a6147 = (1 + i3883);
    s2492 = X(a6147);
    a6148 = (65 + i3883);
    s2493 = X(a6148);
    t6504 = (s2492 + s2493);
    t6505 = (s2492 - s2493);
    a6149 = (33 + i3883);
    s2494 = X(a6149);
    a6150 = (97 + i3883);
    s2495 = X(a6150);
    t6506 = (s2494 + s2495);
    t6507 = (t6504 + t6506);
    t6508 = (t6504 - t6506);
    a6151 = (1.0i*(s2494 - s2495));
    t6509 = (t6505 + a6151);
    t6510 = (t6505 - a6151);
    a6152 = (17 + i3883);
    s2496 = X(a6152);
    a6153 = (81 + i3883);
    s2497 = X(a6153);
    t6511 = (s2496 + s2497);
    s2498 = ((0.70710678118654757 + 1.0i * 0.70710678118654757)*(s2496 - s2497));
    a6154 = (49 + i3883);
    s2499 = X(a6154);
    a6155 = (113 + i3883);
    s2500 = X(a6155);
    t6512 = (s2499 + s2500);
    s2501 = ((-0.70710678118654757 + 1.0i * 0.70710678118654757)*(s2499 - s2500));
    t6513 = (t6511 + t6512);
    s2502 = (1.0i*(t6511 - t6512));
    t6514 = (s2498 + s2501);
    s2503 = (1.0i*(s2498 - s2501));
    a6156 = (8*i3883);
    buf2(a6147) = (dat3(a6156)*(t6507 + t6513));
    buf2(a6148) = (dat3((1 + a6156))*(t6507 - t6513));
    buf2(a6152) = (dat3((2 + a6156))*(t6509 + t6514));
    buf2(a6153) = (dat3((3 + a6156))*(t6509 - t6514));
    buf2(a6149) = (dat3((4 + a6156))*(t6508 + s2502));
    buf2(a6150) = (dat3((5 + a6156))*(t6508 - s2502));
    buf2(a6154) = (dat3((6 + a6156))*(t6510 + s2503));
    buf2(a6155) = (dat3((7 + a6156))*(t6510 - s2503));
  }
  var a6197, a6198, s2516, s2517, s2518, s2519, s2520, s2521, t6563, t6564, t6565, t6566, t6567, t6568, t6569, t6570:complex;
  t6563 = (X(8) + X(72));
  t6564 = (X(8) - X(72));
  t6565 = (X(40) + X(104));
  t6566 = (t6563 + t6565);
  s2516 = ((0.70710678118654757 + 1.0i * 0.70710678118654757)*(t6563 - t6565));
  a6197 = (1.0i*(X(40) - X(104)));
  s2517 = ((0.92387953251128674 + 1.0i * 0.38268343236508978)*(t6564 + a6197));
  s2518 = ((0.38268343236508978 + 1.0i * 0.92387953251128674)*(t6564 - a6197));
  t6567 = (X(24) + X(88));
  t6568 = (X(24) - X(88));
  t6569 = (X(56) + X(120));
  t6570 = (t6567 + t6569);
  s2519 = ((-0.70710678118654757 + 1.0i * 0.70710678118654757)*(t6567 - t6569));
  a6198 = (1.0i*(X(56) - X(120)));
  s2520 = ((0.38268343236508978 + 1.0i * 0.92387953251128674)*(t6568 + a6198));
  s2521 = ((-0.92387953251128674 - 1.0i * 0.38268343236508978)*(t6568 - a6198));
  buf2(8) = (t6566 + t6570);
  buf2(72) = ((1.0i*t6566) + ((- 1.0i)*t6570));
  buf2(24) = (s2517 + s2520);
  buf2(88) = ((1.0i*s2517) + ((- 1.0i)*s2520));
  buf2(40) = (s2516 + s2519);
  buf2(104) = ((1.0i*s2516) + ((- 1.0i)*s2519));
  buf2(56) = (s2518 + s2521);
  buf2(120) = ((1.0i*s2518) + ((- 1.0i)*s2521));
  for i3884 in 0..6 {
    var a6270, s2562, s2563, s2564, s2565, s2566, s2567, s2568, s2569, s2570, s2571, s2572, s2573, t6619, t6620, t6621, t6622, t6623, t6624, t6625, t6626, t6627, t6628, t6629:complex;
    var a6266, a6267, a6268, a6269, a6271, a6272, a6273, a6274, a6275:int;
    a6266 = (9 + i3884);
    s2562 = X(a6266);
    a6267 = (73 + i3884);
    s2563 = X(a6267);
    t6619 = (s2562 + s2563);
    t6620 = (s2562 - s2563);
    a6268 = (41 + i3884);
    s2564 = X(a6268);
    a6269 = (105 + i3884);
    s2565 = X(a6269);
    t6621 = (s2564 + s2565);
    t6622 = (t6619 + t6621);
    t6623 = (t6619 - t6621);
    a6270 = (1.0i*(s2564 - s2565));
    t6624 = (t6620 + a6270);
    t6625 = (t6620 - a6270);
    a6271 = (25 + i3884);
    s2566 = X(a6271);
    a6272 = (89 + i3884);
    s2567 = X(a6272);
    t6626 = (s2566 + s2567);
    s2568 = ((0.70710678118654757 + 1.0i * 0.70710678118654757)*(s2566 - s2567));
    a6273 = (57 + i3884);
    s2569 = X(a6273);
    a6274 = (121 + i3884);
    s2570 = X(a6274);
    t6627 = (s2569 + s2570);
    s2571 = ((-0.70710678118654757 + 1.0i * 0.70710678118654757)*(s2569 - s2570));
    t6628 = (t6626 + t6627);
    s2572 = (1.0i*(t6626 - t6627));
    t6629 = (s2568 + s2571);
    s2573 = (1.0i*(s2568 - s2571));
    a6275 = (8*i3884);
    buf2(a6266) = (dat4(a6275)*(t6622 + t6628));
    buf2(a6267) = (dat4((1 + a6275))*(t6622 - t6628));
    buf2(a6271) = (dat4((2 + a6275))*(t6624 + t6629));
    buf2(a6272) = (dat4((3 + a6275))*(t6624 - t6629));
    buf2(a6268) = (dat4((4 + a6275))*(t6623 + s2572));
    buf2(a6269) = (dat4((5 + a6275))*(t6623 - s2572));
    buf2(a6273) = (dat4((6 + a6275))*(t6625 + s2573));
    buf2(a6274) = (dat4((7 + a6275))*(t6625 - s2573));
  }
  for i3885 in 0..7 {
    var a6386, a6387, a6388, a6389, a6390, a6391, a6392, a6393, s2624, s2625, s2626, s2627, s2628, s2629, s2630, s2631, s2632, s2633, s2634, s2635, s2636, s2637, s2638, s2639, s2640, s2641, s2642, s2643, s2644, s2645, s2646, s2647, s2648, t6758, t6759, t6760, t6761, t6762, t6763, t6764, t6765, t6766, t6767, t6768, t6769, t6770, t6771, t6772, t6773, t6774, t6775, t6776, t6777, t6778, t6779, t6780, t6781, t6782, t6783, t6784, t6785, t6786, t6787, t6788:complex;
    var a6385:int;
    a6385 = (16*i3885);
    s2624 = buf2(a6385);
    s2625 = buf2((8 + a6385));
    t6758 = (s2624 + s2625);
    t6759 = (s2624 - s2625);
    s2626 = buf2((4 + a6385));
    s2627 = buf2((12 + a6385));
    t6760 = (s2626 + s2627);
    t6761 = (t6758 + t6760);
    t6762 = (t6758 - t6760);
    a6386 = (1.0i*(s2626 - s2627));
    t6763 = (t6759 + a6386);
    t6764 = (t6759 - a6386);
    s2628 = buf2((1 + a6385));
    s2629 = buf2((9 + a6385));
    t6765 = (s2628 + s2629);
    t6766 = (s2628 - s2629);
    s2630 = buf2((5 + a6385));
    s2631 = buf2((13 + a6385));
    t6767 = (s2630 + s2631);
    t6768 = (t6765 + t6767);
    s2632 = ((0.70710678118654757 + 1.0i * 0.70710678118654757)*(t6765 - t6767));
    a6387 = (1.0i*(s2630 - s2631));
    s2633 = ((0.92387953251128674 + 1.0i * 0.38268343236508978)*(t6766 + a6387));
    s2634 = ((0.38268343236508978 + 1.0i * 0.92387953251128674)*(t6766 - a6387));
    s2635 = buf2((2 + a6385));
    s2636 = buf2((10 + a6385));
    t6769 = (s2635 + s2636);
    t6770 = (s2635 - s2636);
    s2637 = buf2((6 + a6385));
    s2638 = buf2((14 + a6385));
    t6771 = (s2637 + s2638);
    t6772 = (t6769 + t6771);
    s2639 = (1.0i*(t6769 - t6771));
    a6388 = (1.0i*(s2637 - s2638));
    s2640 = ((0.70710678118654757 + 1.0i * 0.70710678118654757)*(t6770 + a6388));
    s2641 = ((-0.70710678118654757 + 1.0i * 0.70710678118654757)*(t6770 - a6388));
    s2642 = buf2((3 + a6385));
    s2643 = buf2((11 + a6385));
    t6773 = (s2642 + s2643);
    t6774 = (s2642 - s2643);
    s2644 = buf2((7 + a6385));
    s2645 = buf2((15 + a6385));
    t6775 = (s2644 + s2645);
    t6776 = (t6773 + t6775);
    s2646 = ((-0.70710678118654757 + 1.0i * 0.70710678118654757)*(t6773 - t6775));
    a6389 = (1.0i*(s2644 - s2645));
    s2647 = ((0.38268343236508978 + 1.0i * 0.92387953251128674)*(t6774 + a6389));
    s2648 = ((-0.92387953251128674 - 1.0i * 0.38268343236508978)*(t6774 - a6389));
    t6777 = (t6761 + t6772);
    t6778 = (t6761 - t6772);
    t6779 = (t6768 + t6776);
    Y(i3885) = (t6777 + t6779);
    Y((64 + i3885)) = (t6777 - t6779);
    a6390 = (1.0i*(t6768 - t6776));
    Y((32 + i3885)) = (t6778 + a6390);
    Y((96 + i3885)) = (t6778 - a6390);
    t6780 = (t6763 + s2640);
    t6781 = (t6763 - s2640);
    t6782 = (s2633 + s2647);
    Y((8 + i3885)) = (t6780 + t6782);
    Y((72 + i3885)) = (t6780 - t6782);
    a6391 = (1.0i*(s2633 - s2647));
    Y((40 + i3885)) = (t6781 + a6391);
    Y((104 + i3885)) = (t6781 - a6391);
    t6783 = (t6762 + s2639);
    t6784 = (t6762 - s2639);
    t6785 = (s2632 + s2646);
    Y((16 + i3885)) = (t6783 + t6785);
    Y((80 + i3885)) = (t6783 - t6785);
    a6392 = (1.0i*(s2632 - s2646));
    Y((48 + i3885)) = (t6784 + a6392);
    Y((112 + i3885)) = (t6784 - a6392);
    t6786 = (t6764 + s2641);
    t6787 = (t6764 - s2641);
    t6788 = (s2634 + s2648);
    Y((24 + i3885)) = (t6786 + t6788);
    Y((88 + i3885)) = (t6786 - t6788);
    a6393 = (1.0i*(s2634 - s2648));
    Y((56 + i3885)) = (t6787 + a6393);
    Y((120 + i3885)) = (t6787 - a6393);
  }

}
