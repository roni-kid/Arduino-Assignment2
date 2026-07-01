// Task 2: Play a Melody
// Plays an ascending C major scale, then waits and repeats.
int buzzerPin = 8;
// 7 notes of the C major scale: C, D, E, F, G, A, B
int notes[] = {262, 294, 330, 349, 392, 440, 494};
// How many notes are in the array
int numNotes = 7;
// How long each note plays (in milliseconds)
int noteDuration = 400;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.println("Playing scale...");
  // Step through each note, one at a time
  for (int i = 0; i < numNotes; i++) {
    Serial.print("Note ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(notes[i]);
    Serial.println(" Hz");
    tone(buzzerPin, notes[i], noteDuration);
    delay(noteDuration + 50); // wait for the note to finish + small gap
  }
  delay(2000); // 2-second pause, then play again

}