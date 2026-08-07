#include <stdio.h>
void swap (void *a, int *b) {

    printf("a : %c, b : %d\n",*(char*)a,*(int*)b);

    int temp = *(int*)a; // * -> 역참조
    *(int*)a = *b;
    *b = temp;

}
int main(int argc, char const *argv[])
{
    int a = 49, b = 2;

    swap(&a,&b);

    printf("a : %d, b : %d",a,b);
    return 0;
}
