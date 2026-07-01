// Task 4: Show digits 0 to 9 on the 7-segment display.
// Wiring is the same as Task 3 — keep it connected.
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9}; // a, b, c, d, e, f, g
int numSegments = 7;
// The pattern for each digit. 1 = segment ON, 0 = segment OFF.
byte digits[10][7] = {
//a  b  c  d  e  f  g
{1, 1, 1, 1, 1, 1, 0}, // 0
{0, 1, 1, 0, 0, 0, 0}, // 1
{1, 1, 0, 1, 1, 0, 1}, // 2
{1, 1, 1, 1, 0, 0, 1}, // 3
{0, 1, 1, 0, 0, 1, 1}, // 4
{1, 0, 1, 1, 0, 1, 1}, // 5
{1, 0, 1, 1, 1, 1, 1}, // 6
{1, 1, 1, 0, 0, 0, 0}, // 7
{1, 1, 1, 1, 1, 1, 1}, // 8
{1, 1, 1, 1, 0, 1, 1}, // 9
};

// byte digits[10][7] = {
// //Index Number
// {1, 1, 0, 1, 1, 0, 1}, // 2
// {1, 0, 1, 1, 0, 1, 1}, // 5
// {1, 1, 0, 1, 1, 0, 1}, // 2
// {1, 0, 1, 1, 1, 1, 1}, // 6
// {0, 1, 1, 0, 0, 1, 1}, // 4
// {1, 1, 1, 1, 1, 1, 0}, // 0
// {0, 1, 1, 0, 0, 0, 0}, // 1
// {1, 1, 1, 1, 0, 0, 1}, // 3
// {1, 1, 1, 1, 1, 1, 1}, // 8
// {1, 1, 1, 0, 0, 0, 0}, // 7
// };
// Our own function: show a digit on the display.
void showDigit(int n) {
  // For safety: do nothing if the input is outside 0-9.
  if (n < 0 || n > 9) return;
    // Loop through each of the 7 segments.
  for (int i = 0; i < numSegments; i++) {
    // Read the pattern for this digit and segment.
    // If it is 1, turn the segment ON. If 0, turn it OFF.
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}
void setup() {
  Serial.begin(9600);
  // Set every segment pin as OUTPUT.
  for (int i = 0; i < numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT);
}
  // digitalWrite(2, 1); //a
  // digitalWrite(3, 1); //b
  // digitalWrite(4, 1); //c
  // digitalWrite(5, 1); //d
  // digitalWrite(6, 1); //e
  // digitalWrite(9, 1); //g
  // digitalWrite(7, 1); //f
}
void loop() {
  // Count from 0 to 9, showing each digit for 1 second.
  for (int n = 0; n <= 9; n++) {
    Serial.print("\nShowing: ");
    Serial.println(n);
    showDigit(n);
    delay(1000);
}
}