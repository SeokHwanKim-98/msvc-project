#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void swap(float* pa, float* pb, float* pc)    // 매개변수로 포인터 선언
{
    float temp = 0;                  // 교환을 위한 임시 변수

    if (*pa > *pb) { // a가 b보다 크면 a와 b의 위치 변경
        temp = *pa;
        *pa = *pb;
        *pb = temp;
    }

    if (*pb > *pc) { // 위의 if를 넘어왔으니 a보다 b가 크니까 b와 c를 비교
        temp = *pb;
        *pb = *pc;
        *pc = temp;
    }

    if (*pa > *pb) { // 첫 if에서 넘어온 작은 수 a와 두번째 if에서 넘어온 작은수 b를 비교
        temp = *pa;
        *pa = *pb;
        *pb = temp;
    }
}


int main(int argc, char const *argv[])
{
    float a,b,c;
    // double a = 2.7, b = 1.5, c = 3.4;        // 변수 선언과 초기화
    printf("숫자 3개 입력 : ");
    scanf("%f %f %f",&a, &b, &c);
    swap(&a, &b, &c);              // a, b의 주소를 인수로 주고 함수 호출
    printf("a: %.2f, b : %.2f, c : %.2f\n", a, b, c);   // 변수 a, b 출력

    return 0;
}