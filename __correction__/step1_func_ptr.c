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

int main(void)
{
    // Function pointer
    int (*menu_ptr)(int, int) = &add;

    printf("Result : %d\n", menu_ptr(1, 2));
    return (0);
}