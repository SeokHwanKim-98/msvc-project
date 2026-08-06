#include <stdio.h>
#include <stdint.h>

// define은 컴파일 전 전처리과정에서 미리 풀어둠
#define BIT_SET(var, pos)    ((var) |=  (1UL<<(pos)))
// var = var | 1UL 원하는 위치를 1로 바꾸자
#define BIT_CLEAR(var, pos)  ((var) &= ~(1UL<<(pos)))
// 원하는 위치를 0으로 바꾸자
#define BIT_TOGGLE(var, pos) ((var) ^=  (1UL<<(pos)))
// 원하는 위치를 반전시키자
#define BIT_CHECK(var, pos)  (((var) &   (1UL<<(pos)))>>(pos))


// UL = 8bit -> 1UL = 0001
// | => bit연산에서 사용하는 or 연산
// 8 |= (1UL << (0)) => 1000 | 0001 = 1001
// 8 |= (1UL << (1)) => 1000 | 0010 = 1010
// 8 |= (1UL << (4)) => 1000 | 0001 0000 = 0001 1000

int main(int argc, char const *argv[])
{
    uint32_t data = 0x12345678;
    // BIT_SET(data,1); // -> ((data) |= (1UL<<(0)))
    BIT_CLEAR(data,3); // -> ((data) &= ~(1UL<<(3)))
    BIT_TOGGLE(data,0); // -> ((data) ^= (1UL<<(3)))
    int bit_status = BIT_CHECK(data,0);
    bit_status = BIT_CHECK(data,3); // -> ((data) ^= (1UL<<(3)))
    return 0;
}
