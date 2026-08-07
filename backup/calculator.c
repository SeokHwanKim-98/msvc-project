#include <stdio.h>

int main(void)
{

    int a = 0;
    int b = 0;
    char op = 'null';
    int result = 0;

    printf("My Best Calculator\n");
    printf("Put number and cal\n");
    scanf("%d %c %d", &a, &op, &b);

    // if ('/' == op)
    // {
    //     if (0 == b) 
    //     { 
    //         printf("can't divide by 0\n");
    //         result = 0;
    //     }
    //     else { result = a / b; }
    // }
    // else if ('*' == op)
    // {
    //     result = a * b;
    // }
    // else if ('+' == op)
    // {
    //     result = a + b;
    // }
    // else if ('-' == op)
    // {
    //     result = a - b;
    // }
    // else
    // {
    //     printf("뭔가 잘못된걸 넣으셨군요");
    // }
    
    switch (op)
    {
        case '/':
        if (0 == b) printf("Can't divine 0\n");
        else result = a/b;
        break;
        
        case '*':
        result = a * b;
        break;
        
        case '+':
        result = a + b;
        break;
        
        case '-':
        result = a - b;
        break;
    }
    
    printf("%d %c %d = %d", a, op, b, result);

    return 0;
}