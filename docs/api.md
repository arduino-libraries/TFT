# TFT LCD library

## Functions

### `TFT`

#### Description
The base class for drawing to the Arduino TFT screen. Use this to create an named instance of the TFT class to refer to in your sketch.

if using the Arduino Explora, you do not need to call this, all references to the screen are handled through EsploraTFT.

#### Syntax

```
TFT(cs, dc, rst); for using hardware SPI
TFT(cs, dc, mosi, sclk, rst); for use on any pins
```

#### Parameters
cs : int, pin for chip select
dc : int, pin used for
rst : int, pin used for reset
mosi : int, pin used for MOSI communication when not using hardware SPI
sclk : int, pin used for the shared clock, when not using hardware SPI
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // turn off fill coloring
  screen.noFill();

  // draw a rectangle in the center of screen
  screen.line(screen.width()/2-5, screen.height()/2-5, 10, 10);
}

void loop() {

}

```

### `EsploraTFT`

#### Description
This is the named instance of the TFT class when targeting the Arduino Esplora board.

#### Syntax

```
EsploraTFT

```

#### Parameters
none

#### Returns
none

#### Example

```
#include <Esplora.h>
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

void setup() {
  // initialize the screen
  EsploraTFT.begin();

  // make the background white
  EsploraTFT.background(255,255,255);
}

void loop() {

}

```

### `begin()`

#### Description

Must be called to initialize the Arduino GLCD screen before drawing anything.

#### Syntax

```
screen.begin()

```

#### Parameters
none

#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background white
  screen.background(255,255,255);
}

void loop() {

}

```

### `background()`

#### Description

Erases everything currently on the LCD screen with the indicated color. Can be used in loop() to clear the screen.

While background() expects 8-bit values for each of the red, green, and blue channels, the screen does not display with this fidelity. The red and blue values are scaled to 5-bit color (32 discrete steps), and the green is 6-bit color (64 discrete steps).

#### Syntax

```
screen.background(red, green, blue);

```

#### Parameters
red : int 0-255
green : int 0-255
blue : int 0-255
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background white
  screen.background(255,255,255);
}

void loop() {

}

```

### `stroke()`

#### Description

Called before drawing an object on screen, it sets the color of lines and borders around shapes.

stroke() expects 8-bit values for each of the red, green, and blue channels, but the screen does not display with this fidelity. The red and blue values are scaled to 5-bit color (32 discrete steps), and the green is 6-bit color (64 discrete steps).

#### Syntax

```
screen.stroke(red, green, blue);

```

#### Parameters
red : int 0-255
green : int 0-255
blue : int 0-255
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // draw a box with a white outline in the middle of the screen
  screen.rect(screen.width()/2+10,screen.height()/2+10,screen.width()/2-10,screen.height()/2-10);
}

void loop() {

}

```

### `noStroke()`

#### Description

After calling this, any shapes drawn on screen will not have an outline stroke color.

#### Syntax

```
screen.noStroke();

```

#### Parameters
none

#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // turn the stroke off
  screen.noStroke();

  // set the fill color to white
  screen.fill(255,255,255);

  // draw a rectangle in the center of screen
  screen.line(screen.width()/2-5, screen.height()/2-5, 10, 10);
}

void loop() {

}

```

### `fill()`

#### Description

Called before drawing an object on screen, it sets the fill color of shapes and text.

fill() expects 8-bit values for each of the red, green, and blue channels, but the screen does not display with this fidelity. The red and blue values are scaled to 5-bit color (32 discrete steps), and the green is 6-bit color (64 discrete steps).

#### Syntax

```
screen.fill(red, green, blue);

```

#### Parameters
red : int 0-255
green : int 0-255
blue : int 0-255
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);


void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.fill(255,255,255);

  // draw a white box in the screen center
  screen.rect(screen.width()/2+10,screen.height()/2+10,screen.width()/2-10,screen.height()/2-10);
}

void loop() {

}

```

### `noFill()`

#### Description

After calling this, any shapes drawn on screen will not be filled in.

#### Syntax

```
screen.noFill();

```

#### Parameters
none

#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // turn the fill off
  screen.noFill();

  // set the stroke color to white
  screen.stroke(255,255,255);

  // draw a rectangle in the center of screen
  screen.line(screen.width()/2-5, screen.height()/2-5, 10, 10);
}

void loop() {

}

```

### `text()`

#### Description

Write text to the screen at the given coordinates.

#### Syntax

```
screen.text(text, xPos, yPos);

```

#### Parameters
text : char array, the text you want to write on the screen
xPos : int, the location on the x-axis you want to start drawing text to the screen
yPos : int, the location on the y-axis you want to start drawing text to the screen
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the text color to white
  screen.stroke(255,255,255);

  // write text to the screen in the top left corner
  screen.text("Testing!", 0, 0);
}

void loop() {

}

```

### `setTextSize()`

#### Description

Sets the size of text that follows. The default size is "1". Each change in size increases the text by 10 pixels in height. That is, size 1 = 10 pixels, size 2 =20 pixels, and so on.

#### Syntax

```
screen.setTextSize(size);

```

#### Parameters
size : int 1-5
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.fill(255,255,255);

  // default text size
  screen.setTextSize(1);
  // write text to the screen in the top left corner
  screen.text("Testing!", 0, 0);
  // increase text size
  screen.setTextSize(5);
  // write text to the screen below
  screen.text("BIG!", 0, 10);
}

void loop() {

}

```

### `begin()`

#### Description

Must be called to initialize the Arduino GLCD screen before drawing anything.

#### Syntax

```
screen.begin()

```

#### Parameters
none

#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino LCD library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background white
  screen.background(255,255,255);
}

void loop() {

}

```

### `point()`

#### Description

Draws a point at the given coordinates. The first parameter is the horizontal value for the point, the second value is the vertical value for the point.

#### Syntax

```
screen.point(xPos, yPos);

```

#### Parameters
xPos : int, the horizontal position of the point
yPos : int, the vertical position of the point
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.fill(255,255,255);

  // draw a pixel in the screen's center
  screen.point(screen.width()/2, screen.height()/2);
}

void loop() {

}

```

### `line()`

#### Description

Draws a line between two points. Use stroke() to change the color of something drawn with line().

#### Syntax

```
screen.line(xStart, yStart, xEnd, yEnd);

```

#### Parameters
xStart : int, the horizontal position where the line starts
yStart : int, the vertical position where the line starts
xEnd : int, the horizontal position where the line ends
yEnd : int, the vertical position where the line ends
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // draw a diagonal line across the screen's center
  screen.line(0, 0, 160, 124);
}

void loop() {

}

```

### `rect()`

#### Description

Draws a rectangle to the TFT screen. rect() takes 4 arguments, the first two are the top left corner of the shape, the last two are the width and height of the shape.

#### Syntax

```
screen.rect(xStart, yStart, width, height);

```

#### Parameters
xStart : int, the horizontal position where the line starts
yStart : int, the vertical position where the line starts
width : int, the width of the rectangle
height : int, the height of the rectangle
#### Returns
none

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // set the fill color to grey
  screen.fill(127,127,127);

  // draw a rectangle in the center of screen
  screen.rect(screen.width()/2-5, screen.height()/2-5, 10, 10);
}

void loop() {

}

```

### `width()`

#### Description

Reports the width of the TFT screen in pixels.

#### Syntax

```
screen.width();

```

#### Parameters
none

#### Returns
int : the width of the screen in pixels

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // set the fill color to grey
  screen.fill(127,127,127);

  // draw a rectangle in the center of screen
  screen.line(screen.width()/2-5, screen.height()/2-5, 10, 10);
}

void loop() {

}

```

### `height()`

#### Description

Reports the height of the TFT screen in pixels.

#### Syntax

```
screen.height();

```

#### Parameters
none

#### Returns
int : the height of the screen in pixels

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // set the fill color to grey
  screen.fill(127,127,127);

  // draw a rectangle in the center of screen
  screen.line(screen.width()/2-5, screen.height()/2-5, 10, 10);
}

void loop() {

}

```

### `circle()`

#### Description

Draws a circle on the screen.

The circle is drawn relative to its center point, which means the total diameter will always be an odd number.

#### Syntax

```
screen.circle(xPos, yPos, radius);

```

#### Parameters
xPos : int, the location of the center of the circle on the x axis
yPos : int, the location of the center of the circle on the y axis
radius : int, the radius of the circle
#### Returns
int : the width of the screen in pixels

#### Example

```
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);

void setup() {
  // initialize the screen
  screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // set the fill color to grey
  screen.fill(127,127,127);

  // draw a circle in the center of screen
  screen.circle(screen.width()/2, screen.height()/2, 10);
}

void loop() {

}

```

### `image()`

#### Description

Draws an image from the SD card to the screen at a specified location.

#### Syntax

```
screen.image(image, xPos, yPos);

```

#### Parameters
image : a named instance of PImage.
xPos : int, location on the x-axis to start drawing
yPos : int, location on the y-axis to start drawing
#### Returns
none

#### Example

```
// this example looks for a file named "logo.bmp"
//  on the SD card, and renders it to the screen
#include <Esplora.h>
#include <SPI.h>
#include <SD.h>
#include <TFT.h>            // Arduino TFT library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

void setup() {
  // initialize the screen
  EsploraTFT.begin();
  // initialize the SD card
  SD.begin(SD_CS);
  // set the background the black
  EsploraTFT.background(0, 0, 0);

  // load the image into the named instance of PImage
  logo = EsploraTFT.loadImage("arduino.bmp");

  // if it is a valid image file, turn the Esplora's LED green
   if (logo.isValid()) {
       Esplora.writeGreen(255);
  }
  else{
  // if it is not valid, turn the LED red
    Esplora.writeRed(255);
  }

  // draw the image on the screen starting at the top left corner
  EsploraTFT.image(logo, 0, 0);

}

void loop() {

}

```

### `loadImage()`

#### Description

Loads an image file from the SD card into a named instance of PImage. The TFT library has the ability to read .bmp files off the root of a SD card and display them on the screen. Images can be smaller or larger than the screen resolution (160x128), but there is no method on the Arduino for image manipulation. The images should be sized before you put them on the SD card. The TFT library has the ability to read .bmp files off the root of a SD card and display them on the screenIt is possible to load 24 bit bmp image only.

#### Syntax

```
screen.loadImage(name);

```

#### Parameters
name : char array, the name of the image from the SD card you wish to read
#### Returns
The loaded image

#### Example

```
// this example looks for a file named "logo.bmp"
//  on the SD card, and renders it to the screen
#include <Esplora.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

void setup() {
  // initialize the screen
  EsploraTFT.begin();
  // initialize the SD card
  SD.begin(SD_CS);
  // set the background the black
  EsploraTFT.background(0, 0, 0);

  // load the image into the named instance of PImage
  logo = EsploraTFT.loadImage("arduino.bmp");

  // if it is a valid image file, turn the Esplora's LED green
   if (logo.isValid()) {
       Esplora.writeGreen(255);
  }
  else{
  // if it is not valid, turn the LED red
    Esplora.writeRed(255);
  }

  // draw the image on the screen starting at the top left corner
  EsploraTFT.image(logo, 0, 0);

}

void loop() {

}

```

### `PImage`

#### Description
The base class for drawing a bitmap image from the SD card onscreen. You must include the SD library to use PImage.

#### Syntax

```
PImage image;

```

#### Parameters
image : the name of the PImage object. You'll refer to this when drawing images on screen.

#### Returns
none

#### Example

```
// this example looks for a file named "logo.bmp"
//  on the SD card, and renders it to the screen
#include <Esplora.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

void setup() {
  // initialize the screen
  EsploraTFT.begin();
  // initialize the SD card
  SD.begin(SD_CS);
  // set the background the black
  EsploraTFT.background(0, 0, 0);

  // load the image into the named instance of PImage
  logo = EsploraTFT.loadImage("arduino.bmp");

  // if it is a valid image file, turn the Esplora's LED green
   if (logo.isValid()) {
       Esplora.writeGreen(255);
  }
  else{
  // if it is not valid, turn the LED red
    Esplora.writeRed(255);
  }

  // draw the image on the screen starting at the top left corner
  EsploraTFT.image(logo, 0, 0);

}

void loop() {

}

```

### `PImage.height()`

#### Description

Checks the height of the PImage object.

#### Syntax

```
image.height();

```

#### Parameters
none

#### Returns
int : the image's height in pixels

#### Example

```
// this example looks for a file named "logo.bmp"
//  on the SD card, and renders it to the screen
#include <Esplora.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

void setup() {
  // initialize the screen
  EsploraTFT.begin();
  // initialize the SD card
  SD.begin(SD_CS);
  // set the background the black
  EsploraTFT.background(0, 0, 0);

  // load the image into the named instance of PImage
  logo = EsploraTFT.loadImage("arduino.bmp");

  // if it is a valid image file, turn the Esplora's LED green
   if (logo.isValid()) {
       Esplora.writeGreen(255);
  }
  else{
  // if it is not valid, turn the LED red
    Esplora.writeRed(255);
  }


}

void loop() {
  // randomly draw the image on screen
  int x = random(EsploraTFT.width() - logo.width());
  int y = random(EsploraTFT.height() - logo.height());
  EsploraTFT.image(logo, x, y);
  delay(1500);

}

```

### `PImage.width()`

#### Description

Checks the width of the PImage object.

#### Syntax

```
image.width();

```

#### Parameters
none

#### Returns
int : the image's width in pixels

#### Example

```
// this example looks for a file named "logo.bmp"
//  on the SD card, and renders it to the screen
#include <Esplora.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

void setup() {
  // initialize the screen
  EsploraTFT.begin();
  // initialize the SD card
  SD.begin(SD_CS);
  // set the background the black
  EsploraTFT.background(0, 0, 0);

  // load the image into the named instance of PImage
  logo = EsploraTFT.loadImage("arduino.bmp");

  // if it is a valid image file, turn the Esplora's LED green
   if (logo.isValid()) {
       Esplora.writeGreen(255);
  }
  else{
  // if it is not valid, turn the LED red
    Esplora.writeRed(255);
  }


}

void loop() {
  // randomly draw the image on screen
  int x = random(EsploraTFT.width() - logo.width());
  int y = random(EsploraTFT.height() - logo.height());
  EsploraTFT.image(logo, x, y);
  delay(1500);

}

```

### `PImage.isValid()`

#### Description

Checks if a named instance of PImage references a valid bitmap file.

#### Syntax

```
image.isValid();

```

#### Parameters
none

#### Returns
boolean

#### Example

```
// this example looks for a file named "logo.bmp"
//  on the SD card, and renders it to the screen
#include <Esplora.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define SD_CS    8  // Chip select line for SD card in Esplora

PImage logo;

void setup() {
  // initialize the screen
  EsploraTFT.begin();
  // initialize the SD card
  SD.begin(SD_CS);
  // set the background the black
  EsploraTFT.background(0, 0, 0);

  // load the image into the named instance of PImage
  logo = EsploraTFT.loadImage("arduino.bmp");

  // if it is a valid image file, turn the Esplora's LED green
   if (logo.isValid()) {
       Esplora.writeGreen(255);
  }
  else{
  // if it is not valid, turn the LED red
    Esplora.writeRed(255);
  }

  // draw the image on the screen starting at the top left corner
  EsploraTFT.image(logo, 0, 0);

}

void loop() {

}

```