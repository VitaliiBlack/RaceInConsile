#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Object.h"
#include "Application.h"

class GameObject :
  public Object
{
  
  
public:
  
  GameObject();
  ~GameObject();
  
  virtual void onUpdate();
  virtual void onKeyDown(int key);
  virtual void onKeyUp(int key);
  int getScore();
  void CanvasDrawPlayerCar(Canvas& canvas);
  void roadCreation(Canvas& canvas);
  void barriersCreation(Canvas& canvas);
  void bushDrawing(Canvas& canvas);
  virtual void onDraw(Canvas &canvas);

private:

  int roadDirectionIterator_ = 0;
  int roadDirection_ = 0;
  float pos_ = 0;
  float speed_ = 0.1;
  int score_ = 0;
  bool crush = false;

  bool speedUp = false;
  bool speedDown = false;
  bool toLeft = false;
  bool toRight = false;

  BaseDrawElement *road_;
  BaseDrawElement car_;
  //BaseDrawElement duckCrossingRoad_;
  BaseDrawElement barriers_[BARIER_COUNT];
  BaseDrawElement bush_;
  COLOR barrierColors[BARIER_COUNT];
};

#endif // GAMEOBJECT_H