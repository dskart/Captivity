#ifndef CAPTIVITY_HPP
#define CAPTIVITY_HPP

#include <Arduino.h>

#define PLAYER_A_PIN D1
#define PLAYER_B_PIN D2


enum GameStates {
  IDLE = 0,
  RESET = 1,
  START = 2,
  END = 3
};

class Captivity {
 public:
  Captivity(){};
  ~Captivity(){};

  static uint8_t current_state;
  static bool player1_state;
  static bool player2_state;

  static bool life_switch_state;

  void Idle();
  void Reset();
  void Start();
  void End();

 private:


};

#endif  // CAPTIVITY_HPP