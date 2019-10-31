#include "captivity.hpp"


void Captivity::Idle() {
  Serial.println("----IDLE----");
  // PrintPlayerState();
  return;
}

void Captivity::Reset() {
  Serial.println("----RESET----");
  return;
}

void Captivity::Start() {
  Serial.println("----START----");
  return;
}

void Captivity::End() {
  Serial.println("----END----");
  return;
}
