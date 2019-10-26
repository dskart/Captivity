#include "heart.hpp"

void LifeTimerISR() {
  Serial.print("WHATUP");
  Heart::current_life -= 5;

  if (Heart::current_life <= 0) {
    Heart::current_life = 0;
  }

  return;
}

Heart::Heart() : strip_(LED_COUNT, LED_PIN) {
  strip_.begin();
  strip_.show();
  strip_.setBrightness(255);
}

void Heart::StartTimer() {
  life_timer_.attach(1, LifeTimerISR);

  return;
}

void Heart::StopTimer() {
  life_timer_.detach();
}

bool Heart::TimerActive() {
  if (life_timer_.active()) {
    return 1;
  }

  return 0;
}

void Heart::Reset() {
  Heart::current_life = 9000;
  return;
}

void Heart::FillFullDisplay(const uint8_t& red, const uint8_t& green, const uint8_t& blue) {
  strip_.clear();
  uint32_t color = strip_.Color(red, green, blue);
  strip_.fill(color);
  strip_.show();

  return;
}

void Heart::FillDisplayUpToo(const uint8_t& num_led) {
  strip_.clear();
  uint32_t color = strip_.Color(255, 0, 0);
  strip_.fill(color, 0, num_led);
  strip_.show();
}

void Heart::UpdateLifeDisplay() {
  if (Heart::current_life >= 8000) {
    FillDisplayUpToo(9);
  } else if (Heart::current_life >= 7000) {
    FillDisplayUpToo(8);
  } else if (Heart::current_life >= 6000) {
    FillDisplayUpToo(7);
  } else if (Heart::current_life >= 5000) {
    FillDisplayUpToo(6);
  } else if (Heart::current_life >= 4000) {
    FillDisplayUpToo(5);
  } else if (Heart::current_life >= 3000) {
    FillDisplayUpToo(4);
  } else if (Heart::current_life >= 2000) {
    FillDisplayUpToo(3);
  } else if (Heart::current_life >= 1000) {
    FillDisplayUpToo(2);
  } else if (Heart::current_life < 1000) {
    FillDisplayUpToo(1);
  } else {  // life is zero
    FillDisplayUpToo(0);
  }

  return;
}
