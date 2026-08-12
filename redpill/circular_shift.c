//  **Day 6. 원형 비트 시프트 (Circular Shift/Rotate)**
//     - **입력:** 32비트 정수, 이동할 비트 수 `n`, 방향(Left/Right)
//     - **출력:** 회전된 결과값
//     - **제약조건:** 버려지는 비트가 반대편으로 채워져야 함.
//     - **실행결과:**
    
    
//     === Day 6: Circular Shift (Rotate) ===
    
//     [Init]   Hex: 0xF0000000
//              Bin: 1111 0000 0000 0000 0000 0000 0000 0000 
    
//     [ROL 4]  Hex: 0x0000000F
//              Bin: 0000 0000 0000 0000 0000 0000 0000 1111 
//              (MSB bits moved to LSB)
    
//     [ROR 4]  Hex: 0xF0000000
//              Bin: 1111 0000 0000 0000 0000 0000 0000 0000 
//              (Restored to original)
    
//     [Test 2] Data: 0x12345678 -> ROR 8 -> 0x78123456
    




#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t num) { // 2진수 변환 및 출력용
    for (int i = 32; i > 0; i--) {
        int result = (num >> i-1) & 1;
        printf("%d", result);
        if ( i%4 == 1 ) printf(" ");
    }
}

void move_left(uint32_t num, uint16_t count, char printType) {
    // for (int i=1; i <= count; i++) { // 움직이는 횟수만큼 반복
    //     print_binary((num << i) | (num >> (32-i))); 
    //     // 움직이는 방향으로 i만큼 비트이동, 반대방향으로 32-i 만큼 이동 or연산으로 합체
    //     printf("\n");
    // }

    // 움직일 횟수만큼 반복할 필요없이 그냥 한번에 땡기면 되는거 아닌가?
    if (printType == 'x' || printType =='X') {
        // 들어온 32비트 정수를 움직일 비트수만큼 해당방향으로 이동한 값이랑
        // 움직여서 사라지지않은 비트수만큼 반대방향으로 움직여서 or연산으로 합치면
        printf("%.8X",((num << count) | (num >> (32-count))));
    }
    else if (printType == 'b' || printType == 'B') {
        print_binary((num << count) | (num >> (32-count)));
    }
    printf("\n");
}

void move_right(uint32_t num, uint16_t count, char printType) {
    // for (int i=1; i <= count; i++) {
    //     print_binary((num >> i) | (num << (32-i)));
    //     printf("\n");
    // }
    if (printType == 'x' || printType =='X') {
        printf("%.8X",((num >> count) | (num << (32-count))));
    }
    else if (printType == 'b' || printType == 'B') {
        print_binary((num >> count) | (num << (32-count)));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    printf("[Init]\tHex: 0xF0000000\n");
    printf("\tBin: ");
    print_binary(0xF0000000);
    printf("\n\n");

    printf("[ROL 4]\tHex: 0x");
    move_left(0xF0000000,4,'x');
    printf("\tBin: ");    
    move_left(0xF0000000,4,'b');
    printf("\t(MSB bits moved to LSB)\n\n");

    printf("[ROR 4]\tHex: 0x");
    move_right(0x0000000F,4,'x');
    printf("\tBin: ");
    move_right(0x0000000F,4,'b');
    printf("\t(Restored to original)\n\n");

    printf("[Test 2] Data: 0x12345678 -> ROR 8 -> 0x");
    move_right(0x12345678,8,'x');

    // 2진수를 전부 프린트하는걸 썼더니 마지막을 뽑아내서 16진수로 합치는 방법을 잊어버렸다

    return 0;
}
