// - **Day 7. Checksum 계산 (XOR 방식)**
//     - **입력:** 바이트 배열 `[0x01, 0x02, 0x03, 0x04]`, 길이
//     - **출력:** XOR 누적 체크섬 값
//     - **제약조건:** 포인터 연산 사용.
//     - **실행결과:**
    
//     === Day 7: XOR Checksum Calculation ===
    
//     [TX] Sending Packet...
//          Data: 0x01 0x04 0x10 0x20 0x30 0x40 
//          Calculated Checksum: 0x04
    
//     [RX] Receiving Normal Packet...
//          >> Verification SUCCESS (Result: 0x00)
    
//     [RX] Receiving Corrupted Packet (Noise injected)...
//          Corrupted Data: 0x01 0x04 0xEF 0x20 0x30 0x40 0x04 
//          >> Verification FAIL (Result: 0xFF)
//          >> Error detected! Discarding packet.
    
#include <stdio.h>
#include <stdint.h>

uint8_t xor_checksum(uint8_t *data, int length)
{
    uint8_t checksum = 0;

    for (int i = 0; i < length; i++)
    {
        checksum ^= *(data + i);
    }

    return checksum;
}

int main(void)
{
    uint8_t data[] = {0x01, 0x04, 0x10, 0x20, 0x30, 0x40};
    uint8_t error_data[] = {0x01, 0x04, 0xEF, 0x20, 0x30, 0x40, 0x04};
    int length = sizeof(data) / sizeof(data[0]);
    int e_length = sizeof(error_data) / sizeof(error_data[0]);

    uint8_t result1 = xor_checksum(data, length);
    uint8_t result2 = xor_checksum(error_data, length);

    printf("Checksum : 0x%02X\n", result1);
    printf("Checksum : 0x%02X\n", result2);

    return 0;
}