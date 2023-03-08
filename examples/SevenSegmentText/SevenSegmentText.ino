/*
  DonutStudioSevenSegment.h - Library for controlling a seven-segment-display with n digits.
  Created by Donut Studio, March 08, 2023.
  Released into the public domain.
*/

// include the libraray
#include "DonutStudioSevenSegment.h"

// define the ground pins
int gnd[] = { 10, 11, 12, 13 };

// create an object of the SegmentController class and define the segment, ground pins and display length.
SegmentController disp = SegmentController(2, 3, 4, 5, 6, 7, 8, 9, gnd, 4);

void setup() 
{
  // initialize the display (common anode) with a refresh time of 2 and brightness of 175
  disp.initialize(true, 2, 175);
  // set the speed of the text scroll effect
  disp.setTextUpdate(200);
  // display a text at the display
  disp.setText("Hey, I'm a cool person!");
}

void loop() 
{
  // refresh the display to display the text
  disp.refresh();
}