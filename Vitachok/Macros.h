#ifndef MACROS_H
#define MACROS_H

#define HASFLAG(flags, flag) ((flags & flag) == flag)

#define COLOR_TRANSPARENT -1
#define COLOR_BLACK        0
#define COLOR_DARKBLUE     1
#define COLOR_DARKGREEN    2
#define COLOR_DARKCYAN     3
#define COLOR_DARKRED      4
#define COLOR_DARKPURPLE   5
#define COLOR_DARKYELLOW   6
#define COLOR_GRAY         7
#define COLOR_DARKGRAY     8
#define COLOR_BLUE         9
#define COLOR_GREEN        10
#define COLOR_CYAN         11
#define COLOR_RED          12
#define COLOR_PURPLE       13
#define COLOR_YELLOW       14
#define COLOR_WHITE        15

typedef int COLOR;
#define DEFAULT_CONSOLE_WIDTH 80
#define DEFAULT_CONSOLE_HEIGHT 60
#define DEFAULT_CONSOLE_FONTSIZE 12
#define MIN_CONSOLE_WIDTH 14
#define MIN_CONSOLE_HEIGHT 1
#define MIN_CONSOLE_FONTSIZE 5
#define MAX_CONSOLE_WIDTH 500
#define MAX_CONSOLE_HEIGHT 200
#define MAX_CONSOLE_FONTSIZE 40
#define KEY_COUNT 256
#define DEFAULT_APPLICATION_DELAY 30
#define BARIER_COUNT 3

#define KEY_ESC         27
#define KEY_ENTER       13
#define KEY_SPACE       32
#define KEY_ARROW_LEFT  37
#define KEY_ARROW_RIGHT 39
#define KEY_ARROW_UP    38
#define KEY_ARROW_DOWN  40

#endif // MACROS_H