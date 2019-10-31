#ifndef HEART_HPP
#define HEART_HPP

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <Ticker.h>

#define LED_PIN_A D1
#define LED_PIN_B D2
#define LED_COUNT 19

#define LIFE_CONSTANT_DECREASE 10

const uint8_t life_meter_num_led = 9;
const uint8_t heart_num_led = 5;
const uint8_t artery_num_led = 5;

const uint8_t life_meter_led_start = 0;
const uint8_t heart_led_start = 9;
const uint8_t artery_led_start = 14;

void LifeTimerISR();

enum LifeSwitch {
  A = 0,
  B = 1
};

class Heart {
 public:
  Heart();
  ~Heart(){};

  void StartTimer();
  void StopTimer();
  bool TimerActive();

  static int32_t player_A_life;
  static int32_t player_B_life;
  static bool life_switch;
  static bool using_power;

  uint32_t power_use_start_time = 0;
  uint32_t power_use_display_max_time = 2000;

  bool player_A_state = 1;
  bool player_B_state = 1;

  void Reset();
  void FillAllLifeMeter_A(uint8_t red, uint8_t green, uint8_t blue);
  void FillAllLifeMeter_B(uint8_t red, uint8_t green, uint8_t blue);
  void FillLifeMeterUpToo_A(uint8_t num_led);
  void FillLifeMeterUpToo_B(uint8_t num_led);

  void UpdateLifeMeter_A();
  void UpdateLifeMeter_B();

  void FillAllHeart_A(uint8_t red, uint8_t green, uint8_t blue);
  void FillAllHeart_B(uint8_t red, uint8_t green, uint8_t blue);

  void FillAllArtery_A(uint8_t red, uint8_t green, uint8_t blue);
  void FillAllArtery_B(uint8_t red, uint8_t green, uint8_t blue);

 private:
  Ticker life_timer_;
  Adafruit_NeoPixel strip_A;
  Adafruit_NeoPixel strip_B;
};

#endif  // HEART_HPP