#include "Display.hpp"
#include "Game.hpp"

Display::Display(Game& gameEngine) : game(gameEngine) {
  game.init();
}