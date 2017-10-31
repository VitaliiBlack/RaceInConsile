#ifndef COLLECTION_H
#define COLLECTION_H

#undef max
#undef min


// draw rectangle any size
class BaseDrawElement
{
  int width_ = 0;
  int height_ = 0;

public:
  int x = 0;
  int y = 0;

  BaseDrawElement();

  //rect position and size
  BaseDrawElement(int x, int y, int width, int height);
  int getRight();
  int getBottom();
  int getWidth();
  int getHeight();

  void setWidth(int width);
  void setHeight(int height);
  void set(int x, int y, int width, int height);
  BaseDrawElement intersectRect(BaseDrawElement rect);
  bool hasPoint(int x, int y);
  bool isIntersectRect(BaseDrawElement rect);
  bool isEmpty();
};

int max(int value1, int value2);
int min(int value1, int value2);
int range(int min, int value, int max);
float range(float min, float value, float max);
int random(int min, int max);

#endif // COLLECTION_H