#include "captivity.hpp"

void UpdateLifeISR(){
  Captivity::update_life = 1;
  return;
}


void Captivity::Idle() {
  // Serial.println("----IDLE----");
  // PrintPlayerState();
  Captivity::update_life = 0;
  FillLedStrip(0,0,255);
  StopTimer();
  iris_switch_state = 0;

  return;
}

void Captivity::Reset() {
  // Serial.println("----RESET----");
  Captivity::update_life = 0;
  FillLedStrip(0, 255, 0);
  StopTimer();
  iris_switch_state = 0;

  return;
}

void Captivity::Start() {
  // Serial.println("----START----");

  if(Captivity::player2_state){
    if (iris_switch_state) {  // A
      if (!digitalRead(LOCK_PIN)) {
        if (!TimerActive()) {
          StartTimer();
        }
        FillLedStrip(255,0,0);
        iris_switch_state = 0;
      }
    } else {
      if (!digitalRead(UNLOCK_PIN)) {
        StopTimer();
        FillLedStrip(0,255,0);
        iris_switch_state = 1;
      }
    }
  }
  else if (!Captivity::player2_state){
    iris_switch_state = 1;
    FillLedStrip(0,255,0);
    StopTimer();
  }
  
  return;
}

void Captivity::End() {
  // Serial.println("----END----");
  Captivity::update_life = 0;
  FillLedStrip(255, 255, 255);
  StopTimer();
  iris_switch_state = 0;

  return;
}



void Captivity::StartTimer() {
  life_timer_.attach(LIFE_UPDATE_TIME, UpdateLifeISR);

  return;
}

void Captivity::StopTimer() {
  life_timer_.detach();
}

bool Captivity::TimerActive() {
  if (life_timer_.active()) {
    return 1;
  }

  return 0;
}


void Captivity::FillLedStrip(uint8_t red, uint8_t green, uint8_t blue){
  strip_.fill(0, 0, LED_COUNT);
  uint32_t color = strip_.Color(red, green, blue);
  strip_.fill(color, 0, LED_COUNT);
  strip_.show();

  return;
}
