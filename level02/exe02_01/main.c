#include <stdio.h>
#include "increment.h"
#include "negate.h"
int main(void)
{
    int num;

    while(scanf("%d", &num) == 1)
        printf("%d + 1 = %d, -(%d) = %d\n", num, increment(num), num, negate(num));
    
    return 0;
}