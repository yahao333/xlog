#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include "xlog.h"

static char logMsg[1024];
static xlog_level_t xlog_default_level_ = XLOG_VERBOSE;

void xlog_writex(xlog_level_t level,const char* format, va_list args)
{
    if(level <= xlog_default_level_){
        vsprintf(logMsg, format,  args);
        printf("%s", logMsg);
    }
}

void xlog_write(xlog_level_t level, const char* format, ...)
{
    va_list va;
    va_start(va, format);
    //xlog_writex(level, format, va);
    if(level <= xlog_default_level_){
        vsprintf(logMsg, format,  va);
        printf("%s", logMsg);
    }
    va_end(va);
}

void xlevel_set(xlog_level_t level)
{
    xlog_default_level_ = level;
}
