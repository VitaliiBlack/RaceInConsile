#include "Object.h"

bool Object::isEnabled() const
{
  return  isEnabled_;
}

bool Object::isVisible() const
{
  return isVisible_;
}

void Object::setEnabled(bool enabled)
{
  isEnabled_ = enabled;
}

void Object::setVisible(bool visible) 
{
  isVisible_ = visible;
}
