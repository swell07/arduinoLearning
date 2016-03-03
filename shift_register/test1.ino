int latchPin = 5; // shift register pin 12
int clockPin = 6; // shift register pin 11
int dataPin = 4; // shift register pin 14
int Power = 3; // to common anode in RGB LEDs to control brightness
int brightness = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(Power, OUTPUT);

}

void loop() {
  if (brightness > 255) {
    brightness = 0;
  } else {
    brightness += 20;
  }

  for (int i = 2; i < 5; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST,B11111111);
    //shiftOut(dataPin, clockPin, MSBFIRST, green);
    //shiftOut(dataPin, clockPin, MSBFIRST, red);
    digitalWrite(latchPin, HIGH);
    analogWrite(Power, brightness);
    delay(100); // milliseconds
  }
}

