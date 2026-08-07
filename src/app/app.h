// 헤더 가드문 여러곳에서 include 하고 컴파일 할때 한번만 동작하게함
// #pragma once //  -> 높은버전의 C일때 사용
#ifndef __APP_H__ // 낮은버전에선 이렇게
#define __APP_H__


void appInit(void);
void appMain(void);


#endif