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
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;

int Heart::current_life = 9000;



void setup(){
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

  ros::Publisher* current_life_pub = node.GetTopicPublisher(PublisherTopics::CURRENT_LIFE);
  std_msgs::Int32 current_life_msg;
  current_life_msg.data = Heart::current_life;
  current_life_pub->publish(&current_life_msg);

  node.SpinOnce(kSpinFrequency);
}