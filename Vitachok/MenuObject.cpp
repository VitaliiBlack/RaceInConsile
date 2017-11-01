/// singleton layzy
/// facade
/// медиатор

#include "MenuObject.h"
#include "GameObject.h"

MenuObject::MenuObject() : mainRect_(
    Application::instance().getWidth()  * 0.3,
    Application::instance().getHeight() * 0.2,
    Application::instance().getHeight()  * 0.2,
    11
  )
{
  mItems_[0].set(
    mainRect_.getWidth()  * 0.3 + mainRect_.x,
    mainRect_.getHeight() * 0.3 + mainRect_.y,
    mainRect_.getWidth()  * 0.4,
    1
  );
  mItems_[1].set(
    mainRect_.getWidth()  * 0.3 + mainRect_.x,
    mainRect_.getHeight() * 0.6 + mainRect_.y,
    mainRect_.getWidth()  * 0.4,
    1
  );
  
  
} 

void MenuObject::onKeyDown(int key)
{
  switch (key)
  {
    case KEY_ARROW_UP:   choosenIndex_--;       break;
    case KEY_ARROW_DOWN: choosenIndex_++;       break;
    case KEY_ENTER: if (choosenIndex_ == 0)
                    {
                      message_ = MESSAGE_PLAY;
                      break;
                    }
                    if (choosenIndex_ == 1)
                    {
                      message_ = MESSAGE_EXIT;
                      break;
                    }
                    
    default:                                    break;
  }
  choosenIndex_ = range(0, choosenIndex_, 1);
}

void MenuObject::onDraw(Canvas & canvas)
{
  
    canvas.drawRect(mainRect_, '/', COLOR_DARKPURPLE, COLOR_DARKRED);
    canvas.clear(COLOR_RED, mItems_[choosenIndex_]);
   
    canvas.drawText(mItems_[0].x, mItems_[0].y, "PLAY", COLOR_YELLOW, COLOR_TRANSPARENT);
    canvas.drawText(mItems_[1].x, mItems_[1].y, "EXIT", COLOR_YELLOW, COLOR_TRANSPARENT);
       
}

MenuObject::MessageMain MenuObject::getMessage()
{
  return message_;
}

void MenuObject::clearMessage()
{
  message_ = MESSAGE_NONE;
}

