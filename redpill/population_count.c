// Day 5. 1의 개수 세기 (Population Count)
// 입력: 32비트 정수
// 출력: 켜져 있는 비트(1)의 개수
// 제약조건: 루프(for/while) 없이 비트 연산만으로 구현 (Brian Kernighan 알고리즘 등 활용).

#include <stdio.h>
#include <stdint.h>
#include <intrin.h>

int cNum = 0;

void print_binary(uint32_t num) {
    for (int i = 32; i > 0; i--) {
        int result = (num >> i-1) & 1;
        printf("%d", result);
        if ( i%4 == 1 ) printf(" ");
    }
}


int print_algorithm(uint32_t input) {
    printf("Case %d: Input 0x%.8X\n",++cNum,input);
    printf("\t[Naive]\t\t: %d\n", naive_algorithm(input));
    printf("\t[Kernighan]\t: %d\n", kernighan_algorithm(input));
    printf("\t[SWAR]\t\t: %d\n", swar_algorithm(input));
    printf("\t[Built-in]\t: %d\n",__popcnt(input));

    printf("--------------------------------\n");
    return 0;
}   


int naive_algorithm(uint32_t num) {
    int count = 0;
    for (int i=0; i<32; i++) { // 입력제한에 32비트 정수가 걸려있으니까 32번 반복
        if ((num & 0x01) == 0x01) { count++; } // 입력과 01 &연산으로 가장 오른쪽 비트가 1이면 카운트 증가
        // print_binary(num); // 눈으로 보고싶다
        // printf("\t개수 : %d\n",count);
        num = (num>>1); // 비트를 하나 오른쪽으로 밀어서 다음 비교 준비
    }
    return count;
}


int kernighan_algorithm(uint32_t num) {
    int count = 0;
    while (num != 0) { // num이 0이 아니면 반복
        num = num & (num-1); // 가장 오른쪽에 있는 비트 1 뽑아내기
        // print_binary(num); // 눈으로 보자
        // printf("\t개수 : %d\n",count);
        count++;
    }
    return count;
}

int swar_algorithm(uint32_t num) {
    // print_binary(num); // 눈으로 보자
    // printf("\n");

    num = num - ((num >> 1) & 0x55555555); // 2비트마가 1의 갯수를 저장
    // print_binary(num); // 눈으로 보자
    // printf("\n");

    num = (num & 0x33333333) + ((num >> 2) & 0x33333333); // 4비트 단위로 병합
    // print_binary(num); // 눈으로 보자
    // printf("\n");

    num = (num + (num >> 4)) & 0x0F0F0F0F; // 8비트 단위로 병합
    // print_binary(num); // 눈으로 보자
    // printf("\n");

    num = num + (num >> 8); // 16비트 단위로 병합
    // print_binary(num); // 눈으로 보자
    // printf("\n");

    num = num + (num >> 16); // 32비트 단위로 병합
    // print_binary(num); // 눈으로 보자
    // printf("\n");

    return num & 0x3F; // 입력제한이 32비트임으로 하위 비트6개 값만 수집
}



int main(int argc, char const *argv[])
{
    print_algorithm(0x00000000);
    print_algorithm(0x00000007);
    print_algorithm(0x12345678);
    print_algorithm(0xFFFFFFFF);
    return 0;
}
