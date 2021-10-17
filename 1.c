#include <stdio.h>
#include <assert.h>
#include <math.h>

const double EPS = 1E-10;

typedef enum
{
    KV_ONE,
    KV_TWO, 
    KV_ZERO,
    LIN_ONE, 
    LIN_ZERO,
    LIN_INF
} KORNI;

int srav(double x, double y)
{
    if (fabs(x - y) < EPS)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void scan_coefficients(double *ptr_to_a, double *ptr_to_b, double *ptr_to_c)
{
    assert(ptr_to_a != NULL);
    assert(ptr_to_b != NULL);
    assert(ptr_to_c != NULL);
    while (3 != scanf("%lf%lf%lf", ptr_to_a, ptr_to_b, ptr_to_c))
    {
        printf("An error with input try again\n");
        while ('\n' != getchar())
        {
        }
    }
}

void discr(double a, double b, double c, double *D)
{
    assert(D != NULL);
    *D = b * b - (4 * a * c);
}

void resh_kv(double a, double b, double c, double d, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    *x1 = (-b + sqrt(d)) / (2 * a);
    *x2 = (-b - sqrt(d)) / (2 * a);
}

KORNI resh_lin(double b, double c, double *x1)
{
    assert(x1 != NULL);
    if (srav(b, 0))
    {
        *x1 = (-1) * c / b;
        return LIN_ONE;
    } 
    else
    {
        if (srav(c, 0))
        {
            return LIN_ZERO;
        }
        else
        {
            return LIN_INF;
        } 
    }
}

KORNI resh(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    double d = 0;
    if (srav(a, 0))
    {
        discr(a, b, c, &d);
        if (d < 0)
        {
            return KV_ZERO;
        }
        else
        {
            if (!srav(d, 0))
            {
                resh_kv(a, b, c, d, x1, x2);
                return KV_ONE;
            }
            else
            {
                resh_kv(a, b, c, d, x1, x2);
                return KV_TWO;
            }
        }
    }
    else
    {
        return resh_lin(b, c, x1);
    }
}

void answ(double x1, double x2, KORNI kor)
{
    switch (kor)
    {
    case KV_ONE:
        printf("This is a quadratic equation, D = 0\n");
        printf("x = %lf\n", x1);
        break;
    case KV_TWO:
        printf("This is a quadratic equation, D > 0\n");
        printf("x1=%lf x2 = %lf\n", x1, x2);
        break;
    case KV_ZERO:
        printf("This is a quadratic equation, D < 0\n");
        printf("no roots\n");
        break;
    case LIN_INF:
        printf("This is a linear equation\n");
        printf("any root\n");
        break;
    case LIN_ONE:
        printf("This is a linear equation\n");
        printf("x = %lf\n", x1);
        break;
    case LIN_ZERO:
        printf("This is a linear equation\n");
        printf("no roots\n");
        break;
    }
}

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, d = 0;
    KORNI kor;
    scan_coefficients(&a, &b, &c);
    kor = resh(a, b, c, &x1, &x2);
    answ(x1, x2, kor);
    return 0;
}