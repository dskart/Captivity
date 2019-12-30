#include "ros_subscriber_callbacks.hpp"

void Chatter2Cb(const captivity::Num& incoming_msg) {
  int msg_heard = incoming_msg.num;
  Serial.println(msg_heard);
}

void GameStateCB(const captivity::GameState& incoming_msg) {
  Captivity::current_state = incoming_msg.game_state;
  Captivity::player1_state = incoming_msg.player1;
  Captivity::player2_state = incoming_msg.player2;

  return;
}
