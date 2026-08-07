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

// 외워두면 좋은 16진수 -> 2진수
// 0x5 = 0101 0xA = 1010 0xF = 1111


// UL = 8bit -> 1UL = 0001
// | => bit연산에서 사용하는 or 연산
// 8 |= (1UL << (0)) => 1000 | 0001 = 1001
// 8 |= (1UL << (1)) => 1000 | 0010 = 1010
// 8 |= (1UL << (4)) => 1000 | 0001 0000 = 0001 1000

int get_bi(data)
{
    int arr_bi[32];
    int temp=data;
    for(int i=1; i <= 32; i++) {
        if (temp%2 == 0) { arr_bi[i-1] = 0; }
        else {arr_bi[i-1] = 1;}
        temp = temp/2;
    }
    for (int i=31; i>=0; i--) {
        if (i%4 == 0) { printf("%d ",arr_bi[i]); }
        else {printf("%d",arr_bi[i]); }
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    uint32_t data = 0x12345678;
    int num = 0;

    printf("[Init] Hex :0x%.8x | Bin : ",data);
    printf("\n",get_bi(data));
    // scanf("%d",&num);

    BIT_SET(data,0); // -> ((data) |= (1UL<<(0)))
    printf("\n[SET] Target: Bit 0\n");
    printf("Result  Hex :0x%.8x | Bin : ",data);
    get_bi(data);
    printf("\n");

    // scanf("%d",&num);
    BIT_CLEAR(data,4); // -> ((data) &= ~(1UL<<(3)))
    printf("\n[CLEAR] Target: Bit 4\n");
    printf("Result  Hex :0x%.8x | Bin : ", data);
    get_bi(data);
    printf("\n");

    // scanf("%d",num);
    BIT_TOGGLE(data,3); // -> ((data) ^= (1UL<<(3)))
    printf("\n[TOGGLE] Target: Bit 3\n");
    printf("Result  Hex :0x%.8x | Bin : ", data);
    get_bi(data);
    printf("\n");

    
    int bit_status = BIT_CHECK(data,0);
    bit_status = BIT_CHECK(data,3); // -> ((data) ^= (1UL<<(3)))
    printf("\n[CHECK] Bit 3 is currently: %d",bit_status);
    return 0;
}


