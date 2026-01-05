/* UserText

  by K.Abhijeet
  This example code takes input username from serial and prints to the screen.
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
String nm;
char str[100];

void setup() {

  Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);
  // set the font size

  // print text on the serial monitor to instruct user for the input
  Serial.println("Enter your name :");
  TFTscreen.setTextSize(1);
  TFTscreen.text("Enter your name :\n ", 2, 2);
  //waiting for input
  while (Serial.available() == 0) {}
  nm = Serial.readString(); // take input from serial
  nm = "Hello " + nm;

  // convert the string to a char array
  nm.toCharArray(str, 100);

  //print the name
  TFTscreen.text(str, 0, 20);
}
void loop() {}
