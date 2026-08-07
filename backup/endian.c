#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool is_little_endian(uint32_t input_data) {
    bool result = false;
    // data를 주소로 받는다 -> int32값의 주소를 int8로 형변환해서 받고
    // 가장 앞 메모리 가장 뒷 메모리 비교 ->
    // 앞 메모리가 더 큰값이면 true 작은값이면 false
    // ??
    uint8_t* temp = (uint8_t*)&input_data;
    // 변환되어 받은값의 마지막을 어떻게 찾는가
    // 32를 8로 변환했으니 마지막번호는 항상 3?
    
    // 크기 순서대로라면 굳이 처음과 끝을 비교할 이유가 있는가? -> 없다
    // 큰 값대로 들어온다? 들어온 순서? 의 역방향?
    if (temp[0] > temp[1])  { result = true; }

    return result;
}

uint32_t swap_endian(uint32_t val) {
// val = network_data = 0x12345678
    return ((val>>24) & 0x000000FF |
            (val>>8)  & 0x0000FF00 |
            (val<<8)  & 0x00FF0000 |
            (val<<24) & 0xFF000000
    );

}


int main(int argc, char const *argv[])
{
    uint32_t network_data = 0x12345678;

    printf("=== Day 2: Endianness Conversion ===\n");
    printf("Received Data (Hex): 0x%.8x\n", network_data);

    if(is_little_endian(network_data)) {
        printf("[System Check] This system is Little Endian.\n");
        printf(" -> Need to swap bytes to match Host Order.\n");
        
        uint32_t host_data = swap_endian(network_data);

        printf("Original (Network): 0x%.8x\n", network_data);
        printf("Converted (Host)  : 0x%.8x\n", host_data);

        uint8_t* ptr = (uint8_t*)&host_data;
        printf("Memory Dump: [%.2x] [%.2x] [%.2x] [%.2x] (Low Addr -> High Addr)\n",
                ptr[0], ptr[1], ptr[2], ptr[3]);
    }
    return 0;
}
