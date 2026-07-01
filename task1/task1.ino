// Task 1: First Beep
// Plays a single tone every two seconds.
int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Buzzer test starting...");
}

void loop() {
  Serial.println("BEEP!");
  tone(buzzerPin, 1000); // play 1000 Hz tone
  delay(500); // let it play for half a second
  noTone(buzzerPin); // stop the tone
  delay(1500); // silence for 1.5 seconds
}
