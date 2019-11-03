#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

#define LIFE_DECREASE 12

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 50;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;

bool Captivity::switch_state = 0;
bool Captivity::update_life = 0;
bool old_switch_state = 0;

void setup() {
  pinMode(SWITCH_PIN, INPUT);

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

  if(Captivity::switch_state != old_switch_state){
    PublishLigthState();
    old_switch_state = Captivity::switch_state;
  }

  if(Captivity::update_life){
    PublishUpdateLife();
  }

  node.SpinOnce(kSpinFrequency);
}

void PublishLigthState(){
  ros::Publisher* light_state_pub = node.GetTopicPublisher(PublisherTopics::LIGHT_STATE);
  std_msgs::UInt8 light_state_msg;
  light_state_msg.data = Captivity::switch_state;
  light_state_pub->publish(&light_state_msg);

  return;
}

void PublishUpdateLife() {
  ros::Publisher* update_life_pub = node.GetTopicPublisher(PublisherTopics::UPDATE_LIFE);
  std_msgs::Int32 update_life_msg;
  update_life_msg.data = -LIFE_DECREASE ;
  update_life_pub->publish(&update_life_msg);

  Captivity::update_life = 0;

  return;
}