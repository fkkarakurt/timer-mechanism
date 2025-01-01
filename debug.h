// debug.h
#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>

#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED_BOLD "\033[1;31m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_YELLOW "\033[1;33m"

typedef enum
{
    LOG_LEVEL_ERROR,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO
} LogLevel;

static const char *log_level_strings[] = {
    "error",
    "debug",
    "info"};

static const char *log_level_colors[] = {
    COLOR_RED_BOLD,
    COLOR_MAGENTA,
    COLOR_YELLOW};

static inline void log_message(LogLevel level, const char *function, const char *file, int line, const char *format, ...)
{
    va_list args;
    fprintf(stderr, "%s%s:%s ", log_level_colors[level], log_level_strings[level], COLOR_DEFAULT);
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, " %s(%s %s:%d)%s\n", log_level_colors[level], function, file, line, COLOR_DEFAULT);
    fflush(stderr);
}

// Makrolar
#define errorf(format, ...) log_message(LOG_LEVEL_ERROR, __FUNCTION__, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define debugf(format, ...) log_message(LOG_LEVEL_DEBUG, __FUNCTION__, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define infof(format, ...) log_message(LOG_LEVEL_INFO, __FUNCTION__, __FILE__, __LINE__, format, ##__VA_ARGS__)

#endif // DEBUG_H
