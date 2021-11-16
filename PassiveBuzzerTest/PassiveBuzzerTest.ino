#include "pitches.h"

int melody[] = {NOTE_D4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_E4, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_A4};

int buttonPin = 12;

int noteDurations[] = {12, 12, 12, 2, 2, 12, 12, 12, 2, 4, 12, 12, 12, 2, 4, 12, 12, 12, 2, 6, 12, 2, 2, 12, 12, 12, 2, 4, 12, 12, 12, 2, 4, 12, 12, 12, 2, 6, 12, 8/3, 8, 8, 8, 8, 8, 12, 12, 12, 6, 12, 4, 6, 12, 8/3, 8, 8, 8, 8, 8, 4, 2};

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  if (buttonState == 1)
  {
    for (int thisNote = 0; thisNote < sizeof(melody); thisNote++)
    {
      int noteDuration = 1000/ noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      noTone(8);
    }
  }
}
