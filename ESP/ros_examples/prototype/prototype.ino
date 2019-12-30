#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// constants won't change. They're used here to set pin numbers:
// const int buttonPin = ;  // the number of the pushbutton pin
// const int ledPin = ;    // the number of the LED pin

#define SWITCH_PIN 23

// variables will change:
// int buttonState = 0;  // variable for reading the pushbutton status
Adafruit_NeoPixel strip_(15,D1);

void setup() {
  Serial.begin(115200);

  strip_.begin();
  strip_.show();
  strip_.setBrightness(255);

  // initialize the LED pin as an output:
  // pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  // pinMode(SWITCH_PIN, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  // bool out = digitalRead(SWITCH_PIN);
  // if (out) {
    // Serial.println(out);
  // }
  // delay(10);
  // strip_.fill(0,0,14);
  uint32_t color = strip_.Color(255, 0, 0);
  strip_.fill(color, 0, 14);
  strip_.show();
  delay(100);
  Serial.println("HELLO");


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  // if (buttonState == HIGH) {
  //   // turn LED on:
  //   digitalWrite(ledPin, HIGH);
  // } else {
  //   // turn LED off:
  //   digitalWrite(ledPin, LOW);
  // }
}
