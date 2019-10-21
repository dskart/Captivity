#ifndef HEART_HPP
#define HEART_HPP

#include <Arduino.h>
#include <Ticker.h>

void LifeTimerISR();

class Heart{
  public:
    Heart(){};
    ~Heart(){};

    void StartTimer();
    void StopTimer();
    bool TimerActive();
    static int current_life;

  private:
    Ticker life_timer_;
};

#endif // HEART_HPP