#include "captivity.hpp"

void Captivity::Idle() {
  if (music_playing_){
    StopMusic();
  }
  Captivity::monster_out = 0;
  return;
}

void Captivity::Reset() {
  if (music_playing_){
    StopMusic();
  }

  Captivity::monster_out = 0;
  return;
}

void Captivity::Start() {
  if (!monster_out){
    if (music_playing_){
      if (!play_music){
        StopMusic();
        music_interrupt_start_time_ = millis();
      }
      else{
        CheckEndAndRestartSong();
      }
    }

    if (!music_playing_){
      if (play_music){
        mp3_.play();
        music_playing_ = 1;
        music_start_time_ = millis();
        delay(100);
      }
      else{
        if ((millis() - music_interrupt_start_time_) > interrupt_max_duration_) {
          Captivity::monster_out = 1;
        }
      }
    }
  }

  return;
}

void Captivity::End() {
  if (music_playing_){
    Serial.println("STOPPING MUSIC");
    StopMusic();
  }
  Captivity::monster_out = 0;
  return;
}

void Captivity::StopMusic(){
   mp3_.stop();
   music_playing_ = 0;

  return;
}

void Captivity::CheckEndAndRestartSong(){
  if ((millis() - music_start_time_) > song_duration_){
    mp3_.stop();
    music_playing_ = 0;
    delay(100);
  }

  return;
}

