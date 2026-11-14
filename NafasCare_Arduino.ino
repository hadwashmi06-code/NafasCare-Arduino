#include <LiquidCrystal.h>

// LCD connections
LiquidCrystal lcd(A1, A2, A3, A4, A5, 8);

// LEDs
const int RED_LED = 13;
const int YELLOW_LED = 12;
const int GREEN_LED = 11;

// Buzzer
const int BUZZER = 2;

// Simulated patch signal
const int SENSOR = A0;

int previousState = -1;

void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("NafasCare");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM READY");
  delay(2000);
}

void loop() {
  int rawValue = analogRead(SENSOR);
  int signalValue = map(rawValue, 0, 1023, 0, 100);

  int state;

  // Demonstration thresholds only
  if (signalValue < 40) {
    state = 0; // Normal
  } else if (signalValue < 70) {
    state = 1; // Warning
  } else {
    state = 2; // Alert
  }

  setLights(state == 2, state == 1, state == 0);

  lcd.setCursor(0, 0);
  lcd.print("NafasCare       ");

  lcd.setCursor(0, 1);

  if (state == 0) {
    lcd.print("NORMAL          ");
    noTone(BUZZER);
  }
  else if (state == 1) {
    lcd.print("WARNING         ");
    noTone(BUZZER);
  }
  else {
    lcd.print("ALERT           ");
    tone(BUZZER, 1000);
  }

  delay(200);
}
