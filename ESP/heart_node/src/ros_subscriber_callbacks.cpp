#include "ros_subscriber_callbacks.hpp"

#include "captivity.hpp"
#include "heart.hpp"

void GameStateCB(const captivity::GameState& incoming_msg) {
  Captivity::current_state = incoming_msg.game_state;
  Captivity::player1_state = incoming_msg.player1;
  Captivity::player2_state = incoming_msg.player2;

  return;
}

void UpdateLifeCB(const std_msgs::Int32& incoming_msg) {
  Heart::using_power = 1;
  if (Captivity::current_state == GameStates::START) {
    switch (Heart::life_switch) {
      case LifeSwitch::A:
        Heart::player_A_life += incoming_msg.data;

        if (Heart::player_A_life <= 0) {
          Heart::player_A_life = 0;
        }
        break;

      case LifeSwitch::B:
        Heart::player_B_life += incoming_msg.data;

        if (Heart::player_B_life <= 0) {
          Heart::player_B_life = 0;
        }
        break;
    }
  }
  return;
}

void LifeSwitchCB(const std_msgs::UInt8& incoming_msg) {
  Heart::life_switch = incoming_msg.data;
  Serial.println(Heart::life_switch);
  return;
}
