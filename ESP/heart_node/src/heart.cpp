#include "heart.hpp"

void LifeTimerISR() {
  switch (Heart::life_switch) {
    case LifeSwitch::A:
      Heart::player_A_life -= LIFE_CONSTANT_DECREASE;

      if (Heart::player_A_life <= 0) {
        Heart::player_A_life = 0;
      }
      break;

    case LifeSwitch::B:
      Heart::player_B_life -= LIFE_CONSTANT_DECREASE;

      if (Heart::player_B_life <= 0) {
        Heart::player_B_life = 0;
      }
      break;
  }
  return;
}

Heart::Heart() : strip_A(LED_COUNT, LED_PIN_A), strip_B(LED_COUNT, LED_PIN_B) {
  strip_A.begin();
  strip_A.show();
  strip_A.setBrightness(255);

  strip_B.begin();
  strip_B.show();
  strip_B.setBrightness(255);
}

void Heart::StartTimer() {
  life_timer_.attach(1, LifeTimerISR);

  return;
}

void Heart::StopTimer() {
  life_timer_.detach();
}

bool Heart::TimerActive() {
  if (life_timer_.active()) {
    return 1;
  }

  return 0;
}

void Heart::Reset() {
  Heart::player_A_life = 9000;
  Heart::player_B_life = 9000;
  return;
}

void Heart::FillAllLifeMeter_A(uint8_t red, uint8_t green, uint8_t blue) {
  if (!player_A_state) {
    red = 0;
    green = 0;
    blue = 0;
  }

  strip_A.fill(0, 0, life_meter_num_led);
  uint32_t color = strip_A.Color(red, green, blue);
  strip_A.fill(color, 0, life_meter_num_led);
  strip_A.show();

  return;
}

void Heart::FillAllLifeMeter_B(uint8_t red, uint8_t green, uint8_t blue) {
  if (!player_B_state) {
    red = 0;
    green = 0;
    blue = 0;
  }

  strip_B.fill(0, 0, life_meter_num_led);
  uint32_t color = strip_B.Color(red, green, blue);
  strip_B.fill(color, 0, life_meter_num_led);
  strip_B.show();

  return;
}

void Heart::FillLifeMeterUpToo_A(uint8_t num_led) {
  strip_A.fill(0, 0, life_meter_num_led);
  uint32_t color = strip_A.Color(255, 0, 0);
  strip_A.fill(color, 0, num_led);
  strip_A.show();

  return;
}

void Heart::FillLifeMeterUpToo_B(uint8_t num_led) {
  strip_B.fill(0, 0, life_meter_num_led);
  uint32_t color = strip_B.Color(255, 0, 0);
  strip_B.fill(color, 0, num_led);
  strip_B.show();

  return;
}

void Heart::UpdateLifeMeter_A() {
  if (!player_A_state) {
    Heart::player_A_life = 0;
  }
  if (Heart::player_A_life <= 5) {
    FillAllLifeMeter_A(0, 0, 0);
  } else if (Heart::player_A_life >= 8000) {
    FillLifeMeterUpToo_A(9);
  } else if (Heart::player_A_life >= 7000) {
    FillLifeMeterUpToo_A(8);
  } else if (Heart::player_A_life >= 6000) {
    FillLifeMeterUpToo_A(7);
  } else if (Heart::player_A_life >= 5000) {
    FillLifeMeterUpToo_A(6);
  } else if (Heart::player_A_life >= 4000) {
    FillLifeMeterUpToo_A(5);
  } else if (Heart::player_A_life >= 3000) {
    FillLifeMeterUpToo_A(4);
  } else if (Heart::player_A_life >= 2000) {
    FillLifeMeterUpToo_A(3);
  } else if (Heart::player_A_life >= 1000) {
    FillLifeMeterUpToo_A(2);
  } else if (Heart::player_A_life < 1000) {
    FillLifeMeterUpToo_A(1);
  } else {  // life is zero
    FillAllLifeMeter_A(0, 0, 0);
  }

  return;
}

void Heart::UpdateLifeMeter_B() {
  if (!player_B_state) {
    Heart::player_B_life = 0;
  }

  // 5 as buffer
  if (Heart::player_B_life <= 5) {
    FillAllLifeMeter_B(0, 0, 0);
  } else if (Heart::player_B_life >= 8000) {
    FillLifeMeterUpToo_B(9);
  } else if (Heart::player_B_life >= 7000) {
    FillLifeMeterUpToo_B(8);
  } else if (Heart::player_B_life >= 6000) {
    FillLifeMeterUpToo_B(7);
  } else if (Heart::player_B_life >= 5000) {
    FillLifeMeterUpToo_B(6);
  } else if (Heart::player_B_life >= 4000) {
    FillLifeMeterUpToo_B(5);
  } else if (Heart::player_B_life >= 3000) {
    FillLifeMeterUpToo_B(4);
  } else if (Heart::player_B_life >= 2000) {
    FillLifeMeterUpToo_B(3);
  } else if (Heart::player_B_life >= 1000) {
    FillLifeMeterUpToo_B(2);
  } else if (Heart::player_B_life < 1000) {
    FillLifeMeterUpToo_B(1);
  } else {  // life is zero
    FillAllLifeMeter_B(0, 0, 0);
  }

  return;
}

void Heart::FillAllHeart_A(uint8_t red, uint8_t green, uint8_t blue) {
  if (!player_A_state) {
    red = 0;
    green = 0;
    blue = 0;
  }

  strip_A.fill(0, heart_led_start, heart_num_led);
  uint32_t color = strip_A.Color(red, green, blue);
  strip_A.fill(color, heart_led_start, heart_num_led);
  strip_A.show();

  return;
}

void Heart::FillAllHeart_B(uint8_t red, uint8_t green, uint8_t blue) {
  if (!player_B_state) {
    red = 0;
    green = 0;
    blue = 0;
  }

  strip_B.fill(0, heart_led_start, heart_num_led);
  uint32_t color = strip_B.Color(red, green, blue);
  strip_B.fill(color, heart_led_start, heart_num_led);
  strip_B.show();

  return;
}

void Heart::FillAllArtery_A(uint8_t red, uint8_t green, uint8_t blue) {
  if (!player_A_state) {
    red = 0;
    green = 0;
    blue = 0;
  }

  strip_A.fill(0, artery_led_start, artery_num_led);
  uint32_t color = strip_A.Color(red, green, blue);
  strip_A.fill(color, artery_led_start, artery_num_led);
  strip_A.show();

  return;
}

void Heart::FillAllArtery_B(uint8_t red, uint8_t green, uint8_t blue) {
  if (!player_B_state) {
    red = 0;
    green = 0;
    blue = 0;
  }

  strip_B.fill(0, artery_led_start, artery_num_led);
  uint32_t color = strip_B.Color(red, green, blue);
  strip_B.fill(color, artery_led_start, artery_num_led);
  strip_B.show();

  return;
}