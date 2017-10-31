#ifndef OBJECT_H
#define OBJECT_H

#include "Utils.h"
#include "Canvas.h"

class Object
{
public:
  
  virtual void onKeyDown(int key) {};
  virtual void onKeyUp(int key) {};
  virtual void onUpdate() {};
  virtual void onDraw(Canvas &canvas) {};
  virtual ~Object() {};
  bool isEnabled() const;
  bool isVisible() const;
  void setEnabled(bool);
  void setVisible(bool);

private:
  bool isEnabled_ = true;
  bool isVisible_ = true;
};

#endif // OBJECT_H
