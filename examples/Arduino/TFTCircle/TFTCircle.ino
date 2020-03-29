/* TFTCircle

  by K.Abhijeet

  This example code takes input radius from serial and prints the circle to the screen.
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



int red;

void setup() {

  Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);

  // write the static text to the screen
  Serial.println("Enter radius :");
  //waiting for input
  while (Serial.available() == 0) {}
  red = Serial.parseInt();

 
  TFTscreen.setTextSize(1);
  TFTscreen.text("Your circle : ", 2, 0);

  TFTscreen.fill(255, 255, 0);
  TFTscreen.circle( TFTscreen.width()/2,  TFTscreen.height()/2, red); // draw circle
}

void loop() {}
