
#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 10;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;
bool Captivity::play_music = 0;
bool Captivity::monster_out = 0;

void setup() {
  Serial.begin(115200);
  node.Init();
}

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

  ros::Publisher* monster_out_pub = node.GetTopicPublisher(PublisherTopics::MONSTER_OUT);
  std_msgs::UInt8 monster_out_msg;
  monster_out_msg.data = Captivity::monster_out;
  monster_out_pub->publish(&monster_out_msg);

  node.SpinOnce(kSpinFrequency);
}
