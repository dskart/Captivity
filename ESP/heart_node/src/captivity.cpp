#include "captivity.hpp"


void Captivity::Idle() {
  Serial.println("----IDLE----");
  // PrintPlayerState();

  heart_.StopTimer();

  heart_.FillFullDisplay(0,0,255);

  return;
}

void Captivity::Reset() {
  Serial.println("----RESET----");
  // PrintPlayerState();

  heart_.StopTimer();
  heart_.Reset();
  // Serial.print("LIFE FORCE = ");
  // Serial.println(Heart::current_life);

  heart_.FillFullDisplay(0,255,0);

  return;
}

void Captivity::Start() {
  Serial.println("----START----");
  // PrintPlayerState();

  if (!heart_.TimerActive()){
    heart_.StartTimer();
  }

  heart_.UpdateLifeDisplay();

  return;
}

void Captivity::End() {
  Serial.println("----END----");
  // PrintPlayerState();

  heart_.StopTimer();
  heart_.Reset();

  heart_.FillFullDisplay(100,100,100);

  return;
}

void Captivity::PrintPlayerState() {
  Serial.print("player 1 = ");
  Serial.print(player1_state);
  Serial.print(" | player 2 = ");
  Serial.println(player2_state);

  return;
}