#include <stdio.h>

int main() 
{
    int i, n, sum = 0, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        sum += tmp;
    }
    printf("%d", sum);
    return 0;
}
