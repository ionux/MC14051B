# The MC14051B Arduino Library

## Introduction

The [M14051b](http://www.onsemi.com/pub_link/Collateral/MC14051B-D.PDF) is a popular and cheap anlogue multiplexer that can be used to add 8 more analogue ports to your Arduino.

However, writing reading and writing to the MC14051B's ports makes sketches long and tedious, hence this dirver.

## Modules

### MC14051B(int controlPin, int ABCPin[2], int X);

The constructor takes 3 parameters:

1. `controlPin` the Arduino's pin number you connect to the MC14051B's inhibitor.



      void reset();
      int mcAnalogRead(char pin);
      void mcAnalogWrite(char pin, int value);