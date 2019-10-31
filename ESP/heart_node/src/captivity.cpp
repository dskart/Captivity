#include "captivity.hpp"

void Captivity::Idle() {
  // Serial.println("----IDLE----");
  heart_.player_A_state = Captivity::player1_state;
  heart_.player_B_state = Captivity::player2_state;

  heart_.StopTimer();

  heart_.FillAllLifeMeter_A(0, 0, 255);
  heart_.FillAllLifeMeter_B(0, 0, 255);

  heart_.FillAllHeart_A(0, 0, 255);
  heart_.FillAllHeart_B(0, 0, 255);

  heart_.FillAllArtery_A(0, 0, 255);
  heart_.FillAllArtery_B(0, 0, 255);

  Heart::life_switch = LifeSwitch::A;

  return;
}

void Captivity::Reset() {
  // Serial.println("----RESET----");
  heart_.player_A_state = Captivity::player1_state;
  heart_.player_B_state = Captivity::player2_state;

  heart_.StopTimer();
  heart_.Reset();

  heart_.FillAllLifeMeter_A(255, 0, 0);
  heart_.FillAllLifeMeter_B(255, 0, 0);

  heart_.FillAllHeart_A(255, 0, 0);
  heart_.FillAllHeart_B(255, 0, 0);

  heart_.FillAllArtery_A(255, 0, 0);
  heart_.FillAllArtery_B(255, 0, 0);

  Heart::life_switch = LifeSwitch::A;

  return;
}

void Captivity::Start() {
  heart_.player_A_state = Captivity::player1_state;
  heart_.player_B_state = Captivity::player2_state;

  if (!heart_.TimerActive()) {
    heart_.StartTimer();
  }

  if (Heart::using_power) {
    heart_.FillAllArtery_A(255, 0, 0);
    heart_.FillAllArtery_B(255, 0, 0);
    heart_.power_use_start_time = millis();
    Heart::using_power = 0;
  } else {
    if (millis() - heart_.power_use_start_time > heart_.power_use_display_max_time) {
      heart_.FillAllArtery_A(0, 0, 0);
      heart_.FillAllArtery_B(0, 0, 0);
      heart_.power_use_start_time = 0;
    }
  }

  switch (Heart::life_switch) {
    case LifeSwitch::A:
      heart_.FillAllLifeMeter_B(0, 0, 0);
      heart_.UpdateLifeMeter_A();
      break;

    case LifeSwitch::B:
      heart_.FillAllLifeMeter_A(0, 0, 0);
      heart_.UpdateLifeMeter_B();
      break;
  }

  return;
}

void Captivity::End() {
  // Serial.println("----END----");
  heart_.player_A_state = Captivity::player1_state;
  heart_.player_B_state = Captivity::player2_state;

  heart_.StopTimer();
  heart_.Reset();

  heart_.FillAllLifeMeter_A(100, 100, 100);
  heart_.FillAllLifeMeter_B(100, 100, 100);

  heart_.FillAllHeart_A(100, 100, 100);
  heart_.FillAllHeart_B(100, 100, 100);

  heart_.FillAllArtery_A(100, 100, 100);
  heart_.FillAllArtery_B(100, 100, 100);

  Heart::life_switch = LifeSwitch::A;

  return;
}

void Captivity::PrintPlayerState() {
  Serial.print("player 1 = ");
  Serial.print(player1_state);
  Serial.print(" | player 2 = ");
  Serial.println(player2_state);

  return;
}