#include "ros_subscriber_callbacks.hpp"

#include "captivity.hpp"
#include <Arduino.h>

void GameStateCB(const captivity::GameState& incoming_msg) {
  Captivity::current_state = incoming_msg.game_state;
  Captivity::player1_state = incoming_msg.player1;
  Captivity::player2_state = incoming_msg.player2;

  return;
}

void PlayerHealthCB(const std_msgs::Int32& incoming_msg){

  int32_t normalized_health = map(incoming_msg.data, 0, 9000, 0, 1000);
  Captivity::health = normalized_health;
  
  return;
}