#include "MainObject.h"

MainObject::MainObject()
{
  menu_.setEnabled(false); 
  menu_.setVisible(false);
  game_.setEnabled(true);
  game_.setVisible(true);
  duck_.setEnabled(false);
  duck_.setVisible(false);
  Application::instance().addObject(&menu_);
  Application::instance().addObject(&game_);
  Application::instance().addObject(&duck_);

}



//button in game
void MainObject::onKeyDown(int key)
{
  switch (key)
  {
  case KEY_ESC:
    if(!menu_.isVisible())
    {
      menu_.setEnabled(true);
      menu_.setVisible(true);
      game_.setEnabled(false);
      game_.setVisible(false);
      menu_.clearMessage();
    }
    else
    {
      menu_.setEnabled(false);
      menu_.setVisible(false);
      game_.setEnabled(true);
      game_.setVisible(true);
      menu_.clearMessage();
    }
    break;
  case KEY_ENTER:
    if (game_.isVisible())
    {
      game_.setEnabled(!game_.isEnabled());
    }
    break;
  default: break;
  }
}

void MainObject::onUpdate()
{
  if(game_.getScore() >=1000  && game_.getScore() < 1001)
  {
    menu_.setEnabled(false);
    menu_.setVisible(false);
    game_.setEnabled(false);
    game_.setVisible(true);
    duck_.setEnabled(true);
    duck_.setVisible(true);
    if(!duck_.duckTime())
    {
      game_.setEnabled(true);
      game_.setVisible(true);
      duck_.setEnabled(false);
      duck_.setVisible(false);
    }
  }
  
  
  
  if (menu_.getMessage() == MenuObject::MESSAGE_PLAY)
  {
    menu_.setEnabled(false);
    menu_.setVisible(false);
    game_.setEnabled(true);
    game_.setVisible(true);
    menu_.clearMessage();
  }
  if (menu_.getMessage() == MenuObject::MESSAGE_EXIT)
  {
    Application::instance().close();
  }
 
  
}
