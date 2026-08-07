#include "uart_win.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>


static HANDLE hStdout = INVALID_HANDLE_VALUE;
static HANDLE hStdin = INVALID_HANDLE_VALUE;


bool uartInit(void)
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hStdin = GetStdHandle(STD_INPUT_HANDLE);

    if (hStdout != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;
        GetConsoleMode(hStdout, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT;
        SetConsoleMode(hStdout, mode);
    }

    return true;
}

int uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{

    DWORD written = 0;
    if (hStdout != INVALID_HANDLE_VALUE)
    {
        WriteConsoleA(hStdout, p_data, (DWORD)length, &written, NULL);
    }
    else {
        fwrite(p_data,1,length,stdout);
        fflush(stdout);
        written = (DWORD)length;
    }
    
    return (int)written;
}

bool uartReadBlock(uint8_t ch, uint8_t *p_data, uint32_t timeout)
{
    
    return false;
}
