/* 
  HEART NODE
*/
#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"
#include "src/heart.hpp"

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 10;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 1;
bool Captivity::player2_state = 1;

int32_t Heart::player_A_life = 9000;
int32_t Heart::player_B_life = 9000;
bool Heart::life_switch = LifeSwitch::A;
bool Heart::using_power = 0;

void setup() {
  Serial.begin(115200);
  node.Init();
}

void loop() {
  delay(100);
  switch (Captivity::current_state) {
    case GameStates::IDLE:
      captivity_game.Idle();
      break;

    case GameStates::RESET:
      captivity_game.Reset();
      break;

    case GameStates::START:
      captivity_game.Start();
      break;

    case GameStates::END:
      captivity_game.End();
      break;

    default:
      Serial.println("ERROR: GAME STATE IS WRONG");
      break;
  }

  PublishPlayersLife();

  node.SpinOnce(kSpinFrequency);
}

void PublishPlayersLife() {
  ros::Publisher* player_A_current_life_pub = node.GetTopicPublisher(PublisherTopics::PLAYER_A_CURRENT_LIFE);
  std_msgs::Int32 player_A_current_life_msg;
  player_A_current_life_msg.data = Heart::player_A_life;
  player_A_current_life_pub->publish(&player_A_current_life_msg);

  ros::Publisher* player_B_current_life_pub = node.GetTopicPublisher(PublisherTopics::PLAYER_B_CURRENT_LIFE);
  std_msgs::Int32 player_B_current_life_msg;
  player_B_current_life_msg.data = Heart::player_B_life;
  player_B_current_life_pub->publish(&player_B_current_life_msg);

  return;
}