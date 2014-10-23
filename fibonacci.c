#include <stdio.h>
int fibonacci(int n)
{
    if (n < 1) {
        return -1;
    }
    if (n ==1 || n ==2) {
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacci_m(int n)
{
    int result = 1;
    if (n < 1) {
        return -1;
    }
    
    if (n < 3) {
        return 1;
    }

    int prev_1 = 1, prev_2 = 1;

    while (n-- > 2) {
        prev_1 = prev_2;
        prev_2 = result;
        result = prev_1 + prev_2;
    }

    return result;
}

int fibonacci_m2(int n)
{
    int result = 1;
    if (n < 1) {
        return -1;
    }
    
    if (n < 3) {
        return 1;
    }

    int i;
    int prev_1 = 1;
    int prev_2 = 1;

    for (i = 2; i < n; ++i)
    {
        prev_1 = prev_2;
        prev_2 = result;
        result = prev_1 + prev_2;
    }
    return result;
}
