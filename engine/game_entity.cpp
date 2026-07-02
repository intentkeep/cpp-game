#include "engine/game_entity.hpp"

#include <algorithm>

namespace game {

GameEntity::GameEntity(int max_health)
    : health_(max_health), max_health_(max_health), alive_(true) {}

bool GameEntity::is_alive() const { return alive_; }

int GameEntity::health() const { return health_; }

void GameEntity::take_damage(int amount) {
  if (!alive_) {
    return;
  }
  health_ -= amount;
  if (health_ <= 0) {
    health_ = 0;
    alive_ = false;
  }
}

bool GameEntity::heal(int amount) {
  if (!alive_) {
    return false;
  }
  health_ = std::min(health_ + amount, max_health_);
  return true;
}

}  // namespace game
