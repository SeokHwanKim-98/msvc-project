#include <stdio.h>

void input_nums(int* lotto);
void print_nums(int* lotto);

void input_nums(int *lotto)
{
    int num;
    int a;
    for (int i = 0; i<6; i++) {
        printf("%d번째 번호 입력 : ",i+1);
        scanf("%d", &num);
        a = 0;
        
        for (int j = 0; j<i; j++) {
            if(num == lotto[j]) {
                a=1;
                break;
            }
        }
        if (!a) { lotto[i] = num; }
        else {
            printf("같은 번호가 있습니다.\n");
            i--;
        }
    }
}

void print_nums(int *lotto)
{
    // for (int i=0; i<6; i++) { printf("%d번째 번호는 : %d\n",i+1,lotto[i]); }

    int num;
    int a;
    int count = 0;
    for (int i = 0; i<6; i++) {
        printf("번호 입력 : ",i+1);
        scanf("%d", &num);
        if (num == 0) { 
            i--; 
            printf("0은 입력되지않습니다.");
            continue; 
        }
        a = 0;
        
        for (int j = 0; j<6; j++) {
            if(num == lotto[j]) {
                a=1;
                break;
            }
        }
        if (!a) { printf("입력한 번호는 당첨번호가 아닙니다.\n"); }
        else {
            printf("입력한 번호는 당첨번호입니다.\n");
            count += 1;
            lotto[i] = 0;
        }

        switch(count) {
            case 1:
                printf("꽝");
                break;
            case 2:
                printf("꽝");
                break;
            case 3:
                printf("꽝");
                break;
            case 4:
                printf("3등");
                break;
            case 5:
                printf("2등");
                break;
            case 6:
                printf("1등");
                break;
        }
        
    }

}



int main(int argc, char const *argv[])
{
    int lotto_nums[6];
    input_nums(lotto_nums);
    print_nums(lotto_nums);

    return 0;
}

