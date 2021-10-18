#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "Quadreq.c"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, d = 0;
    KORNI kor=LIN_ZERO;
    scan_coefficients(&a, &b, &c);
    kor = resh(a, b, c, &x1, &x2);
    answ(x1, x2, kor);
    return 0;
}
