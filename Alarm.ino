#include <math.h>

int leds[4] = {6,9,10,11};
int nleds = 4;
int alarmLed = 12;
int alarmTime = 4000; //ms

void setup() {
  // initialize LEDs as PWM
  for (int i = 0; i < 4; i++) pinMode(leds[i], OUTPUT);
  pinMode(alarmLed, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int partialTime = alarmTime / nleds;
  float partialFadeFloat = ((float) partialTime) / 256.0;
  int partialFade = ceil(partialFadeFloat);
  
  for (int i = 0; i < nleds; i++) {
    int fade = 0;
    while (fade <= 255) {
      analogWrite(leds[i], fade); 
      delay(partialFade);
      fade += 1; 
    }
  }

  while(1) {
    digitalWrite(alarmLed, HIGH);
    delay(1000);
    digitalWrite(alarmLed, LOW);
    delay(1000);
  }
}
