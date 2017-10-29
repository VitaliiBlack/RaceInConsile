#include "GameObject.h"


//create new objects & setup it

GameObject::GameObject()
{
  road_ = new Rect[Application::instance().height];
  //generate road mass in hight of screen of game
  for (int i = 0; i < Application::instance().height; i++)
  {
    road_[i].set(
      Application::instance().width * 0.25, i,
      Application::instance().width * 0.5,  1
    );
  }

  //creation car
  car_ = Rect(Application::instance().width * 0.5, Application::instance().height - 6, 4, 5);

  //creation mass of bariers
  barriers_[0] = Rect(random(road_[0].x, road_[0].getRight()),
                      random(-Application::instance().height * 0.7, -3), 4, 2);
  barriers_[1] = Rect(random(road_[0].x, road_[0].getRight()),
                      random(-Application::instance().height * 0.7, -3), 4, 2);
  barriers_[2] = Rect(random(road_[0].x, road_[0].getRight()),
                      random(-Application::instance().height * 0.7, -3), 6, 3);

  //random set colors
  for (int i = 0; i < barrierCount; i++)
  {
    barrierColors[i] = random(COLOR_BLUE, COLOR_YELLOW);
  }
}



//Destructor (of course)
GameObject::~GameObject()
{
  delete[] road_;
}




//Update function
void GameObject::onUpdate()
{
  //control ride left, right
  if (toLeft)
  {
    car_.x -= 2;
  }
  if (toRight)
  {
    car_.x += 2;
  }

  //control speed
  if (speedUp)
  {
    speed_ += 0.1;
  }
  if (speedDown)
  {
    speed_ -= 0.15;
  }
  speed_ = range(0.1, speed_, 5.0);

  float prev = pos_;
  pos_ += speed_;


  int deltaY = int(pos_) - int(prev);

  for (int repeat = 0; repeat < deltaY; repeat++)
  {
    roadDirectionIterator_--;
    if (roadDirectionIterator_ < 0)
    {
      roadDirectionIterator_ = random(10, 100);
      roadDirection_ = roadDirection_ == 1 ? 0 : 1;
    }
    for (int i = Application::instance().height - 1; i > 0; i--)
    {
      road_[i].set(road_[i - 1].x, i, road_[i - 1].getWidth(), 1);
    }
    int x = road_[0].x + random(roadDirection_ ? -1 : 0, roadDirection_ ? 0 : 1);
    road_[0].x = range(Application::instance().width * 0.05, x, Application::instance().width * 0.45);
  }



  for (int i = 0; i < barrierCount; i++)
  {
    int y = barriers_[i].y + deltaY;
    if (y >= Application::instance().height)
    {
      barrierColors[i] = random(COLOR_BLUE, COLOR_YELLOW);
      y = random(-20, -3);
      int x = road_[0].getWidth() / 2 + road_[0].x + random(-road_[0].getWidth() * 0.4, road_[0].getWidth() * 0.3);
      barriers_[i].x = x;
    }
    barriers_[i].y = y;
  }
  score_ += deltaY;

  pos_ = pos_ - int(pos_);



  //Collision calculate
  for (int i = 0; i < Application::instance().height; i++)
  {
    if (car_.isIntersectRect(Rect(-1000, i, road_[i].x + 1000, 1)))
    {
      car_.x++;
    }
    if (car_.isIntersectRect(Rect(road_[i].getRight(), i, 1000, 1)))
    {
      car_.x--;
    }
  }
  for (int i = 0; i < barrierCount; i++)
  {
    if (car_.isIntersectRect(barriers_[i]))
    {
      ///
     
      crush = true;
      
      //Application::instance().close();
    }
  }
}

//key handler press
void GameObject::onKeyDown(int key)
{
  switch (key)
  {
  case KEY_ARROW_UP:    speedUp   = true; break;
  case KEY_ARROW_DOWN:  speedDown = true; break;
  case KEY_ARROW_LEFT:  toLeft    = true; break;
  case KEY_ARROW_RIGHT: toRight   = true; break;
  default:                                break;
  }
}

//key handler depress 8)
void GameObject::onKeyUp(int key)
{
  switch (key)
  {
  case KEY_ARROW_UP:    speedUp    = false; break;
  case KEY_ARROW_DOWN:  speedDown  = false; break;
  case KEY_ARROW_LEFT:  toLeft     = false; break;
  case KEY_ARROW_RIGHT: toRight    = false; break;
  default:                                  break;
  }
}

void GameObject::onDraw(Canvas & canvas)
{
  //field
  canvas.clear(COLOR_DARKGREEN);
  //road
  for (int i = 0; i < Application::instance().height; i++)
  {
    canvas.clear(COLOR_GRAY, road_[i]);
    canvas.drawCell(road_[i].x, road_[i].y, ' ', COLOR_GRAY, COLOR_WHITE);
    canvas.drawCell(road_[i].getRight() - 1, road_[i].y, ' ', COLOR_GRAY, COLOR_WHITE);
  }
  //barrier
  for (int i = 0; i < barrierCount; i++)
  {
    canvas.clear(barrierColors[i], barriers_[i]);
  }
  //car
  canvas.clear(COLOR_RED - 8, car_);
  canvas.clear(COLOR_RED, Rect(car_.x, car_.y + 2, 4, 2));
  canvas.drawRect(Rect(car_.x + 1, car_.y, 2, 2), '|', COLOR_WHITE, COLOR_TRANSPARENT);
  canvas.drawCell(car_.x - 1, car_.y + 1, ' ', COLOR_BLACK, COLOR_BLACK);
  canvas.drawCell(car_.getRight(), car_.y + 1, ' ', COLOR_BLACK, COLOR_BLACK);
  canvas.drawCell(car_.x - 1, car_.y + 4, ' ', COLOR_BLACK, COLOR_BLACK);
  canvas.drawCell(car_.getRight(), car_.y + 4, ' ', COLOR_BLACK, COLOR_BLACK);
  //text
  canvas.drawText(Application::instance().width - 17, Application::instance().height - 3, "SCORE:" + std::to_string(score_), COLOR_YELLOW, COLOR_BLACK);
  canvas.drawText(10, Application::instance().height - 3, "SPEED:" + std::to_string(int(speed_ * 10)), COLOR_YELLOW, COLOR_BLACK);

  if (!isEnabled)
  {

    canvas.drawText(Application::instance().width / 2 - 5, Application::instance().height/2, "PAUSED", COLOR_RED, COLOR_BLACK);
  }
  if (crush)
  {
    Rect rect;

    rect.set(0, 0, Application::instance().width, Application::instance().height);
    canvas.drawRect(rect, '/', COLOR_RED, COLOR_RED);
    canvas.drawText(Application::instance().width / 2 - 5, Application::instance().height / 2, "Game over", COLOR_BLUE, COLOR_YELLOW);

    
  
    
  }
}
