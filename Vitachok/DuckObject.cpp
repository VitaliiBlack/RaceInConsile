#include "DuckObject.h"
#include "Application.h"
#include "GameObject.h"
#include "MainObject.h"


DuckObject::DuckObject()
{
  duckCrossingRoad_ = BaseDrawElement(Application::instance().getWidth()*0.1, Application::instance().getHeight() / 2, 4, 5);

}


DuckObject::~DuckObject()
{}




void DuckObject::onUpdate()
{
  
  float prev = pos_;
  pos_ += speed_;
  int deltaY = int(pos_) - int(prev);
  
    duckCrossingRoad_.x += deltaY;
    duckCrossingRoad_.y = Application::instance().getHeight() / 2;
  
  pos_ = pos_ - int(pos_);
  if(duckCrossingRoad_.x > 70 )
  {
    DuckObject::setEnabled(false);
    DuckObject::setVisible(false);
    
  }
  
}

void DuckObject::onDraw(Canvas& canvas)
{
  
    duckRunR(canvas);
  
}

void DuckObject::duckRunR(Canvas &canvas)
{
  canvas.clear(COLOR_YELLOW, BaseDrawElement(duckCrossingRoad_.x, duckCrossingRoad_.y, 6, 11));
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x - 2, duckCrossingRoad_.y + 7, 2, 2), '|', COLOR_YELLOW, COLOR_YELLOW);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x - 1, duckCrossingRoad_.y + 5, 1, 2), '|', COLOR_YELLOW, COLOR_YELLOW);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x - 1, duckCrossingRoad_.y + 11, 2, 1), '|', COLOR_RED, COLOR_RED);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 4, duckCrossingRoad_.y + 11, 2, 1), '|', COLOR_RED, COLOR_RED);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 6, duckCrossingRoad_.y + 7, 2, 2), '|', COLOR_YELLOW, COLOR_YELLOW);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 6, duckCrossingRoad_.y + 6, 1, 1), '|', COLOR_YELLOW, COLOR_YELLOW);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 2, duckCrossingRoad_.y + 2, 8, 2), '|', COLOR_RED, COLOR_RED);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 2, duckCrossingRoad_.y + 2, 8, 2), '|', COLOR_RED, COLOR_RED);
  if(duckCrossingRoad_.x%10 >= 5)canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x - 1, duckCrossingRoad_.y + 11, 2, 1), 178, COLOR_BLACK, COLOR_RED);
  else canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 4, duckCrossingRoad_.y + 11, 2, 1), 178, COLOR_BLACK, COLOR_RED);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x, duckCrossingRoad_.y + 1, 1, 1), '|', COLOR_WHITE, COLOR_WHITE);
  canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x + 4, duckCrossingRoad_.y + 1, 1, 1), '|', COLOR_WHITE, COLOR_WHITE);
  if(duckCrossingRoad_.x % 10 >= 5)canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x - 2, duckCrossingRoad_.y + 7, 3, 1), '#', COLOR_DARKYELLOW, COLOR_YELLOW);
  else canvas.drawRect(BaseDrawElement(duckCrossingRoad_.x - 2, duckCrossingRoad_.y + 8, 3, 1), '#', COLOR_DARKYELLOW, COLOR_YELLOW);
}

bool DuckObject::duckTime()
{

  for(int i = getSpeed(); i>=0; i--)
  {
    setSpeed(i);
    
  }
  return isEnabled();
}


