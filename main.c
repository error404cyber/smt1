#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "Quadreq.c"
#include "lib_testQuadrEq.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, d = 0;
    KORNI kor=LIN_ZERO;
    run_all_tests();
    printf("Ready\n");
    return 0;
}
