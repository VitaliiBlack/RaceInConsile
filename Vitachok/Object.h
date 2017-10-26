#ifndef OBJECT_H
#define OBJECT_H

#include "Utils.h"
#include "Canvas.h"

class Object
{
public:
  bool isEnabled = true;
  bool isVisible = true;
  //COLOR roadColor = COLOR_GRAY;
  virtual void onKeyDown(int key) {};
  virtual void onKeyUp(int key) {};
  virtual void onUpdate() {};
  virtual void onDraw(Canvas &canvas) {};
  virtual ~Object() {};
};

#endif // OBJECT_H
