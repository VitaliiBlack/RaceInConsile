#ifndef MENUOBJECT_H
#define MENUOBJECT_H

#include "Object.h"
#include "Application.h"

class MenuObject :
  public Object
{
public:
  enum MessageMain
  {
    MESSAGE_NONE,
    MESSAGE_PLAY,
    MESSAGE_EXIT,
  };

private:
  
  Rect mainRect_;
  Rect subMainRect_;
  Rect mItems_[3];
  Rect sItems_[2];
  int choosenIndex_ = 0;
  MessageMain message_ = MESSAGE_NONE;
public:
  MenuObject();
  
  virtual void onKeyDown(int key);
  virtual void onDraw(Canvas &canvas);
  MessageMain getMessage();
  void clearMessage();
};

#endif // MENUOBJECT_H