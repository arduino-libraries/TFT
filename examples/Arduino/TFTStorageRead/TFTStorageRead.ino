/*
  TFTStorageRead

  This example shows how to read  data  from an SD card file and prints it to the screen.

  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  TFT Screen attached to SPI bus as follows:
  cs  - pin 10
  dc  - pin 9
  rst - pin 8

  created by Abhijeet Kadam
  This example code is in the public domain.

*/

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8


#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#include <SD.h>

String fname;
int n = 0;
File root, myFile;
char str[100];// char array to print to the screen

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);

  // set the font color to white
  TFTscreen.stroke(255, 255, 255);
  // set the font size

  root = SD.open("/"); // create root reference.
  printDirectory(root, 0); // print directory and file list

  Serial.println("Enter file name to read file data:");//ask user for file name eg. test.txt
  waitip();
  fname = Serial.readString();
  fname.trim();

  if (SD.exists(fname)) { //if file already exists

    myFile = SD.open(fname);
    if (myFile) {
      Serial.println(" " + fname);
      // read from the file until there's nothing else in it:
      n = 0;
      while (myFile.available()) {
        str[n] = myFile.read();
        n++;
      }
      // close the file:
      myFile.close();
      TFTscreen.text(str, 0, 0);
    }
  }
  else { //if file not exists show the message
    Serial.println(fname + " doesn't exist.");
  }
}

void loop() {
}

void waitip()// wait for user input
{
  while (Serial.available() == 0)
  {}
}

void printDirectory(File dir, int numTabs) // prints directory list
{
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
