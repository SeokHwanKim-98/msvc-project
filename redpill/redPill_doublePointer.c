// - **Day 10. 이중 포인터를 활용한 2차원 배열 동적 할당**
//     - **입력:** 행(row) 수, 열(col) 수
//     - **출력:** 연속된 메모리 공간을 갖는 2차원 배열 구조
//     - **제약조건:** `malloc` 호출 횟수를 최소화할것 (데이터 영역은 한 번에 할당).
//     - **실행결과:**
    
//         === Day 10: Dynamic 2D Array Allocation ===
    
//         Generated Matrix (3x4):
//          1  2  3  4
//          5  6  7  8
//          9 10 11 12
    
//         >> Memory successfully freed.

#include <stdio.h>
#include <stdlib.h>

    // **는 역참조를 두번하는거 
int **create_matrix(int rows, int cols) {
    // 행 포인터를 저장할 공간
    int **matrix = malloc(rows * sizeof(int *));

    // 실제 데이터를 저장할 공간
    int *data = malloc(rows * cols * sizeof(int));

    // 각 행 포인터가 연속된 데이터 영역을 가리키도록 설정
    for (int i = 0; i < rows; i++) {
        matrix[i] = data + i * cols;
    }

    // 1 ~ rows*cols 저장
    for (int i = 0; i < rows * cols; i++) {
        data[i] = i + 1;
    }

    return matrix;
}

void free_matrix(int **matrix) {
    // 실제 데이터의 시작 주소
    free(matrix[0]);

    // 행 포인터 배열
    free(matrix);
}

int main(void) {
    int rows = 3;
    int cols = 4;

    int **matrix = create_matrix(rows, cols);

    printf("Generated Matrix (%dx%d):\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    free_matrix(matrix);

    printf("\n>> Memory successfully freed.\n");

    return 0;
}
