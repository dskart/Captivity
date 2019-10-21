#include "heart.hpp"

void LifeTimerISR() {
  Serial.print("WHATUP");
  Heart::current_life -= 5;
  
  if (Heart::current_life <= 0){
    Heart::current_life = 0;
  }

  return;
}

void Heart::StartTimer() {
  life_timer_.attach(1, LifeTimerISR);

  return;
}

void Heart::StopTimer(){
  life_timer_.detach();
}

bool Heart::TimerActive(){
  if(life_timer_.active()){
    return 1;
  } 

  return 0 ;
}