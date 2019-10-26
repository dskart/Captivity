#ifndef CAPTIVITY_HPP
#define CAPTIVITY_HPP

#include <Arduino.h>
#include "heart.hpp"


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

  void Idle();
  void Reset();
  void Start();
  void End();

 private:
  Heart heart_;

  void PrintPlayerState();
};

#endif  // CAPTIVITY_HPP