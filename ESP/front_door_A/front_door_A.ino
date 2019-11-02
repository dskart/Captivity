#include <Arduino.h>
#include <Ticker.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"
#include <std_msgs/UInt8.h>
#include <std_msgs/Int32.h>

#define DRIVE_CLOSED_PIN D2
#define DRIVE_OPEN_PIN D3 

#define DOOR_CLOSED_PIN D5
#define DOOR_OPEN_PIN D6

#define LOCK_OPEN_PIN D1
#define LOCK_CLOSED_PIN D7

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 10;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;

bool lock_has_changed = 0;
bool lock_is_open = 0; // 1 for open, 0 for closed
bool old_lock_value = 0;
const int drive_speed = 1000;
double pub_freq_float = .5;
int penalty = -111;
int time_closed = 0;


Ticker timer;

void timer_callback(){

  if (Captivity::current_state == GameStates::START){
    if (!lock_is_open){
      std_msgs::Int32 update_life_msg;
      update_life_msg.data = penalty;
   
      ros::Publisher* update_life_pub = node.GetTopicPublisher(PublisherTopics::UPDATE_LIFE);
      update_life_pub->publish(&update_life_msg);
    }
  }
}

void update_lock_state(){
  if (!digitalRead(LOCK_OPEN_PIN) && !digitalRead(LOCK_CLOSED_PIN)){
    lock_is_open = 1;
    
  }
  else if (digitalRead(LOCK_OPEN_PIN) && digitalRead(LOCK_CLOSED_PIN)){
    lock_is_open = 0;
    
  }
  return;
}

void control_door(){
  analogWrite(DRIVE_CLOSED_PIN, 0);
  analogWrite(DRIVE_OPEN_PIN, 0);
  
  if(lock_is_open && !digitalRead(DOOR_OPEN_PIN)){
    analogWrite(DRIVE_OPEN_PIN, drive_speed);
  }
  
  else if(!lock_is_open && !digitalRead(DOOR_CLOSED_PIN)){
    analogWrite(DRIVE_CLOSED_PIN, drive_speed);
  }
}

void OpenDoor(){
  analogWrite(DRIVE_CLOSED_PIN, 0);
  analogWrite(DRIVE_OPEN_PIN, 0);

  if (!digitalRead(DOOR_OPEN_PIN)) {
    analogWrite(DRIVE_OPEN_PIN, drive_speed);
  }
  else{
    analogWrite(DRIVE_OPEN_PIN,0);
    analogWrite(DRIVE_CLOSED_PIN,0);
  }
}

void start_timer(){
  timer.attach(pub_freq_float, timer_callback);
  return;
}

void setup() {
  pinMode(LOCK_OPEN_PIN, INPUT);
  pinMode(LOCK_CLOSED_PIN, INPUT);

  pinMode(DOOR_OPEN_PIN, INPUT);
  pinMode(DOOR_CLOSED_PIN, INPUT);

  pinMode(DRIVE_CLOSED_PIN, OUTPUT);
  pinMode(DRIVE_OPEN_PIN, OUTPUT);

  Serial.begin(115200);
  node.Init();
  start_timer();
}


void loop() {
  switch (Captivity::current_state) {
    case GameStates::IDLE:
      captivity_game.Idle();
      lock_is_open = 1;
      OpenDoor();
      break;

    case GameStates::RESET:
      captivity_game.Reset();
      lock_is_open = 1;
      OpenDoor();
      break;

    case GameStates::START:
      if(Captivity::player1_state){
        control_door();
        update_lock_state();
        captivity_game.Start();
      }
      else {
        lock_is_open = 1;
        OpenDoor();
      }
      break;

    case GameStates::END:
      captivity_game.End();
      lock_is_open = 1;
      OpenDoor();
      break;

    default:
      Serial.println("ERROR: GAME STATE IS WRONG");
      break;
  }
  
  // update_lock_state();
  PublishLockState();
  node.SpinOnce(kSpinFrequency);
}

void PublishLockState(){
  if (old_lock_value != lock_is_open){
    std_msgs::UInt8 locked_msg;
    locked_msg.data = lock_is_open;
    ros::Publisher* front_door_pub = node.GetTopicPublisher(PublisherTopics::FRONT_DOOR);
    front_door_pub->publish(&locked_msg);
    // lock_has_changed = 0;
    old_lock_value = lock_is_open;
  }
    
}
