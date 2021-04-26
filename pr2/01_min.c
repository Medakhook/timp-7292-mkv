#include <stdio.h>
int main()
{
    double n, x, min = 0;
    if (scanf("%lf\n", &n) == 1)
    {
        if (scanf("%lf\n", &x) == 1)
        {
            min = x;
            n--;
        }
        while (n>=1)
        {
            if (scanf("%lf\n", &x) == 1)
            {
                if (min>x)
                {
                    min = x;
                }
                n--;
            }
        }
    }
    printf("%lf\n", min);
    return 0;
}
