#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 50;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;
uint8_t Captivity::front_door_actor_state = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

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

  node.SpinOnce(kSpinFrequency);
}