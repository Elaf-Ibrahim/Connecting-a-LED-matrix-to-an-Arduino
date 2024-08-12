#include <LedControl.h>

//  منافذ أردوينو
int DIN = 11;
int CLK = 13;
int CS = 10;

LedControl lc = LedControl(DIN, CLK, CS, 4);


byte closed_mouth[] = {
 B00000000,
 B01100110,
 B01100110,
 B00000000,
 B01111110,
 B00111100,
 B00000000,
 B00000000
};

byte open_mouth[] = {
 B00000000,
 B01100110,
 B01100110,
 B00000000,
 B01111110,
 B01000010,
 B00111100,
 B00000000
};

void setup() {
  
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }
}

void loop() {
  
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, closed_mouth[row]);
    lc.setRow(1, row, closed_mouth[row]);
    lc.setRow(2, row, closed_mouth[row]);
    lc.setRow(3, row, closed_mouth[row]);
  }
  delay(1000);

  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, open_mouth[row]);
    lc.setRow(1, row, open_mouth[row]);
    lc.setRow(2, row, open_mouth[row]);
    lc.setRow(3, row, open_mouth[row]);
  }
  delay(1000);
}
