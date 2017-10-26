#include "Application.h"
#include "MainObject.h"
#include <iostream>

int main()
{
  MainObject main;
  Application::instance().addObject(&main);
  Application::instance().run();
}