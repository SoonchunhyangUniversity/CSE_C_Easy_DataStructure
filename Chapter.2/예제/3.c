#include <stdio.h>

int factorial_iter(int n)
{
    int k, v = 1;
    for(k = n; k > 0; k--)
        v = v * k;

    return v;
}

int main()
{
    printf("%d\n", factorial_iter(5));

    return 0;
}
