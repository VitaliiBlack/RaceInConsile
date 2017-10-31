#include "Console.h"
#include "Utils.h"
#include <windows.h>
#include <tchar.h>
#include "Macros.h"

Console::Console()
{
  setFontSize(fontSize);
  resize(width_, height_);
}



Console::Console(int width, int height)
{
  
  setFontSize(fontSize);
  resize(width, height);
}

Console::Console(int width, int height, short fontSize)
{
  setFontSize(fontSize);
  resize(width, height);
}

int Console::getWidth() const
{
  return width_;
}

int Console::getHeight() const
{
  return height_;
}

void Console::setWidht(int widht)
{
  this->width_ = widht;
}

void Console::setHight(int hight)
{
  this->height_ = hight;
}

void Console::setFontSize(short fontSize)
{
  fontSize = range(MIN_CONSOLE_FONTSIZE, fontSize, MAX_CONSOLE_FONTSIZE);
  CONSOLE_FONT_INFOEX font = { 0 };
  font.cbSize = sizeof(font);
  font.dwFontSize.Y = fontSize;
  font.FontWeight = FW_NORMAL;
  TCHAR fontName[] = TEXT("Lucida Console");
  _tcscpy_s(font.FaceName, lstrlen(fontName) + 1, fontName);
  SetCurrentConsoleFontEx(hOut_, FALSE, &font);
  recalcSize(true);
}

short Console::getFontSize()
{
  CONSOLE_FONT_INFO font;
  GetCurrentConsoleFont(hOut_, FALSE, &font);
  return font.dwFontSize.Y;
}

void Console::resize(int width, int height)
{
  width   = range(MIN_CONSOLE_WIDTH, width, MAX_CONSOLE_WIDTH);
  height  = range(MIN_CONSOLE_HEIGHT, height, MAX_CONSOLE_HEIGHT);
  width_  = width;
  height_ = height;
  COORD bufferSize = { width, height };
  SMALL_RECT consoleSize = { 0, 0, width - 1, height - 1 };
  SetConsoleWindowInfo(hOut_, TRUE, &consoleSize);// Window Size 
  SetConsoleScreenBufferSize(hOut_, bufferSize);  // Buffer Size
  recalcSize(false);
}

void Console::recalcSize(bool noMove)
{
  RECT displayArea;
  RECT clientRect;
  RECT windowRect;
  CONSOLE_FONT_INFO font;

  GetCurrentConsoleFont(hOut_, FALSE, &font);
  SystemParametersInfo(SPI_GETWORKAREA, 0, &displayArea, 0);
  GetClientRect(hwnd_, &clientRect);
  GetWindowRect(hwnd_, &windowRect);




  SetWindowPos(
    hwnd_, 0,
    (noMove ? windowRect.left : displayArea.left),
    (noMove ? windowRect.top : displayArea.top),
    windowRect.right  - windowRect.left - clientRect.right  + font.dwFontSize.X * width_,
    windowRect.bottom - windowRect.top  - clientRect.bottom + font.dwFontSize.Y * height_,
    SWP_SHOWWINDOW
  );
}

void Console::draw(const CHAR_INFO* charInfo, int width, int height)
{
  SMALL_RECT drawableRect = { 0, 0, width, height };
  COORD      bufferSize   = { width, height };
  WriteConsoleOutputA(hOut_, charInfo, bufferSize, { 0, 0 }, &drawableRect);
}
