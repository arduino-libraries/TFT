/* TFTRainbow
  by K.Abhijeet
  This example code prints the Rainbow to the screen.
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
int16_t x=80, y=100, r, st_angle=0, end_angle=180;

void setup() {

  Serial.begin(9600);

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);

 
  TFTscreen.setTextSize(1);
  TFTscreen.text("Rainbow: ", 2, 0);

  for(r=0;r<=50;r++)
  {
     TFTscreen.stroke(random(255),random(255),random(255));
     delay(5);
     TFTscreen.arc(x, y, r, st_angle, end_angle);    
    }

  Serial.println("Rainbow completed!");
}

void loop() {}
