#include "captivity.hpp"


void Captivity::Idle() {
  Serial.println("----IDLE----");
  PrintPlayerState();

  heart_.StopTimer();


  strip_.clear();
  uint32_t color = strip_.Color(0, 255, 0);
  strip_.fill(color);
  strip_.show();

  return;
}

void Captivity::Reset() {
  Serial.println("----RESET----");
  PrintPlayerState();

  heart_.StopTimer();
  Heart::current_life = 1000;
  Serial.print("LIFE FORCE = ");
  Serial.println(Heart::current_life);

  strip_.clear();
  uint32_t color = strip_.Color(0, 0, 0);
  strip_.fill(color);
  strip_.show();

  return;
}

void Captivity::Start() {
  Serial.println("----START----");
  PrintPlayerState();

  if (!heart_.TimerActive()){
    heart_.StartTimer();
  }
  Serial.print("LIFE FORCE = ");
  Serial.println(Heart::current_life);

  if (Heart::current_life >= 900){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color,0,9);
    strip_.show();
  }
  else if (Heart::current_life >= 800){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 8);
    strip_.show();
  }
  else if (Heart::current_life >= 700){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 7);
    strip_.show();
  }
  else if (Heart::current_life >= 600){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 6);
    strip_.show();
  }
  else if (Heart::current_life >= 500){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 5);
    strip_.show();
  }
  else if (Heart::current_life >= 400){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 4);
    strip_.show();
  }
  else if (Heart::current_life >= 300){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 3);
    strip_.show();
  }
  else if (Heart::current_life >= 200){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 2);
    strip_.show();
  }
  else if (Heart::current_life >= 100){
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color, 0, 1);
    strip_.show();
  }
  else{
    strip_.clear();
    uint32_t color = strip_.Color(255, 0, 0);
    strip_.fill(color);
    strip_.show();
  }


  return;
}

void Captivity::End() {
  Serial.println("----END----");
  PrintPlayerState();

  heart_.StopTimer();

  strip_.clear();
  uint32_t color = strip_.Color(255, 255, 255);
  strip_.fill(color);
  strip_.show();

  return;
}

void Captivity::PrintPlayerState() {
  Serial.print("player 1 = ");
  Serial.print(player1_state);
  Serial.print(" | player 2 = ");
  Serial.println(player2_state);

  return;
}