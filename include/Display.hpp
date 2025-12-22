#pragma once

#include "Game.hpp"

class Display {
  private:
    Game game;

  public:
    Display(Game game);
    void run();
}
