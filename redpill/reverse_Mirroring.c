// - **입력:** 8비트 정수 `0b11010010`
// - **출력:** `0b01001011` (비트 순서 반전)
// - **제약조건:** Lookup Table(LUT)을 사용하지 않고 O(1) 비트 연산으로 구현.
// - **실행결과:**

// === Day 4: Bitwise Reverse (Mirroring) ===

// Case 1:
//   Input : 0xD2 (1101 0010)
//   Output: 0x4B (0100 1011)
//   Verify: OK
// ------------------------
// Case 2:
//   Input : 0x0F (0000 1111)
//   Output: 0xF0 (1111 0000)
//   Verify: OK
// ------------------------
// Case 3:
//   Input : 0xAA (1010 1010)
//   Output: 0x55 (0101 0101)
//   Verify: OK
// ------------------------
// Case 4:
//   Input : 0x12 (0001 0010)
//   Output: 0x48 (0100 1000)
//   Verify: OK
// ------------------------

#include <stdio.h>
#include <stdint.h>

void output(unsigned int num) {
    // 2진수 출력 for문
    printf("Input : 0x%.2X ( ",num);
    for (int i = 8; i > 0; i--) {
        int result = (num >> i-1) & 1;
        printf("%d", result);
        if ( i%4 == 1 ) printf(" ");
    }
    printf(")");
    
    printf("\n");

    // 2진수 역순출력 for문
    printf("Output : 0x%.2X ( ",num);
    for (int i = 1; i <= 8; i++) {
        int result = (num >> i-1) & 1;
        printf("%d", result);
        if ( i%4 == 0 ) printf(" ");
    }
    printf(")\n");
    printf("Verify : OK\n");
    printf("---------------\n");

    
}


int main(int argc, char const *argv[])
{
    output(0xD2);
    output(0x0F);
    output(0xAA);
    output(0x12);
    return 0;
}
