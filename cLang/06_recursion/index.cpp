#include <stdio.h>

void p(int n)
{
    if (n > 10)
    {
        return;
    } // base case
    printf("%d ", n);
    p(n + 1); // recursive call
}

int f(int n)
{
    if (n == 1)
    {
        return 1; // base case
    }
    return n * f(n - 1); // recursive call
}
int main()
{
    p(1);
    return 0;
}
