#include "Arduino.h"
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
    pinMode(_X, INPUT);
    
    setABCPin(pin);
    return(analogRead(_X));
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
