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

#include "omega64c.h"
static double D534[124];
static double D535[124];
static double D536[124];
static double D537[124];
static double D538[28];
static double D539[28];

void init_fft512() {
  for(int i51585 = 0; i51585 <= 30; i51585++) {
    for(int i51621 = 0; i51621 <= 1; i51621++) {
      D534[((i51585*4) + (i51621*2))] = omega(512, ((i51585 + 1)*(i51621*2)));
      D534[((i51585*4) + (i51621*2) + 1)] = omega(512, ((i51585 + 1)*((i51621*2) + 4)));
    }
  }
  for(int i51585 = 0; i51585 <= 30; i51585++) {
    for(int i51599 = 0; i51599 <= 1; i51599++) {
      D535[((i51585*4) + (i51599*2))] = omega(512, ((i51585 + 1)*(1 + (i51599*2))));
      D535[((i51585*4) + (i51599*2) + 1)] = omega(512, ((i51585 + 1)*(5 + (i51599*2))));
    }
  }
  for(int i51586 = 0; i51586 <= 30; i51586++) {
    for(int i51629 = 0; i51629 <= 1; i51629++) {
      D536[((i51586*4) + (i51629*2))] = omega(512, ((33 + i51586)*(i51629*2)));
      D536[((i51586*4) + (i51629*2) + 1)] = omega(512, ((33 + i51586)*((i51629*2) + 4)));
    }
  }
  for(int i51586 = 0; i51586 <= 30; i51586++) {
    for(int i51609 = 0; i51609 <= 1; i51609++) {
      D537[((i51586*4) + (i51609*2))] = omega(512, ((33 + i51586)*(1 + (i51609*2))));
      D537[((i51586*4) + (i51609*2) + 1)] = omega(512, ((33 + i51586)*(5 + (i51609*2))));
    }
  }
  for(int i51611 = 0; i51611 <= 6; i51611++) {
    for(int i51637 = 0; i51637 <= 1; i51637++) {
      D538[((i51611*4) + (i51637*2))] = omega(64, ((i51611 + 1)*i51637));
      D538[((i51611*4) + (i51637*2) + 1)] = omega(64, ((i51611 + 1)*(i51637 + 2)));
    }
  }
  for(int i51612 = 0; i51612 <= 6; i51612++) {
    for(int i51645 = 0; i51645 <= 1; i51645++) {
      D539[((i51612*4) + (i51645*2))] = omega(64, ((9 + i51612)*i51645));
      D539[((i51612*4) + (i51645*2) + 1)] = omega(64, ((9 + i51612)*(i51645 + 2)));
    }
  }

}

void fft512(_Complex double  *Y, _Complex double  *X) {
  static _Complex double T13024[512];
  for(int i51587 = 0; i51587 <= 7; i51587++) {
    static _Complex double T13025[64];
    for(int i51613 = 0; i51613 <= 3; i51613++) {
      _Complex double a88908, a88909, a88910, a88911, a88913, a88914, a88915, a88916, s38973, s38974, s38975, s38976, s38977, s38978, s38979, s38980, s38981, s38982, s38983, s38984, s38985, s38986, s38987, s38988, s38989, s38990, s38991, s38992, s38993, s38994, s38995, s38996, s38997, t87492, t87493, t87494, t87495, t87496, t87497, t87498, t87499, t87500, t87501, t87502, t87503, t87504, t87505, t87506, t87507, t87508, t87509, t87510, t87511, t87512, t87513, t87514, t87515, t87516, t87517, t87518, t87519, t87520, t87521, t87522;
      _Complex double  *a88907;
      _Complex double  *a88912;
      a88907 = (X + i51587 + (8*i51613));
      s38973 = *(a88907);
      s38974 = *((a88907 + 256));
      t87492 = (s38973 + s38974);
      t87493 = (s38973 - s38974);
      s38975 = *((a88907 + 128));
      s38976 = *((a88907 + 384));
      t87494 = (s38975 + s38976);
      t87495 = (t87492 + t87494);
      t87496 = (t87492 - t87494);
      a88908 = (__I__*(s38975 - s38976));
      t87497 = (t87493 + a88908);
      t87498 = (t87493 - a88908);
      s38977 = *((a88907 + 32));
      s38978 = *((a88907 + 288));
      t87499 = (s38977 + s38978);
      t87500 = (s38977 - s38978);
      s38979 = *((a88907 + 160));
      s38980 = *((a88907 + 416));
      t87501 = (s38979 + s38980);
      t87502 = (t87499 + t87501);
      s38981 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t87499 - t87501));
      a88909 = (__I__*(s38979 - s38980));
      s38982 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t87500 + a88909));
      s38983 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t87500 - a88909));
      s38984 = *((a88907 + 64));
      s38985 = *((a88907 + 320));
      t87503 = (s38984 + s38985);
      t87504 = (s38984 - s38985);
      s38986 = *((a88907 + 192));
      s38987 = *((a88907 + 448));
      t87505 = (s38986 + s38987);
      t87506 = (t87503 + t87505);
      s38988 = (__I__*(t87503 - t87505));
      a88910 = (__I__*(s38986 - s38987));
      s38989 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t87504 + a88910));
      s38990 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t87504 - a88910));
      s38991 = *((a88907 + 96));
      s38992 = *((a88907 + 352));
      t87507 = (s38991 + s38992);
      t87508 = (s38991 - s38992);
      s38993 = *((a88907 + 224));
      s38994 = *((a88907 + 480));
      t87509 = (s38993 + s38994);
      t87510 = (t87507 + t87509);
      s38995 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t87507 - t87509));
      a88911 = (__I__*(s38993 - s38994));
      s38996 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t87508 + a88911));
      s38997 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t87508 - a88911));
      t87511 = (t87495 + t87506);
      t87512 = (t87495 - t87506);
      t87513 = (t87502 + t87510);
      a88912 = (T13025 + (16*i51613));
      *(a88912) = (t87511 + t87513);
      *((a88912 + 8)) = (t87511 - t87513);
      a88913 = (__I__*(t87502 - t87510));
      *((a88912 + 4)) = (t87512 + a88913);
      *((a88912 + 12)) = (t87512 - a88913);
      t87514 = (t87497 + s38989);
      t87515 = (t87497 - s38989);
      t87516 = (s38982 + s38996);
      *((a88912 + 1)) = (t87514 + t87516);
      *((a88912 + 9)) = (t87514 - t87516);
      a88914 = (__I__*(s38982 - s38996));
      *((a88912 + 5)) = (t87515 + a88914);
      *((a88912 + 13)) = (t87515 - a88914);
      t87517 = (t87496 + s38988);
      t87518 = (t87496 - s38988);
      t87519 = (s38981 + s38995);
      *((a88912 + 2)) = (t87517 + t87519);
      *((a88912 + 10)) = (t87517 - t87519);
      a88915 = (__I__*(s38981 - s38995));
      *((a88912 + 6)) = (t87518 + a88915);
      *((a88912 + 14)) = (t87518 - a88915);
      t87520 = (t87498 + s38990);
      t87521 = (t87498 - s38990);
      t87522 = (s38983 + s38997);
      *((a88912 + 3)) = (t87520 + t87522);
      *((a88912 + 11)) = (t87520 - t87522);
      a88916 = (__I__*(s38983 - s38997));
      *((a88912 + 7)) = (t87521 + a88916);
      *((a88912 + 15)) = (t87521 - a88916);
    }
    _Complex double a88957, a88958, a88959, a88960, a88962, t87539, t87540, t87541;
    _Complex double  *a88961;
    a88957 = *(T13025);
    a88958 = *((T13025 + 32));
    t87539 = (a88957 + a88958);
    t87540 = (a88957 - a88958);
    a88959 = *((T13025 + 16));
    a88960 = *((T13025 + 48));
    t87541 = (a88959 + a88960);
    a88961 = (T13024 + (64*i51587));
    *(a88961) = (t87539 + t87541);
    *((a88961 + 32)) = (t87539 - t87541);
    a88962 = (__I__*(a88959 - a88960));
    *((a88961 + 16)) = (t87540 + a88962);
    *((a88961 + 48)) = (t87540 - a88962);
    for(int i51611 = 0; i51611 <= 6; i51611++) {
      _Complex double a89010, s39014, s39015, s39016, s39017, t87558, t87559, t87560;
      double  *a89009;
      _Complex double  *b14255;
      _Complex double  *b14256;
      b14255 = (T13025 + i51611);
      a89009 = (D538 + (4*i51611));
      s39014 = (*(a89009)**((b14255 + 1)));
      s39015 = (*((a89009 + 1))**((b14255 + 33)));
      t87558 = (s39014 + s39015);
      t87559 = (s39014 - s39015);
      s39016 = (*((a89009 + 2))**((b14255 + 17)));
      s39017 = (*((a89009 + 3))**((b14255 + 49)));
      t87560 = (s39016 + s39017);
      b14256 = (T13024 + (64*i51587) + i51611);
      *((b14256 + 1)) = (t87558 + t87560);
      *((b14256 + 33)) = (t87558 - t87560);
      a89010 = (__I__*(s39016 - s39017));
      *((b14256 + 17)) = (t87559 + a89010);
      *((b14256 + 49)) = (t87559 - a89010);
    }
    _Complex double a89056, a89057, a89058, a89059, s39022, s39023, t87577, t87578;
    _Complex double  *b14262;
    a89056 = *((T13025 + 8));
    a89057 = (__I__**((T13025 + 40)));
    t87577 = (a89056 + a89057);
    t87578 = (a89056 - a89057);
    a89058 = *((T13025 + 24));
    a89059 = (__I__**((T13025 + 56)));
    s39022 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a89058 + a89059));
    s39023 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a89058 - a89059));
    b14262 = (T13024 + (64*i51587));
    *((b14262 + 8)) = (t87577 + s39022);
    *((b14262 + 40)) = (t87577 - s39022);
    *((b14262 + 24)) = (t87578 + s39023);
    *((b14262 + 56)) = (t87578 - s39023);
    for(int i51612 = 0; i51612 <= 6; i51612++) {
      _Complex double a89107, s39040, s39041, s39042, s39043, t87595, t87596, t87597;
      double  *a89106;
      _Complex double  *b14281;
      _Complex double  *b14282;
      b14281 = (T13025 + i51612);
      a89106 = (D539 + (4*i51612));
      s39040 = (*(a89106)**((b14281 + 9)));
      s39041 = (*((a89106 + 1))**((b14281 + 41)));
      t87595 = (s39040 + s39041);
      t87596 = (s39040 - s39041);
      s39042 = (*((a89106 + 2))**((b14281 + 25)));
      s39043 = (*((a89106 + 3))**((b14281 + 57)));
      t87597 = (s39042 + s39043);
      b14282 = (T13024 + (64*i51587) + i51612);
      *((b14282 + 9)) = (t87595 + t87597);
      *((b14282 + 41)) = (t87595 - t87597);
      a89107 = (__I__*(s39042 - s39043));
      *((b14282 + 25)) = (t87596 + a89107);
      *((b14282 + 57)) = (t87596 - a89107);
    }
  }
  _Complex double a89174, a89175, a89176, a89177, a89178, a89179, a89180, a89181, a89182, s39052, s39053, s39054, s39055, t87646, t87647, t87648, t87649, t87650, t87651, t87652, t87653, t87654, t87655, t87656;
  a89174 = *(T13024);
  a89175 = *((T13024 + 256));
  t87646 = (a89174 + a89175);
  t87647 = (a89174 - a89175);
  a89176 = *((T13024 + 128));
  a89177 = *((T13024 + 384));
  t87648 = (a89176 + a89177);
  t87649 = (t87646 + t87648);
  t87650 = (t87646 - t87648);
  a89178 = (__I__*(a89176 - a89177));
  t87651 = (t87647 + a89178);
  t87652 = (t87647 - a89178);
  a89179 = *((T13024 + 64));
  a89180 = *((T13024 + 320));
  t87653 = (a89179 + a89180);
  s39052 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a89179 - a89180));
  a89181 = *((T13024 + 192));
  a89182 = *((T13024 + 448));
  t87654 = (a89181 + a89182);
  s39053 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a89181 - a89182));
  t87655 = (t87653 + t87654);
  s39054 = (__I__*(t87653 - t87654));
  t87656 = (s39052 + s39053);
  s39055 = (__I__*(s39052 - s39053));
  *(Y) = (t87649 + t87655);
  *((Y + 256)) = (t87649 - t87655);
  *((Y + 64)) = (t87651 + t87656);
  *((Y + 320)) = (t87651 - t87656);
  *((Y + 128)) = (t87650 + s39054);
  *((Y + 384)) = (t87650 - s39054);
  *((Y + 192)) = (t87652 + s39055);
  *((Y + 448)) = (t87652 - s39055);
  for(int i51585 = 0; i51585 <= 30; i51585++) {
    _Complex double a89262, s39096, s39097, s39098, s39099, s39100, s39101, s39102, s39103, s39104, s39105, s39106, s39107, t87705, t87706, t87707, t87708, t87709, t87710, t87711, t87712, t87713, t87714, t87715;
    int a89260;
    double  *a89261;
    double  *a89263;
    _Complex double  *b14307;
    _Complex double  *b14308;
    b14307 = (T13024 + i51585);
    a89260 = (4*i51585);
    a89261 = (D534 + a89260);
    s39096 = (*(a89261)**((b14307 + 1)));
    s39097 = (*((a89261 + 1))**((b14307 + 257)));
    t87705 = (s39096 + s39097);
    t87706 = (s39096 - s39097);
    s39098 = (*((a89261 + 2))**((b14307 + 129)));
    s39099 = (*((a89261 + 3))**((b14307 + 385)));
    t87707 = (s39098 + s39099);
    t87708 = (t87705 + t87707);
    t87709 = (t87705 - t87707);
    a89262 = (__I__*(s39098 - s39099));
    t87710 = (t87706 + a89262);
    t87711 = (t87706 - a89262);
    a89263 = (D535 + a89260);
    s39100 = (*(a89263)**((b14307 + 65)));
    s39101 = (*((a89263 + 1))**((b14307 + 321)));
    t87712 = (s39100 + s39101);
    s39102 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(s39100 - s39101));
    s39103 = (*((a89263 + 2))**((b14307 + 193)));
    s39104 = (*((a89263 + 3))**((b14307 + 449)));
    t87713 = (s39103 + s39104);
    s39105 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(s39103 - s39104));
    t87714 = (t87712 + t87713);
    s39106 = (__I__*(t87712 - t87713));
    t87715 = (s39102 + s39105);
    s39107 = (__I__*(s39102 - s39105));
    b14308 = (Y + i51585);
    *((b14308 + 1)) = (t87708 + t87714);
    *((b14308 + 257)) = (t87708 - t87714);
    *((b14308 + 65)) = (t87710 + t87715);
    *((b14308 + 321)) = (t87710 - t87715);
    *((b14308 + 129)) = (t87709 + s39106);
    *((b14308 + 385)) = (t87709 - s39106);
    *((b14308 + 193)) = (t87711 + s39107);
    *((b14308 + 449)) = (t87711 - s39107);
  }
  _Complex double a89352, a89353, a89354, a89355, a89356, a89357, a89358, a89359, a89360, a89361, s39120, s39121, s39122, s39123, s39124, s39125, t87764, t87765, t87766, t87767, t87768, t87769, t87770, t87771;
  a89352 = *((T13024 + 32));
  a89353 = (__I__**((T13024 + 288)));
  t87764 = (a89352 + a89353);
  t87765 = (a89352 - a89353);
  a89354 = *((T13024 + 96));
  a89355 = (__I__**((T13024 + 352)));
  s39120 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(a89354 + a89355));
  s39121 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(a89354 - a89355));
  a89356 = *((T13024 + 160));
  a89357 = (__I__**((T13024 + 416)));
  s39122 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a89356 + a89357));
  s39123 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a89356 - a89357));
  a89358 = *((T13024 + 224));
  a89359 = (__I__**((T13024 + 480)));
  s39124 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(a89358 + a89359));
  s39125 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(a89358 - a89359));
  t87766 = (t87764 + s39122);
  t87767 = (t87764 - s39122);
  t87768 = (s39120 + s39124);
  *((Y + 32)) = (t87766 + t87768);
  *((Y + 288)) = (t87766 - t87768);
  a89360 = (__I__*(s39120 - s39124));
  *((Y + 160)) = (t87767 + a89360);
  *((Y + 416)) = (t87767 - a89360);
  t87769 = (t87765 + s39123);
  t87770 = (t87765 - s39123);
  t87771 = (s39121 + s39125);
  *((Y + 96)) = (t87769 + t87771);
  *((Y + 352)) = (t87769 - t87771);
  a89361 = (__I__*(s39121 - s39125));
  *((Y + 224)) = (t87770 + a89361);
  *((Y + 480)) = (t87770 - a89361);
  for(int i51586 = 0; i51586 <= 30; i51586++) {
    _Complex double a89441, s39166, s39167, s39168, s39169, s39170, s39171, s39172, s39173, s39174, s39175, s39176, s39177, t87820, t87821, t87822, t87823, t87824, t87825, t87826, t87827, t87828, t87829, t87830;
    int a89439;
    double  *a89440;
    double  *a89442;
    _Complex double  *b14333;
    _Complex double  *b14334;
    b14333 = (T13024 + i51586);
    a89439 = (4*i51586);
    a89440 = (D536 + a89439);
    s39166 = (*(a89440)**((b14333 + 33)));
    s39167 = (*((a89440 + 1))**((b14333 + 289)));
    t87820 = (s39166 + s39167);
    t87821 = (s39166 - s39167);
    s39168 = (*((a89440 + 2))**((b14333 + 161)));
    s39169 = (*((a89440 + 3))**((b14333 + 417)));
    t87822 = (s39168 + s39169);
    t87823 = (t87820 + t87822);
    t87824 = (t87820 - t87822);
    a89441 = (__I__*(s39168 - s39169));
    t87825 = (t87821 + a89441);
    t87826 = (t87821 - a89441);
    a89442 = (D537 + a89439);
    s39170 = (*(a89442)**((b14333 + 97)));
    s39171 = (*((a89442 + 1))**((b14333 + 353)));
    t87827 = (s39170 + s39171);
    s39172 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(s39170 - s39171));
    s39173 = (*((a89442 + 2))**((b14333 + 225)));
    s39174 = (*((a89442 + 3))**((b14333 + 481)));
    t87828 = (s39173 + s39174);
    s39175 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(s39173 - s39174));
    t87829 = (t87827 + t87828);
    s39176 = (__I__*(t87827 - t87828));
    t87830 = (s39172 + s39175);
    s39177 = (__I__*(s39172 - s39175));
    b14334 = (Y + i51586);
    *((b14334 + 33)) = (t87823 + t87829);
    *((b14334 + 289)) = (t87823 - t87829);
    *((b14334 + 97)) = (t87825 + t87830);
    *((b14334 + 353)) = (t87825 - t87830);
    *((b14334 + 161)) = (t87824 + s39176);
    *((b14334 + 417)) = (t87824 - s39176);
    *((b14334 + 225)) = (t87826 + s39177);
    *((b14334 + 481)) = (t87826 - s39177);
  }

}
