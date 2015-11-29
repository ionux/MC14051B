/*
Copyleft 2015 Paul Cambra Brown.

This program is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of
the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see http://www.gnu.org/licenses/.
*/

#ifndef MC14051B_h
#define MC14051B_h

#include "Arduino.h"

class MC14051B
{
  public:
      MC14051B(int controlPin, int ABCPin[2], int X);
      ~MC14051B();
      void reset();
      int mcAnalogRead(char pin);
      void mcAnalogWrite(char pin, int value);
    
  private:
      int _ABC[3];      //The pins on the Arduino that decide what port you read from or write to
      int _X;           //The pin on th Arduino you're going to read through
      int _control;     //The pin on the Arduino that sends the LOW (activate) or HIGH (de-activate) signal to the MC14051B
      void setABCPin(char pin);
};

#endif


