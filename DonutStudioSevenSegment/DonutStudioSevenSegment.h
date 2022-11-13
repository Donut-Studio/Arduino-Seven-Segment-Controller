/*
  DonutStudioSevenSegment.h - Library for controlling a seven-segment-display with n digits.
  Created by Donut Studio, November 13, 2022.
  Released into the public domain.
*/

/*
--- seven segment display ---

       D4        D3       D2        D1        

        A
       ---
    |       |
  F |       | B
    |       |
       -G-
    |       |
  E |       | C
    |       |
       ---
        D   - 
            dp
*/



#ifndef DonutStudioSevenSegment.h
#define DonutStudioSevenSegment.h

#ifndef MAXDIGITS
#define MAXDIGITS 8
#endif

#include "Arduino.h"

class SegmentController
{
  public:
    /*
      --- CONSTRUCTOR ---
    */

    // constructor of the class in which you set all the pins for the display
    SegmentController(int a, int b, int c, int d, int e, int f, int g, int dp, int gnd[], int length);

    /*
      --- METHODS ---
    */

    // initialize the display with the pin type, refresh time and brightness
    void initialize(bool _commonAnode, unsigned long _refreshTime = 2, byte _brightness = 175);

    // refresh the currently displayed byte
    void refreshDisplay();

    // set an byte value to display
    void setByte(byte d[]);
    // set an integer value to display
    void setInt(int number, bool showLeadZeros = false);
    // set an float value to display
    void setFloat(float number);

    // enable/disable blinking on one digit
    void setBlinkDigit(int _digit, bool _value);
    // enable/disable blinking on all digits
    void setBlinkAll(bool _value);
    // enable/disable one digit
    void setDigit(int _digit, bool _value);
    // enable/disable all digits
    void setDigitAll(bool _value);
    // reset blinking and deactivated digits
    void resetEffects();

  private:
    /*
      --- METHODS ---
    */

    // set the segments according to a byte
    void setSegments(byte digit);
    // update the brightness according to the pin type
    void updateBrightness();
    
    // get the length of the segments
    int getSegmentLength();
    // check if an integer number is able to display
    bool NumberInRange(int _number);
    // check if an float number is able to display
    bool NumberInRange(float _number);

    /*
      --- VARIABLES ---
    */

    // type of the display: common cathode-0, command anode-1
    int commonPinType = 0;
    // time (in milliseconds) to refresh the display
    unsigned long refreshTime = 2;
    // brightness of the display max=255
    byte brightness = 200;
    // time (in milliseconds) of blinking digits
    int blinkInterval = 250;

    // pins for the segments: a, b, c, d, e, f, g, dp
    int segmentPins[8];
    // is a pin for the decimal point given?
    bool hasDP = true;
    // the length of the display
    int displayLength = 4;
    // ground pins for the digits
    int gndPins[MAXDIGITS];
    // the byte which is currently displayed
    byte currentDisplayByte[MAXDIGITS];

    // all digits from 0-9 and off
    byte digits[11] = { B00111111, B00000110, B01011011, B01001111, B01100110, B01101101, B01111101, B00000111, B01111111, B01101111, B00000000 };

    // the minus symbol
    byte minus = B01000000;
    // the dot symbol
    byte dot = B10000000;

    // array of the digits that blink
    bool blinkDigit[MAXDIGITS];
    // array of the digits that are disabled
    bool enabledDigit[MAXDIGITS];
};
#endif