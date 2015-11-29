/*
Copyleft 2015 Paul Cambra Brwon.

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

#include <math.h>
#include "Arduino.h"
#include "Wire.h"
#include "MC14051B.h"

MC14051B::MC14051B(int controlPin, int ABCPin[3], int X)
{
    int i;
    
    pinMode(controlPin, OUTPUT);
    
    for (i=0; i<3 ; i++)
    {
        pinMode(ABCPin[i], OUTPUT);
        _ABC[i]=ABCPin[i];
    }
    _control=controlPin;
    _X=X;
}

int MC14051B::mcAnalogRead(char pin)
{
    int result;
    
    pinMode(_X, INPUT);
    
    setABCPin(pin);
    result=analogRead(_X);
    return(result);
}


void MC14051B::mcAnalogWrite(char pin, int value)
{
    pinMode(_X, OUTPUT);
    
    setABCPin(pin);
    analogWrite(_X, value);
}


void MC14051B::setABCPin(char pin)
{
    int i;
    
    for (i=0; i<3; i++)
    {
        digitalWrite(_ABC[i], pin%2);
        pin=pin/2;
    }
}


void MC14051B::reset()
{
    digitalWrite(_control, HIGH);
    delay(10);
    digitalWrite(_control, LOW);
}


MC14051B::~MC14051B()
{
    digitalWrite(_control, HIGH);
}
