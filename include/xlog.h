#ifndef _XLOG_H_
#define _XLOG_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * @brief log level
 */
typedef enum{
    XLOG_NONE = 0,  // No log output
    XLOG_ERROR,
    XLOG_WARN,
    XLOG_INFO,
    XLOG_DEBUG,
    XLOG_VERBOSE
}xlog_level_t;

void xlevel_set(xlog_level_t level);

#if 1 //CONFIG_LOG_COLORS
#define LOG_COLOR_BLACK   "30"
#define LOG_COLOR_RED     "31"
#define LOG_COLOR_GREEN   "32"
#define LOG_COLOR_BROWN   "33"
#define LOG_COLOR_BLUE    "34"
#define LOG_COLOR_PURPLE  "35"
#define LOG_COLOR_CYAN    "36"
#define LOG_COLOR(COLOR)  "\033[0;" COLOR "m"
#define LOG_BOLD(COLOR)   "\033[1;" COLOR "m"
#define LOG_RESET_COLOR   "\033[0m"
#define LOG_COLOR_E       LOG_COLOR(LOG_COLOR_RED)
#define LOG_COLOR_W       LOG_COLOR(LOG_COLOR_BROWN)
#define LOG_COLOR_I       LOG_COLOR(LOG_COLOR_GREEN)
#define LOG_COLOR_D
#define LOG_COLOR_V
#else
#define LOG_COLOR_E
#define LOG_COLOR_W
#define LOG_COLOR_I
#define LOG_COLOR_D
#define LOG_COLOR_V
#define LOG_RESET_COLOR
#endif

#define LOG_FORMAT(letter, format)  LOG_COLOR_ ## letter #letter " : " format LOG_RESET_COLOR "\n"

#define LOGE( format, ... )        XLOG_LEVEL(XLOG_ERROR,   format, ##__VA_ARGS__)
#define LOGW( format, ... )        XLOG_LEVEL(XLOG_WARN,    format, ##__VA_ARGS__)
#define LOGI( format, ... )        XLOG_LEVEL(XLOG_INFO,    format, ##__VA_ARGS__)
#define LOGD( format, ... )        XLOG_LEVEL(XLOG_DEBUG,   format, ##__VA_ARGS__)
#define LOGV( format, ... )        XLOG_LEVEL(XLOG_VERBOSE, format, ##__VA_ARGS__)

#define XLOG_LEVEL(level, format, ...) do{ \
    if (XLOG_ERROR == level) { xlog_write( XLOG_ERROR, LOG_FORMAT(E, format),  ##__VA_ARGS__); } \
    else if (XLOG_WARN == level) { xlog_write( XLOG_WARN,    LOG_FORMAT(W, format), ##__VA_ARGS__); } \
    else if (XLOG_DEBUG == level) { xlog_write( XLOG_DEBUG,  LOG_FORMAT(D, format),  ##__VA_ARGS__); } \
    else if (XLOG_INFO == level) { xlog_write( XLOG_INFO,      LOG_FORMAT(I, format), ##__VA_ARGS__); } \
    else if (XLOG_VERBOSE == level) { xlog_write( XLOG_VERBOSE,       LOG_FORMAT(V, format), ##__VA_ARGS__); } \
    }while(0)

void xlog_write(xlog_level_t level, const char* format, ...);

#endif
