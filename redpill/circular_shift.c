#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t num) {
    for (int i = 32; i > 0; i--) {
        int result = (num >> i-1) & 1;
        printf("%d", result);
        if ( i%4 == 1 ) printf(" ");
    }
}

void move_left(uint32_t num, uint16_t count) {
    for (int i=1; i <= count; i++) { // 움직이는 횟수만큼 반복
        print_binary((num << i) | (num >> (32-i))); 
        // 움직이는 방향으로 i만큼 비트이동, 반대방향으로 32-i 만큼 이동 or연산으로 합체
        printf("\n");
    }
}

void move_right(uint32_t num, uint16_t count) {
    for (int i=1; i <= count; i++) {
        print_binary((num >> i) | (num << (32-i)));
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    move_left(0xF0000000,4);
    printf("----------------------------------------\n");
    move_right(0x0000000F,4);
    printf("----------------------------------------\n");
    move_right(0x12345678, 8);


    //2진수로 결과는 냈는데 이걸 16진수로 어떻게 다시보지?
    return 0;
}
