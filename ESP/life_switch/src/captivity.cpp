#include "captivity.hpp"


void Captivity::Idle() {
  // Serial.println("----IDLE----");
  // PrintPlayerState();
  life_switch_state = 1;

  return;
}

void Captivity::Reset() {
  // Serial.println("----RESET----");
  life_switch_state = 1;

  return;
}

void Captivity::Start() {
  // Serial.println("----START----");

  if(Captivity::player1_state && Captivity::player2_state){
    if(life_switch_state){ // A
      if (digitalRead(PLAYER_B_PIN)) {
        life_switch_state = 0;
      }
    } 
    else{
      if (digitalRead(PLAYER_A_PIN)){
        life_switch_state = 1;
      }
    }
  }
  else if (!Captivity::player1_state){
    life_switch_state = 1;
  }
  else if (!Captivity::player2_state){
    life_switch_state = 0;
  }
  return;
}

void Captivity::End() {
  // Serial.println("----END----");
  life_switch_state = 1;

  return;
}
