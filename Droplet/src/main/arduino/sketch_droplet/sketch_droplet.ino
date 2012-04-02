/*******************************************************************************
 * Project: Droplet - Toolkit for Liquid Art Photographers
 * Copyright (C) 2012 Stefan Brenner
 *
 * This file is part of Droplet.
 *
 * Droplet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Droplet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Droplet. If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/


#include "logging.h"
#include "protocol.h"
#include "droplet.h"

#define BOUD_RATE         9600
#define MAX_INPUT_SIZE    50   // how many memory can we use one the different arduino devices?


                                   //  1  2  3  4  5  6  7  8  9  10  11  12, 13
char deviceMapping[DEVICE_NUMBERS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };


/*
 * setup stuff befor we start our main loop
 */
void setup() {
  // start serial communication
  Serial.begin(BOUD_RATE);
 
  // setup pin modes
  for(int i = 0; i < DEVICE_NUMBERS; i++) {
    pinMode(deviceMapping[i], OUTPUT);
  } 
  
}

 
/*
 * entry point
 */
void loop() {
  // nothing to do here
}



char input[MAX_INPUT_SIZE];
int count = 0;

void serialEvent() {
  while (Serial.available()) {
    
    // get the new byte
    char inChar = (char) Serial.read(); 
    
    //Serial.println("New char: " + String(inChar));
    
    // TODO brenner: consume input byte by byte
    
    if (inChar == '\n') {
      
      input[count] = '\0';
      
      logging(DEBUG, input);
      
      // TODO process byte by byte to prevent serial buffer overflow
      
      processCommand(input);
      
      count = 0;
      
      // TODO send received message next can come
      
    } else {
      
      // add it to the inputString:
      input[count] = inChar;
      count++;
      
    }
     
  }
}


