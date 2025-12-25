#include <iostream>
#include <vector>

#include "Game.hpp"
#include "Stock.hpp"
#include "Player.hpp"

void clear_screen() {
  std::system("clear");
}

Game::Game () {
  this->chart = get_default_stocks();
}

void Game::init(int player_num, std::vector& players) {
  this->player_num = player_num;
  this->players = players.copy();
}

void Game::step() {
  for (auto& player : this->players) {
    clear_screen();
    player.show_menu(this->chart);
  }
}

void Game::run() {
  while (true) {
    this->step();
  }
}
