#include <stdio.h>
int main()
{
    double xl = 0, xn, n;
    int truth = 1;
    if (scanf("%lf\n", &n) == 1)
    {
        if (scanf("%lf\n", &xl) == 1)
        {
            n--;
        }
    }
    while (n>=1)
    {
        if (scanf("%lf\n", &xn) == 1)
        {
            if (xl<xn)
            {
                truth = 0;
            }
            n--;
        }

    }
    if (truth == 1)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}