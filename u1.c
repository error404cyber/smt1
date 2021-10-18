#include "u1.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

void run_all_tests() { assert(OK == test_echo()); }
Error test_discr() {
  double test_value = 1, test_a = 1, test_b = 3, test_c = 2, test_d = 0;
  discr(test_a,test_b,test_c,&test_d);
  if (abs(test_value - test_d) > EPS) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  return OK;
}
