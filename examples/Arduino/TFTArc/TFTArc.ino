/* TFTArc
  by K.Abhijeet
  This example code takes input x, y(center coordinates of arc ), r(radius), start angle and end angle from serial and prints the arc to the screen.
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
int16_t x, y, r, st_angle, end_angle;

void setup() {

  Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter x :");
  //waiting for input
  while (Serial.available() == 0) {}
  x = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter y :");
  //waiting for input
  while (Serial.available() == 0) {}
  y = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter r :");
  //waiting for input
  while (Serial.available() == 0) {}
  r = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter start angle :");
  //waiting for input
  while (Serial.available() == 0) {}
  st_angle = Serial.parseInt();

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter end angle :");
  //waiting for input
  while (Serial.available() == 0) {}
  end_angle = Serial.parseInt();

  TFTscreen.setTextSize(1);
  TFTscreen.text("Your Arc: ", 2, 0);

  TFTscreen.arc(x, y, r, st_angle, end_angle); //draw arc
}

void loop() {}
