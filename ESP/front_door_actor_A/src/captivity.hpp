#ifndef CAPTIVITY_HPP
#define CAPTIVITY_HPP

#include <Arduino.h>

#define RED_LED D0
#define YELLOW_LED D1
#define GREEN_LED D2

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

  static uint8_t front_door_actor_state;

  void Idle();
  void Reset();
  void Start();
  void End();

 private:
  void DisplayLEDs(const bool &red_led, const bool &yellow_led, const bool &green_led);

};

#endif  // CAPTIVITY_HPP