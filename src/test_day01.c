// # [비트 연산과 데이터 표현 (Bitwise & Data)]

// - **Day 1. 특정 비트 제어 매크로 구현**
//     - **입력:** 32비트 정수 `0x12345678`, 조작할 비트 위치(3), 
//                              동작(SET/CLEAR/TOGGLE)
//     - **출력:** 조작된 16진수 값
//     - **제약조건:** `<stdint.h>` 사용, 함수가 아닌 매크로로 구현할 것.
//     - **실행결과:** `SET 3rd bit of 0x... -> 0x...`
        
//         ```c
//         === Day 1: Bitwise Macro Test ===
//         [Init]   Hex: 0x12345678 | Bin: 0001 0010 0011 0100 0101 0110 0111 1000 
        
//         [SET]    Target: Bit 0
//         Result   Hex: 0x12345679 | Bin: 0001 0010 0011 0100 0101 0110 0111 1001 
        
//         [CLEAR]  Target: Bit 4
//         Result   Hex: 0x12345669 | Bin: 0001 0010 0011 0100 0101 0110 0110 1001 
        
//         [TOGGLE] Target: Bit 3
//         Result   Hex: 0x12345661 | Bin: 0001 0010 0011 0100 0101 0110 0110 0001 
        
//         [CHECK]  Bit 3 is currently: 0
//         ```

