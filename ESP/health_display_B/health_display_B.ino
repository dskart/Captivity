#include <Arduino.h>

#include "src/captivity.hpp"
#include "src/esp_ros_node.hpp"
#include <TM1637Display.h>

#define CLK D2
#define DIO D1
#define TEST_DELAY 2000

EspRosNode node;
Captivity captivity_game;

const uint16_t kSpinFrequency = 10;

uint8_t Captivity::current_state = GameStates::IDLE;
bool Captivity::player1_state = 0;
bool Captivity::player2_state = 0;
int32_t Captivity::health = 100;

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(115200);
  node.Init();
  display.setBrightness(0x0f);
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
    // Show decimal numbers with/without leading zeros

  display.showNumberDec(Captivity::health,false);
  node.SpinOnce(kSpinFrequency);
}