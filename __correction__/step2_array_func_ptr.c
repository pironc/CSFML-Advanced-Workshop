/*
** EPITECH WORKSHOP, 2022
** CSFML Introduction
** File description:
** CSFML main
*/

#include "my.h"

int add(int x, int y)
{
    return (x + y);
}

int sub(int x, int y)
{
    return (x - y);
}

int mul(int x, int y)
{
    return (x * y);
}

int div(int x, int y)
{
    return (x / y);
}

int main(void)
{
    // Array of function pointer
    int (*menu_ptr[])(int, int) = {add, sub, mul, div};

    printf("Result : %d\n", menu_ptr[0](1, 2));
    return (0);
}