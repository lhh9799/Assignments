#include <stdio.h>

int main() {
    int i, idx = 0, A, B, C, integer, div = 1, sosu;    //integer = ������ 

    scanf("%d %d", &A, &B);
    C = B;

    while(C-- > 0) {
        div *= 10;
    }

    integer = A/div;       //������ 
    sosu = A - (integer*div);

    printf("%d",integer);
    if(B != 0)
    {
        printf(".");
           printf("%d\n", sosu);
       }


    return 0;
}
