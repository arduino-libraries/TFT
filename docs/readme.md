# TFT LCD library

The TFT library is included with [Arduino IDE 1.0.5](https://www.arduino.cc/en/software) and later.

This library enables an Arduino board to communicate with the [Arduino TFT LCD screen](https://docs.arduino.cc/retired/other/arduino-lcd-screen). It simplifies the process for drawing shapes, lines, images, and text to the screen.

The Arduino TFT library extends the [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library), and [Adafruit ST7735](https://github.com/adafruit/Adafruit-ST7735-Library) libraries that it is based on. The GFX library is responsible for the drawing routines, while the ST7735 library is specific to the screen on the Arduino TFT. The Arduino specific additions were designed to work as similarly to the Processing API as possible.

Onboard the screen is a SD card slot, which can be used through the [SD library](https://www.arduino.cc/en/Reference/SD).

The TFT library relies on the [SPI library](https://www.arduino.cc/en/Reference/SPI) for communication with the screen and SD card, and needs to be included in all sketches.

To use this library:

```
#include <SPI.h>
#include <TFT.h>
```

## Using the Library

The screen can be configured for use in two ways. One is to use an Arduino's hardware SPI interface. The other is to declare all the pins manually. There is no difference in the functionality of the screen between the two methods, but using hardware SPI is significantly faster.

If you plan on using the SD card on the TFT module, you must use hardware SPI. All examples in the library are written for hardware SPI use.

If using hardware SPI with the Uno, you only need to declare the CS, DC, and RESET pins, as MOSI (pin 11) and SCLK (pin 13) are already defined.

```
#define CS   10
#define DC   9
#define RESET  8

TFT myScreen = TFT(CS, DC, RESET);
```

To use hardware SPI with the Leonardo, you declare the pins like so :

```
#define CS   7
#define DC   0
#define RESET  1

TFT myScreen = TFT(CS, DC, RESET);
```

When not using hardware SPI, you can use any available pins, but you must declare the MOSI and SCLK pins in addition to CD, DC, and RESET.

```
#define SCLK 4
#define MOSI 5
#define CS   6
#define DC   7
#define RESET 8

TFT myScreen = TFT(CS, DC, MOSI, SCLK, RESET);
```


## Using the Arduino Esplora and the TFT library

As the Arduino Esplora has a socket designed for the TFT, and the pins for using the screen are fixed, an Esplora only object is created when targeting sketches for that board. You can reference the screen attached to an Esplora through `EsploraTFT`.

## Similarities to Processing

[Processing](https://processing.org/) is an open source software environment used by designers, artists, and students. The main output of Processing is a graphic window on a computer or browser. The Arduino TFT library has made the calls for drawing primitives and text to the screen as "Processing-like" as possible to ensure a smooth transition between the two environments.

## Examples

You can find examples for this library (both Arduino and Esplora specific examples) at the [Examples from Libraries page](https://docs.arduino.cc/library-examples).