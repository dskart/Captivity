#include "ros_subscriber_callbacks.hpp"

#include "captivity.hpp"
#include "heart.hpp"

void GameStateCB(const captivity::GameState& incoming_msg) {
  Captivity::current_state = incoming_msg.game_state;
  Captivity::player1_state = incoming_msg.player1;
  Captivity::player2_state = incoming_msg.player2;

  return;
}

void UpdateLifeCB(const std_msgs::Int32& incoming_msg){
  if(Captivity::current_state == GameStates::START){
    Heart::current_life -= incoming_msg.data;

    if (Heart::current_life <= 0){
      Heart::current_life = 0;
    }
  }
  return;
}
