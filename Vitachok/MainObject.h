#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "Object.h"
#include "Application.h"
#include "MenuObject.h"
#include "GameObject.h"
#include "DuckObject.h"

class MainObject :
  public Object
{
public:
  MainObject();
  virtual void onKeyDown(int key);
  virtual void onUpdate();
private:
  MenuObject menu_;
  GameObject game_;
  DuckObject duck_;
};

#endif // MAINOBJECT_H