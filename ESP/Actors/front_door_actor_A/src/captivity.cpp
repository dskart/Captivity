#include "captivity.hpp"


void Captivity::Idle() {
  Serial.println("----IDLE----");
  Captivity::front_door_actor_state = 0;
  DisplayLEDs(1,1,1);
  return;
}

void Captivity::Reset() {
  Serial.println("----RESET----");
  Captivity::front_door_actor_state = 0;
  DisplayLEDs(1,0,0);
  return;
}

void Captivity::Start() {
  if(Captivity::front_door_actor_state == 0){
    DisplayLEDs(1,0,0); 
  }
  else if (Captivity::front_door_actor_state == 1){
    DisplayLEDs(0,1,0); 
  }
  else if (Captivity::front_door_actor_state == 2){
    DisplayLEDs(0,0,1); 
  }
  return;
}

void Captivity::End() {
  Serial.println("----END----");
  Captivity::front_door_actor_state = 0;
  DisplayLEDs(1,1,1);
  return;
}

void Captivity::DisplayLEDs(const bool &red_led, const bool &yellow_led, const bool &green_led){
  digitalWrite(RED_LED, red_led);
  digitalWrite(YELLOW_LED, yellow_led);
  digitalWrite(GREEN_LED, green_led);

  return;
}

