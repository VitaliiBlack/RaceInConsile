#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Console.h"
#include "Canvas.h"
#include "Object.h"


//main class, Facade pattern, 
class Application
{

  //delay timer time
  static const int delay = 30;

  // input keys (all keys)
  static const int keyCount = 256;
  // is game opened?
  bool opened_ = true;
  
  //Console class declaretion
  Console console_;

  //Canvas class declaretion
  Canvas canvas_;

  //counter of keyboard actions
  bool keyStates_[keyCount] = { 0 };

  //vector of objects pointers 
  std::vector<Object*> objects_;
  
  //Keybofrd key check press 
  void checkKeyboard();

  //rewrite objects, on canvas 
  void update();

  Application();
public:
  
  const int width = 0;
  const int height = 0;

  //return reference of private class, creating object of application
  static Application& instance();

  //stop while cycle in run() method
  void close();

  //addition object(CAR, Road, Obstacles)
  void addObject(Object *object);

  //delete Objects.
  void removeObject(Object *object);

  //star program, update objects, in while cycle checing keyboard & set delay.
  void run();

};

#endif // APPLICATION_H