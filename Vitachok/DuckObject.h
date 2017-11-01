#ifndef DUCKOBJECT_H
#define DUCKOBJECT_H
#include "Object.h"


class DuckObject :
  public Object
{
public:
  DuckObject();
  ~DuckObject();

  
  void duckRunR(Canvas  &canvas);
  bool duckTime();
  
  void onUpdate() override;
  void onDraw(Canvas &canvas);
  
private:
  BaseDrawElement duckCrossingRoad_;

  bool isEnabled_ = true;
  bool isVisible_ = true;
  bool duckSteps = true;
  int duckSpeed_ = 0;
  float pos_ = 0;
  float speed_ = 0.5;
  

};

#endif //DUCKOBJECT_H
