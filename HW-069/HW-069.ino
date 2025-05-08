// Include the library from here --> https://github.com/avishorp/TM1637
#include "TM1637Display.h"

#define CLK 2
#define DIO 3

// display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

// array for making all segments ON
const uint8_t allOn[] = {0xff, 0xff, 0xff, 0xff};

// array for making all segment OFF
const uint8_t allOff[] = {0x00, 0x00, 0x00, 0x00};

// To set the word done
const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

// degree Celsius symbol
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

int temperature = 39;
int hour = 12;
int minute = 0;
const int delayShort = 50;
const int delayMedium = 1000;
const int delayLong = 2000;

void setup() {
  display.setBrightness(7);                        // Set the brightness
  display.setSegments(allOn);                       // Make all segments ON
  delay(delayMedium);
  display.clear();
  delay(delayMedium);
}

void loop() {
  displayCount();
  tempCelsius(temperature);
  timeDisplay(hour, minute);
  display.setSegments(done);           //Display "done" once the above number display is finished
  while(1);
}

// Display numbers from 0 t0 100
// Max value can be up to 9999   i.e, i <= 9999
void displayCount() {
  for (int i = 0; i <= 100; i++) {
    display.showNumberDec(i, false);
    delay(delayShort);
  }
}

// Example Function for displaying the Temperature data in °C
void tempCelsius(int temp) {
  display.showNumberDec(temp, false, 2, 0);
  display.setSegments(celsius, 2, 2);
  delay(delayLong);
}

void timeDisplay(int hour, int minute) {
  for (int i = 0; i <=
   5; i++) {                              // Run for 5 seconds
    int displayTime = hour * 100 + minute;                   // Convert to HHMM format
    display.showNumberDecEx(displayTime, 0b11100000, true);  // Show with colon
    delay(delayMedium);                                      // Tick every second

    minute++;
    if (minute >= 60) {
      minute = 0;
      hour++;
      if (hour >= 24) hour = 0;
    }
  }

  display.clear();
}

