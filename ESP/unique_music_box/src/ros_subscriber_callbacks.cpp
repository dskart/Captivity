#include "ros_subscriber_callbacks.hpp"

#include "captivity.hpp"

void GameStateCB(const captivity::GameState& incoming_msg) {
  Captivity::current_state = incoming_msg.game_state;
  Captivity::playerA_state = incoming_msg.player1;
  Captivity::playerA_state = incoming_msg.player2;

  return;
}

void MusicBoxStateCB(const std_msgs::UInt8& incoming_msg){
  Captivity::play_music = incoming_msg.data;

  return;
}
