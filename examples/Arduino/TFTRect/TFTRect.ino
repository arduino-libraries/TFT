/* TFTRect

  by K.Abhijeet
  This example code takes input length and width from serial and prints the rectangle to the screen.
*/
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  1

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen

int len, wid;

void setup() {

  Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter length :");
  //waiting for input
  while (Serial.available() == 0) {}
  len = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter width :");
  //waiting for input
  while (Serial.available() == 0) {}
  wid = Serial.parseInt();

  TFTscreen.setTextSize(1);
  TFTscreen.text("Your Rectangle : ", 2, 0);

  TFTscreen.fill(255, 255, 0);
  TFTscreen.rect(10, 20, len, wid); // draw rectangle
}
void loop() {}
