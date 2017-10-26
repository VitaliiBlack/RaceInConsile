#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Object.h"
#include "Application.h"

class GameObject :
  public Object
{
  static const int barrierCount = 3;
  int roadDirectionIterator_ = 0;
  int roadDirection_ = 0; // 0 - left, 1 - right
  float pos_ = 0;
  float speed_ = 0.1;
  int score_ = 0;
  bool crush = false;
  
  bool speedUp = false;
  bool speedDown = false;
  bool toLeft = false;
  bool toRight = false;
  
  Rect *road_;
  Rect car_;
  Rect barriers_[barrierCount];
  COLOR barrierColors[barrierCount];
public:
  
  GameObject();
  ~GameObject();
  
  virtual void onUpdate();
  virtual void onKeyDown(int key);
  virtual void onKeyUp(int key);
  virtual void onDraw(Canvas &canvas);
};

#endif // GAMEOBJECT_H