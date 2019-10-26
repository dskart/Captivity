#ifndef HEART_HPP
#define HEART_HPP

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <Ticker.h>

#define LED_PIN D1
#define LED_COUNT 9

void LifeTimerISR();

class Heart {
 public:
  Heart();
  ~Heart(){};

  void StartTimer();
  void StopTimer();
  bool TimerActive();
  static int32_t current_life;

  void Reset();
  void FillFullDisplay(const uint8_t& red, const uint8_t& green, const uint8_t& blue);
  void FillDisplayUpToo(const uint8_t& num_led);

  void UpdateLifeDisplay();

 private:
  Ticker life_timer_;
  Adafruit_NeoPixel strip_;
};

#endif  // HEART_HPP