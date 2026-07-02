#pragma once

namespace game {

constexpr int DEFAULT_MAX_HEALTH = 100;

class GameEntity {
  int health_;
  const int max_health_;
  bool alive_;

public:
  explicit GameEntity(int max_health);

  bool is_alive() const;
  int health() const;

  void take_damage(int amount);
  bool heal(int amount);
};

}  // namespace game
