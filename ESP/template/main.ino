#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 500;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;

void setup() {
  Serial.begin(115200);
  node.Init();
}

int ii = 0;

void loop() {
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
  // captivity::Num num_msg;
  // num_msg.num = ++ii;

  // ros::Publisher* pub = node.GetTopicPublisher(PublisherTopics::CHATTER1);
  // pub->publish(&num_msg);

  node.SpinOnce(kSpinFrequency);
}