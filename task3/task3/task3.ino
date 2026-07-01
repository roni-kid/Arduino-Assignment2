// Task 3: Light up each segment one at a time.
// We use this to confirm that the wiring is correct.
// The pins each segment is connected to.
// Order is: a, b, c, d, e, f, g (g is on pin 9 because pin 8 is the buzzer).
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};
char segmentNames[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
int numSegments = 7;
void setup() {
  Serial.begin(9600);
// Set every segment pin as OUTPUT and start with them OFF.
  for (int i = 0; i < numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }
  Serial.println("Starting segment test...");
}
void loop() {
// Walk through each segment one by one.
  for (int i = 0; i < numSegments; i++) {
    Serial.print("Lighting segment ");
    Serial.println(segmentNames[i]);
    digitalWrite(segmentPins[i], HIGH); // turn this segment ON
    delay(800); // wait so you can see it
    digitalWrite(segmentPins[i], LOW); // turn it OFF
}
  delay(1000); // pause before repeating
}
