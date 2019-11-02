#include "captivity.hpp"

void Captivity::Idle() {
  if (music_playing_){
    StopMusic();
  }
  Captivity::monster_out = 0;
  Captivity::restart_music = 0;
  return;
}

void Captivity::Reset() {
  if (music_playing_){
    StopMusic();
  }

  Captivity::monster_out = 0;
  Captivity::restart_music = 0;
  return;
}

// This is pretty ugly, but like had 2hours to make it work so give me a break
void Captivity::Start() {
  if (monster_out){
    return;
  }

  if (music_playing_){
    // turn of the music
    if (!play_music){
      StopMusic();
      music_interrupt_start_time_ = millis();
    }
    else{
      // restart song if at the end of song
      CheckEndAndRestartSong();
    }
  }

  if (!music_playing_){
    // turn on the music
    if (play_music){
      mp3_.play();
      music_playing_ = 1;
      music_start_time_ = millis();
      delay(100);
    }
    else{
      
      // music out for too long
      if ((millis() - music_interrupt_start_time_) > interrupt_max_duration_) {
        Captivity::monster_out = 1;
      }

      //clicked the restart switch, ready to pub
      if (digitalRead(RESTART_PIN_A) || digitalRead(RESTART_PIN_B)) {
        Serial.println("RESTART MUSIC");
        Captivity::restart_music = 1;
      }
    }
  }


  return;
}

void Captivity::End() {
  if (music_playing_){
    StopMusic();
  }
  Captivity::monster_out = 1;
  Captivity::restart_music = 0;
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


