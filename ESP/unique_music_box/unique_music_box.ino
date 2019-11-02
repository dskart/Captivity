
#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 50;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::playerB_state = 0;
bool Captivity::playerA_state = 0;
bool Captivity::play_music = 0;
bool Captivity::monster_out = 0;
bool Captivity::restart_music = 0;

void setup() {
 pinMode(RESTART_PIN_A, INPUT);
 pinMode(RESTART_PIN_B, INPUT);

 Serial.begin(115200);
 node.Init();
}

// ONLY ONE ESP/MUSIC BOX/ HANDLE TWO SWITCHES

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
     PublishMonsterOut();
     PublishMusicBoxState();
     break;

   case GameStates::END:
     captivity_game.End();
     break;

   default:
     Serial.println("ERROR: GAME STATE IS WRONG");
     break;
 }

  node.SpinOnce(kSpinFrequency);
}

void PublishMonsterOut(){
  ros::Publisher* monster_out_pub = node.GetTopicPublisher(PublisherTopics::MONSTER_OUT);
  std_msgs::UInt8 monster_out_msg;
  monster_out_msg.data = Captivity::monster_out;
  monster_out_pub->publish(&monster_out_msg);

  return;
}

void PublishMusicBoxState(){
  if(Captivity::restart_music){
    ros::Publisher* music_state_pub = node.GetTopicPublisher(PublisherTopics::MUSIC_STATE);
    std_msgs::UInt8 music_state_msg;
    music_state_msg.data = 1;
    music_state_pub->publish(&music_state_msg);
    Captivity::restart_music = 0;
  }

  return;
}
