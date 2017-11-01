#include "Application.h"
#include "Macros.h"
#include <ctime>
#include <algorithm>

//initialization in consrtuctor
Application::Application()
{
  console_.resize(DEFAULT_CONSOLE_WIDTH, DEFAULT_CONSOLE_HEIGHT);
  canvas_.resize(console_.getWidth(), console_.getWidth());
}

int Application::getWidth() const
{
  return console_.getWidth();
}

int Application::getHeight() const
{
  return console_.getHeight();
}

Application& Application::instance()
{
  static Application inst;
  return inst;
}

void Application::close()
{
  opened_ = false;
}

void Application::addObject(Object* object)
{
  if (object != nullptr)
  {
    objects_.push_back(object);
  }
}

void Application::removeObject(Object* object)
{
  if (object != nullptr)
  {
    objects_.erase(std::remove(objects_.begin(), objects_.end(), object), objects_.end());
  }
}

void Application::run()
{
  update();
  while (opened_)
  {
    DWORD millis = clock();
    checkKeyboard();
    update();
    millis = clock() - millis;
    if (millis < DEFAULT_APPLICATION_DELAY)
    {
      Sleep(DEFAULT_APPLICATION_DELAY - millis);
    }
  }
}

void Application::checkKeyboard()
{
  bool state = false;
  for (int key = 1; key < KEY_COUNT; key++)
  {
    state = HIWORD(GetKeyState(key));
    if (state)
    {
      if (!keyStates_[key])
      {
        notifyKeyDown(key);
      }
    }
    else if (keyStates_[key])
    {
      notifyKeyUp(key);
    }
    keyStates_[key] = state;
  }
}

void Application::update()
{
  
  canvas_.clear(COLOR_BLACK);
  for (Object* object : objects_)
  {
    if (object->isEnabled())
    {
      object->onUpdate();
    }
    if (object->isVisible())
    {
      object->onDraw(canvas_);
    }
  }
  canvas_.display(console_);
}

void Application::notifyKeyDown(int key)
{
  for (int i = 0; i < objects_.size(); i++)
  {
    if (objects_[i]->isEnabled())
    {
      objects_[i]->onKeyDown(key);
    }
  }
}

void Application::notifyKeyUp(int key)
{
  for (int i = 0; i < objects_.size(); i++)
  {
    if (objects_[i]->isEnabled())
    {
      objects_[i]->onKeyUp(key);
    }
  }
}
