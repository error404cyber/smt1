#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "lib.h"

/**
 * Функция сравнивает 2 числа на то, равны ли они
 * если разница между числами меньше заданной константы, то они считаются равными
 *
 * @param x Первое число
 * @param y Второе число
 * @return возвращает больше ли разница между числами нуля
 */

int isEqual(double x, double y)
{
    return (fabs(x - y) >= EPS);
}

/**
 * Проверяет ввод на корректность
 * считывает 3 коэффицента до тех пор, пока не будет совершен правильный ввод
 *
 *
 * @param ptr_to_a Первое число
 * @param ptr_to_b Второе число
 * @param ptr_to_c Третье число
 */

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

/**
 * Функция считает дискриминант
 *
 * @param a первый коэффицент
 * @param b второй коэффицент
 * @param c третий коэффицент
 * @param d дискриминант
 */

void discr(double a, double b, double c, double *D)
{
    assert(D != NULL);
    *D = b * b - (4 * a * c);
}

/**
 * Функция находит корни квадратного уравнения, используя дискриминант
 *
 * @param a первый коэффицент
 * @param b второй коэффицент
 * @param c третий коэффицент
 * @param d дискриминант
 * @param x1 первый корень
 * @param x2 второй корень
 */

void resh_kv(double a, double b, double c, double d, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    *x1 = (-b + sqrt(d)) / (2 * a);
    *x2 = (-b - sqrt(d)) / (2 * a);
}

/**
 * Функция решает линейное уравнение
 *
 * @param b первый коэффицент
 * @param c второй коэффицент
 * @param x1 корень
 */

KORNI resh_lin(double b, double c, double *x1)
{
    assert(x1 != NULL);
    if (isEqual(b, 0))
    {
        *x1 = (-1) * c / b;
        return LIN_ONE;
    } 
    else
    {
        if (isEqual(c, 0))
        {
            return LIN_ZERO;
        }
        else
        {
            return LIN_INF;
        } 
    }
}

/**
 * Функция решает уравнение
 *
 * @param a первый коэффицент
 * @param b второй коэффицент
 * @param c третий коэффицент
 * @param x1 первый корень
 * @param x2 второй корень
 */

KORNI resh(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    double d = 0;
    if (isEqual(a, 0))
    {
        discr(a, b, c, &d);
        if (d < EPS)
        {
            return KV_ZERO;
        } //нет корней в квадратном
        else
        {
            if (!srav(d, 0))
            {
                resh_kv(a, b, c, d, x1, x2);
                return KV_ONE; //1 корень в квадратном
            }
            else
            {
                resh_kv(a, b, c, d, x1, x2);
                return KV_TWO; //2 корня в квадратном
            }
        }
    }
    else
    {
        return resh_lin(b, c, x1);
    }
}

/**
 * Функция выводит нужный ответ
 *
 * @param x1 первый корень
 * @param x2 второй корень
 * @param kor значение уравнения
 * 
 */

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


