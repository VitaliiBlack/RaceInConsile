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
  virtual void setSpeed(int speed);
  virtual int  getSpeed();

  virtual ~Object() {};
  virtual bool isEnabled() const;
  virtual bool isVisible() const;
  void setEnabled(bool);
  void setVisible(bool);
 

private:
  int speed_ = 0;
  bool isEnabled_ = true;
  bool isVisible_ = true;
};

#endif // OBJECT_H
