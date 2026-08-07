#include <stdio.h>

// int sum(int n) {
//     if (n == 0) {return 0;}
//     return n + sum(n-1);
// }

long long sum(int n){
    long long result=0;
    // for (size_t i = 1; i <= n; i++)
    // {
    //    result = result + i;
    // }
    //--------------------------------------------------//

    result = (n+1) * (n/2);
    return result;

    //--------------------------------------------------//

    int i = 0;
    while (i <= n) {
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int input = 1000000000000;
    
    // printf("까지 더할 수 : ");
    // scanf("%d", &input);
    long long result = sum(input);
    printf("출력값 : %Id",result);
    return 0;
}
