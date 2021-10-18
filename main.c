#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "Quadreq.c"
#include "lib_testQuadrEq.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, d = 0;
    KORNI kor=LIN_ZERO;
    scan_coefficients(&a, &b, &c);
    run_all_tests();
    printf("Ready");
    return 0;
}
