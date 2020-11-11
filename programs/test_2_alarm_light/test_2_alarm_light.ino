/*
  test_2_alarm_light.ino
  Detect ambiant light
  When light is lower than 200 alarm is on
*/
#define LIGHTPin A6 // light sensor pinout number
#define LEDPin  4   //  LED pinout number
#define BUZZERPin  5  // buzzer pinout number

#define LEVEL 200     //light level tigger
#define FREQUENCY 1000  //alarm frequency

uint16_t lightLevel;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(BUZZERPin, OUTPUT);
  pinMode(LIGHTPin, INPUT);
}

void loop() {
  lightLevel = analogRead(LIGHTPin);
  Serial.println(lightLevel);
  if (lightLevel < LEVEL) {
    digitalWrite(LEDPin, HIGH);
    tone(BUZZERPin, FREQUENCY);
  }
  else {
    digitalWrite(LEDPin, LOW);
    noTone(BUZZERPin);
  }
}
