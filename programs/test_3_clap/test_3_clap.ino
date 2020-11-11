/*
  test_3_clap.ino
  When clap with hands
  light on the led
  clap again led is off
  works as schmitt tigger
  https://en.wikipedia.org/wiki/Schmitt_trigger
*/
#define SOUNDPin A2 // sound sensor pinout number
#define LEDPin  4   //  LED pinout number

#define CLAP_LEVEL_TRIGGER_HIGH 1000  //Trigger high
#define CLAP_LEVEL_TRIGGER_LOW 750    //Tigger low

uint16_t soundLevel;
uint8_t ledState = 0;
uint8_t triggerState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(SOUNDPin, INPUT);
}

void loop() {
  soundLevel = analogRead(SOUNDPin);
  Serial.println(soundLevel);
  if (triggerState == 0) {
    if (soundLevel > CLAP_LEVEL_TRIGGER_HIGH) {
      triggerState = 1;
      swappLed();
      delay(500); //delay to avoid sound bounce
    }
  }
    else {
      if (soundLevel < CLAP_LEVEL_TRIGGER_LOW) {
        triggerState = 0;        
      }
    }
}

void swappLed()
{
  if (ledState == 0) {
    ledState = 1;
    digitalWrite(LEDPin, HIGH);
  }
  else
  {
    ledState = 0;
    digitalWrite(LEDPin, LOW);
  }
}
