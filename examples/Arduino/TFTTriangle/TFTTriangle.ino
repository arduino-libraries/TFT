/* TFTPointLine

  by K.Abhijeet
  This example code takes input x1,y1 x2,y2 and x3,y3 from serial and prints the triangle to the screen
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
int x1, y1, x2, y2, x3, y3;

void setup() {

  Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter x1 :");
  //waiting for input
  while (Serial.available() == 0) {}
  x1 = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter y1 :");
  //waiting for input
  while (Serial.available() == 0) {}
  y1 = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter x2 :");
  //waiting for input
  while (Serial.available() == 0) {}
  x2 = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter y2 :");
  //waiting for input
  while (Serial.available() == 0) {}
  y2 = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter x3 :");
  //waiting for input
  while (Serial.available() == 0) {}
  x3 = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter y3 :");
  //waiting for input
  while (Serial.available() == 0) {}
  y3 = Serial.parseInt();

  //draw triangle to the screen
  TFTscreen.triangle(x1, y1, x2, y2, x3, y3);
}
void loop() {}
