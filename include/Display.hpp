#pragma once

#include "Game.hpp"

class Display {
  private:
    Game& game;

  public:
    Display(Game& gameEngine);
    void run();
};
