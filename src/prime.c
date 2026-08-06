#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int count;
    int pn_count = 0;
    time_t start_time, end_time;
    printf("소수를 찾을 수 : ");
    scanf("%d", &count);


    // for (int i = 2; i < count; i++)
    // {
    //     int pn = 1;
    //     for (int j = 2; j < i; j++)
    //     {
    //         if(i%j == 0) {
    //             pn = 0;
    //             break;
    //         }
    //     }
    //     if (pn) {
    //         printf("%5d",i);
    //         pn_count++;
    //         if (pn_count%5 == 0) {
    //             printf("\n");
    //         }
    //     }
        
    // }
    time(&start_time);

    printf("2     3     5     7");
    for (int i = 2; i< count; i++) {
        if ((i % 2) != 0 && (i % 3) != 0 && (i % 5) != 0 && (i % 7) != 0) {
            printf("%10d", i);
            pn_count++;
            if (pn_count % 5 == 0) {
                printf("\r\n");
            }
        }
    }
    time(&end_time);

    printf("\n소수의 개수 %d",pn_count+4);
    printf("\r\n걸린 시간 : %I64d", (end_time - start_time));

    return 0;
}
