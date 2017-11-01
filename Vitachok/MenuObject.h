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

  MenuObject();
  virtual void onKeyDown(int key);
  virtual void onDraw(Canvas &canvas);
  MessageMain getMessage();
  void clearMessage();

private:
  
  BaseDrawElement mainRect_;
  BaseDrawElement subMainRect_;
  BaseDrawElement mItems_[3];
  BaseDrawElement sItems_[2];
  int choosenIndex_ = 0;
  MessageMain message_ = MESSAGE_NONE;

  
};

#endif // MENUOBJECT_H