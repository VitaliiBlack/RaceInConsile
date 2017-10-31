#include "Utils.h"
#include <cstdlib>


BaseDrawElement::BaseDrawElement() {}
BaseDrawElement::BaseDrawElement(int x, int y, int width, int height)
{
  set(x, y, width, height);
}
int BaseDrawElement::getRight()
{
  return x + width_;
}
int BaseDrawElement::getBottom()
{
  return y + height_;
}
int BaseDrawElement::getWidth()
{
  return width_;
}
int BaseDrawElement::getHeight()
{
  return height_;
}
void BaseDrawElement::setWidth(int width)
{
  width_ = max(0, width);
}
void BaseDrawElement::setHeight(int height)
{
  height_ = max(0, height);
}
void BaseDrawElement::set(int x, int y, int width, int height)
{
  this->x = x;
  this->y = y;
  setWidth(width);
  setHeight(height);
}
BaseDrawElement BaseDrawElement::intersectRect(BaseDrawElement rect)
{
  BaseDrawElement r;
  r.x = max(x, rect.x);
  r.y = max(y, rect.y);
  r.setWidth( min(getRight(),  rect.getRight())  - r.x);
  r.setHeight(min(getBottom(), rect.getBottom()) - r.y);
  return r;
}
bool BaseDrawElement::hasPoint(int x, int y)
{
  return
    x >= this->x && x < getRight() &&
    y >= this->y && y < getBottom();
}

bool BaseDrawElement::isIntersectRect(BaseDrawElement rect)
{
  rect = intersectRect(rect);
  return rect.width_ && rect.height_;
}

bool BaseDrawElement::isEmpty()
{
  return !(width_ | height_);
}

int max(int value1, int value2)
{
  return value1 > value2 ? value1 : value2;
}

int min(int value1, int value2)
{
  return value1 < value2 ? value1 : value2;
}

int range(int min, int value, int max)
{
  return value < min ? min : value > max ? max : value;
}

float range(float min, float value, float max)
{
  return value < min ? min : value > max ? max : value;
}

int random(int min, int max)
{
  return rand() % (max - min + 1) + min;
}
