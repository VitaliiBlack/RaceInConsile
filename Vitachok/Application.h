#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Console.h"
#include "Canvas.h"
#include "Object.h"
#include <list>


//main class, Facade pattern, 
class Application
{
public:

  static Application& instance();
  int getWidth() const;
  int getHeight() const;
  void close();
  void addObject(Object *object);
  void removeObject(Object *object);
  void run();
private:
  
  
  
  bool opened_ = true;
  Console console_;
  Canvas canvas_;
  bool keyStates_[KEY_COUNT] = { 0 };
  std::vector<Object*> objects_;
  void checkKeyboard();
  void update();
  void notifyKeyDown(int key);
  void notifyKeyUp(int key);
  void notifyDuckState();
  Application();

};

#endif // APPLICATION_H