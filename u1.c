#include "u1.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

void run_all_tests() { assert(OK == test_discr()); 
                      assert(OK == test_kv()); 
                      assert(OK == test_ln()); 
                     }

Error test_discr() {
  double test_value = 1, test_a = 1, test_b = 3, test_c = 2, test_d = 0;
  discr(test_a,test_b,test_c,&test_d);
  if (abs(test_value - test_d) > EPS) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  return OK;
}

Error test_kv() {
  double test_a = 1, test_b = 3, test_c = 2, test_x1=-2, test_x2=-1, test_xx1 = 0,test_xx2 = 0;
  KORNI ans=KV_TWO;
  resh(test_a,test_b,test_c, &test_xx1, &test_xx2);
  if ((resh(test_a,test_b,test_c, &test_xx1, &test_xx2)!=ans) || (abs(test_xx2 - test_x2) > EPS) || (abs(test_xx2 - test_x2)) > EPS) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  
  double test_a = 1, test_b = 2, test_c = 1, test_x1=-1, test_xx1 = 0,test_xx2 = 0;
  KORNI ans=KV_ONE;
  resh(test_a,test_b,test_c, &test_xx1, &test_xx2);
  if ((resh(test_a,test_b,test_c, &test_xx1, &test_xx2)!=ans) || (abs(test_xx2 - test_x2)) > EPS) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  
  double test_value = 1, test_a = 1, test_b = 2, test_c = 10, test_xx1 = 0,test_xx2 = 0;
  KORNI ans=KV_ZERO;
  resh(test_a,test_b,test_c, &test_xx1, &test_xx2);
  if ((resh(test_a,test_b,test_c, &test_xx1, &test_xx2)!=ans)) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  
  return OK;
}

Error test_ln(){
  double test_b = 2, test_c = 1, test_x1=-0.5, test_xx1 = 0;
  KORNI ans=LIN_ONE;
  resh_lin(test_b,test_c, &test_xx1);
  if ((resh_lin(test_b,test_c, &test_xx1)!=ans) || (abs(test_xx1 - test_x1)) > EPS) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  
  double test_b = 0, test_c = 1, test_xx1 = 0;
  KORNI ans=LIN_ZERO;
  resh_lin(test_b,test_c, &test_xx1);
  if (resh_lin(test_b,test_c, &test_xx1)!=ans) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
  
  double test_b = 0, test_c = 0, test_xx1 = 0;
  KORNI ans=LIN_INF
  resh_lin(test_b,test_c, &test_xx1);
  if (resh_lin(test_b,test_c, &test_xx1)!=ans) {
    printf("F*ck this sh*t I'm out\n");
    return ligma;
  }
    return OK;
}
