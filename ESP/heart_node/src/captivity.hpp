#ifndef CAPTIVITY_HPP
#define CAPTIVITY_HPP

#include <Arduino.h>
#include "heart.hpp"
#include <Adafruit_NeoPixel.h>

#define LED_PIN D1
 
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 9

enum GameStates {
  IDLE = 0,
  RESET = 1,
  START = 2,
  END = 3
};

class Captivity {
 public:
  Captivity():strip_(LED_COUNT, LED_PIN){
    strip_.begin();
    strip_.show();
    strip_.setBrightness(255);
  };
  ~Captivity(){};

  static uint8_t current_state;
  static bool player1_state;
  static bool player2_state;

  void Idle();
  void Reset();
  void Start();
  void End();

 private:
  Adafruit_NeoPixel strip_;
  Heart heart_;

  void PrintPlayerState();
};

#endif  // CAPTIVITY_HPP