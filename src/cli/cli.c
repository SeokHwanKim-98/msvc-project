#include "cli.h"
#include <Windows.h>

static HANDLE hStdout = INVALID_HANDLE_VALUE;
static char cli_line_buf[CLI_LINE_BUF_MAX];
static uint16_t cli_line_idx = 0;
static uint16_t cli_cursor = 0;


static cli_input_state_t input_state = CLI_STATE_NORMAL;
static cli_callback_t ctrl_c_handler = NULL;

void cliInit(void)
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    cli_line_idx = 0;
    cli_cursor = 0;
    ctrl_c_handler = NULL;

    cliPrintf("\r\n=============================================\r\n");
    cliPrintf("    MSVC Windows Console CLI Terminal V0.1\r\n");

    cliPrintf("CLI> ");
}

void cliMain(void)
{
}

void cliPrintf(char *fmt, ...)
{
    char buf[256];
    va_list args;
    int len;
    va_start(args, fmt);
    len = vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    if(len > 0 ) {
        DWORD written = 0;
        WriteConsoleA(hStdout, (uint8_t*)buf, (DWORD)len, &written, NULL);
        
    }
}

void cliAdd(char *cmd_str, void (*cmd_func)(uint8_t argc, char *argv[]))
{
}

void cliSetCtrlHandler(cli_callback_t handler)
{
}
