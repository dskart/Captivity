#ifndef CAPTIVITY_HPP
#define CAPTIVITY_HPP

#include <Arduino.h>
#include "SerialMP3Player.h"

#define TX D6
#define RX D7

enum GameStates {
  IDLE = 0,
  RESET = 1,
  START = 2,
  END = 3
};

class Captivity {
 public:
  Captivity(){
    mp3_.begin(9600);  // start mp3-communication
    delay(500);       // wait for init

    mp3_.sendCommand(CMD_SEL_DEV, 0, 2);  //select sd-card
    delay(500);
  };
  ~Captivity(){};

  static uint8_t current_state;
  static bool player1_state;
  static bool player2_state;
  static bool play_music;
  static bool monster_out;


  void Idle();
  void Reset();
  void Start();
  void End();

 private:
  SerialMP3Player mp3_;

  bool music_playing_ = 0;
  uint32_t music_start_time_;

  uint32_t music_interrupt_start_time_;

  const uint32_t song_duration_ = 60000 + 20000; // 1:10min
  const uint32_t interrupt_max_duration_ = 10000;

  void CheckEndAndRestartSong();
  void StopMusic();
  
};

#endif  // CAPTIVITY_HPP