#ifndef CAPTIVITY_HPP
#define CAPTIVITY_HPP

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <Ticker.h>

#define LOCK_PIN D2
#define UNLOCK_PIN D1
#define LED_PIN D5

#define LED_COUNT 12

#define LIFE_UPDATE_TIME 1


enum GameStates {
  IDLE = 0,
  RESET = 1,
  START = 2,
  END = 3
};

class Captivity {
 public:
  Captivity() :strip_(LED_COUNT, LED_PIN) {
    strip_.begin();
    strip_.show();
    strip_.setBrightness(255);
  };
  ~Captivity(){};

  void StartTimer();
  void StopTimer();
  bool TimerActive();


  static uint8_t current_state;
  static bool player1_state;
  static bool player2_state;

  static bool iris_switch_state;

  void Idle();
  void Reset();
  void Start();
  void End();

  static bool update_life;

  void FillLedStrip(uint8_t red, uint8_t green, uint8_t blue);

 private:
  Ticker life_timer_;
  Adafruit_NeoPixel strip_;


};

#endif  // CAPTIVITY_HPP