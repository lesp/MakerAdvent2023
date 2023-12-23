/********************************************************************
All of this code is based on Brian Lough's fabulous work on the Cheap Yello Display
https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display
YouTube: https://www.youtube.com/brianlough
Twitter: https://twitter.com/witnessmenow

I've also used Adafruit's NeoPixel libary to control some external NeoPixels.
https://github.com/adafruit/Adafruit_NeoPixel
 *******************************************************************/

// Make sure to copy the UserSetup.h file into the library as
// per the Github Instructions. The pins are defined in there.

// ----------------------------
// Standard Libraries
// ----------------------------

#include <SPI.h>


// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include <XPT2046_Touchscreen.h>
// A library for interfacing with the touch screen
//
// Can be installed from the library manager (Search for "XPT2046")
//https://github.com/PaulStoffregen/XPT2046_Touchscreen

#include <TFT_eSPI.h>
// A library for interfacing with LCD displays
//
// Can be installed from the library manager (Search for "TFT_eSPI")
//https://github.com/Bodmer/TFT_eSPI

#include <Adafruit_NeoPixel.h>
// Adafruit's NeoPixel library
//
// Can be installed via the Arduino library manager (Search for "Adafruit NeoPixel")
// https://github.com/adafruit/Adafruit_NeoPixel


// ----------------------------
// Touch Screen pins
// ----------------------------

// The CYD touch uses some non default
// SPI pins

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33
#define CYD_LED_BLUE 17
#define CYD_LED_RED 4
#define CYD_LED_GREEN 16
#define LED_PIN    22
#define LED_COUNT 8
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// ----------------------------

SPIClass mySpi = SPIClass(VSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  pinMode(CYD_LED_RED, OUTPUT);
  pinMode(CYD_LED_GREEN, OUTPUT);
  pinMode(CYD_LED_BLUE, OUTPUT);

  // Start the SPI for the touch screen and init the TS library
  mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  ts.begin(mySpi);
  ts.setRotation(1);

  // Start the tft display and set it to black
  tft.init();
  tft.setRotation(1); //This is the display in landscape

  // Clear the screen before writing to it
  tft.fillScreen(TFT_BLACK);

  int x = 320 / 2; // center of display
  int y = 100;
  int fontSize = 4;
  tft.drawCentreString("Maker Advent Day 23", x, y, fontSize);
  y += 24;
  String temp = "Touch screen to start";
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.drawCentreString(temp, x, y, fontSize);
  digitalWrite(CYD_LED_RED, HIGH); // The LEDs are "active low", meaning HIGH == off, LOW == on
  digitalWrite(CYD_LED_GREEN, HIGH);
  digitalWrite(CYD_LED_BLUE, HIGH);
}

void printTouchToSerial(TS_Point p) {
  Serial.print("Pressure = ");
  Serial.print(p.z);
  Serial.print(", x = ");
  Serial.print(p.x);
  Serial.print(", y = ");
  Serial.print(p.y);
  Serial.println();
}

void printTouchToDisplay(TS_Point p) {

  // Clear screen first
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  int x = 320 / 2; // center of display
  int y = 100;
  int fontSize = 4;
}

void loop() {
  int x = 320 / 2;
  int y = 0;
  int fontSize = 4;
  if (ts.tirqTouched() && ts.touched()) {
    TS_Point p = ts.getPoint();
    printTouchToSerial(p);
    printTouchToDisplay(p);
    for (int i = 0; i <= 4; i++) {
      String temp = "FLASHNG LIGHTS!";
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.drawCentreString(temp, x, y, fontSize);
      digitalWrite(CYD_LED_RED, LOW); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, HIGH);
      colorWipe(strip.Color(255,   0,   0), 50);
      delay(200);
      digitalWrite(CYD_LED_RED, HIGH); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, HIGH);
      delay(100);
      y += 24;
      temp = "Merry Christmas";
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.drawCentreString(temp, x, y, fontSize);
      digitalWrite(CYD_LED_RED, HIGH); 
      digitalWrite(CYD_LED_GREEN, LOW);
      digitalWrite(CYD_LED_BLUE, HIGH);
      colorWipe(strip.Color(0,   255,   0), 50);
      delay(200);
      digitalWrite(CYD_LED_RED, HIGH); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, HIGH);
      delay(100);
      y += 24;
      temp = "Happy Holidays";
      tft.setTextColor(TFT_BLUE, TFT_BLACK);
      tft.drawCentreString(temp, x, y, fontSize);
      digitalWrite(CYD_LED_RED, HIGH); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, LOW);
      colorWipe(strip.Color(0,   0,   255), 50);
      delay(200);
      digitalWrite(CYD_LED_RED, HIGH); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, HIGH);
      delay(100);
      digitalWrite(CYD_LED_RED, LOW); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, LOW);
      colorWipe(strip.Color(255,   0,   255), 50);
      delay(200);
      digitalWrite(CYD_LED_RED, HIGH); 
      digitalWrite(CYD_LED_GREEN, HIGH);
      digitalWrite(CYD_LED_BLUE, HIGH);
      delay(100);
      tft.fillScreen(TFT_BLACK);
      colorWipe(strip.Color(0,0,0), 100);
      strip.show();
    }
  }
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
