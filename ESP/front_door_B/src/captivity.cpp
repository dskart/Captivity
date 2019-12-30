#include "captivity.hpp"

void Captivity::Idle() {
  // Serial.println("----IDLE----");
  // PrintPlayerState();

  return;
}

void Captivity::Reset() {
  // Serial.println("----RESET----");
  // PrintPlayerState();

  return;
}

void Captivity::Start() {
  // Serial.println("----START----");
  // PrintPlayerState();

  return;
}

void Captivity::End() {
  // Serial.println("----END----");
  // PrintPlayerState();

  return;
}

void Captivity::PrintPlayerState() {
  Serial.print("player 1 = ");
  Serial.print(player1_state);
  Serial.print(" | player 2 = ");
  Serial.println(player2_state);

  return;
}