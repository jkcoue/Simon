#define RED RED_LED
#define BLUE BLUE_LED
#define GREEN GREEN_LED
#define ORBIT_LED_1 PB_5
#define ORBIT_LED_2 PD_6
#define ORBIT_LED_3 PC_7
#define ORBIT_LED_4 PC_6

int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long timer = 0;

void LedSetup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(ORBIT_LED_1, OUTPUT);
  pinMode(ORBIT_LED_2, OUTPUT);
  pinMode(ORBIT_LED_3, OUTPUT);
  pinMode(ORBIT_LED_4, OUTPUT);
}

void RbgLedFlash(int color, long speed) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > speed) {
    previousMillis = currentMillis;
    if (ledState == LOW) ledState = HIGH;
    else ledState = LOW;
    if (color == 0) digitalWrite(RED, ledState);
    else if (color == 1) digitalWrite(BLUE, ledState);
    else  digitalWrite(GREEN, ledState);
  }
}

void OrbitLedFlash(long speed) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > speed) {
    previousMillis = currentMillis;
    if (ledState == LOW) ledState = HIGH;
    else ledState = LOW;
    digitalWrite(ORBIT_LED_1, ledState);
    digitalWrite(ORBIT_LED_2, ledState);
    digitalWrite(ORBIT_LED_3, ledState);
    digitalWrite(ORBIT_LED_4, ledState);
  }
}

void RbgOn(int color) {
  if (color == 0) digitalWrite(RED, HIGH);
  else if (color == 1) digitalWrite(BLUE, HIGH);
  else if (color == 2) digitalWrite(GREEN, HIGH);
  else if (color == 3) {
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
  }
  else if (color == 4) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
  }
  else if (color == 5) {
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
  }
  else if (color == 6) {
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
  }
  else if (color == 7) {
    for (int i = 0; i < 5; i++) {
      analogWrite(RED, 180);
    }
    analogWrite(GREEN, 50);
  }
  else if (color == 8) {
    for (int i = 0; i < 15; i++) {
      analogWrite(RED, 100);
    }
    analogWrite(BLUE, 80);
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
  }
}

void allLedOff() {
  digitalWrite(ORBIT_LED_1, LOW);
  digitalWrite(ORBIT_LED_2, LOW);
  digitalWrite(ORBIT_LED_3, LOW);
  digitalWrite(ORBIT_LED_4, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
  analogWrite(RED, 0);
  analogWrite(BLUE, 0);
  analogWrite(GREEN, 0);
}






