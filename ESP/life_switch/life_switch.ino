#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 50;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;

bool Captivity::life_switch_state = 0;
bool old_life_switch_state = 0;

void setup() {
  pinMode(PLAYER_B_PIN, INPUT);
  pinMode(PLAYER_A_PIN, INPUT);

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

  if (Captivity::life_switch_state != old_life_switch_state) {
    PublishLifeSwitch();
    old_life_switch_state = Captivity::life_switch_state;
  }

  node.SpinOnce(kSpinFrequency);
}


void PublishLifeSwitch(){
  ros::Publisher* life_switch_state_pub = node.GetTopicPublisher(PublisherTopics::LIFE_SWITCH);
  std_msgs::UInt8 life_switch_state_msg;
  life_switch_state_msg.data = Captivity::life_switch_state;
  life_switch_state_pub->publish(&life_switch_state_msg);

  return;
}