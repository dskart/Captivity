#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

#define LIFE_DECREASE 55 

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 50;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;

bool Captivity::iris_switch_state = 0;
bool Captivity::update_life = 0;
bool old_iris_switch_state = 0;

void setup() {
  pinMode(LOCK_PIN, INPUT);
  pinMode(UNLOCK_PIN, INPUT);

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

  if (Captivity::iris_switch_state != old_iris_switch_state){
    PublishIrisSwitch();
    old_iris_switch_state = Captivity::iris_switch_state;
  }

  if(Captivity::update_life){
    PublishUpdateLife();
  }

  node.SpinOnce(kSpinFrequency);
}


void PublishIrisSwitch(){
  ros::Publisher* iris_state_pub = node.GetTopicPublisher(PublisherTopics::IRIS_SWITCH);
  std_msgs::UInt8 iris_state_msg;
  iris_state_msg.data = Captivity::iris_switch_state;
  iris_state_pub->publish(&iris_state_msg);

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