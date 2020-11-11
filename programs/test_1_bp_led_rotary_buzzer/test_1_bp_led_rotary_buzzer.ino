/*
  test_1_bp_led_rotary_buzzer.ino
  Detect rising edge on push button then 
  blink led once and play zap sound on buzzer.
  rotary potentiometer select frequancy start
  https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
*/
#define ROTARYPin A0 // rotary pinout number
#define LEDPin  4   //  LED pinout number
#define BUTTONPin  6 //  pushbutton pinout number
#define BUZZERPin  5  // buzzer pinout number

#define DELAY 200     //delay led blink
uint8_t buttonState;
uint8_t buttonTrigger = 0;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(BUZZERPin, OUTPUT);
  pinMode(ROTARYPin, INPUT);
  pinMode(BUTTONPin, INPUT);
}

void loop() {
  buttonState = digitalRead(BUTTONPin);
  if (buttonState == 1) {
    buttonTrigger |= 1;
    if (buttonTrigger == 1) { //is it a rising edge
      blinkLed(DELAY);      //blink and then play
      playZap();
    }
  }
  buttonTrigger <<= 1;      //shift and mask for next loop
  buttonTrigger &= 3;
}

void blinkLed(uint16_t wait) {
  digitalWrite(LEDPin, HIGH);
  delay(wait);
  digitalWrite(LEDPin, LOW);
  delay(wait);
}

void playZap() {
  uint16_t f;
  uint16_t fStart=analogRead(ROTARYPin)+1000;  
  for (f = fStart; f > 500; f--) {
    tone(BUZZERPin, f);
    delay(1);
  }
  noTone(BUZZERPin);
}
