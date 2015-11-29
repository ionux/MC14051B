# The MC14051B Arduino Library

## Introduction

The [M14051b](http://www.onsemi.com/pub_link/Collateral/MC14051B-D.PDF) is a popular and cheap anlogue multiplexer that can be used to add 8 more analogue ports to your Arduino.

However, writing reading and writing to the MC14051B's ports makes sketches long and tedious, hence this driver.

## Modules

### MC14051B(int controlPin, int ABCPin[3], int X)

The constructor takes 3 parameters:

1. `controlPin` the Arduino's pin number you connect to the MC14051B's inhibitor.
2. `ABCPin` is three item array that contains the Arduino pin numbers for MC14051B's A, B, & C ports.
3. `X` is the Arduino analogue pin connected to the MC14051B X (I/O) pin.

### mcAnalogRead(char pin)

Returns the analogue input from one of the MC14051B's ports. You set which port you want to read from with the `pin` parameter shown above, where `0` reads from port `X0`, `1` reads from port `X1`, `2` reads from port `X2`, and so on.

### mcAnalogWrite(char pin, int value)

Is the same as `mcAnalogRead()` shown above, except that it pushes a number (`value`) to the MC14051B `pin`you want to write to.

### reset()

Resets the MC14051B.      

## Example

This example reads in values from an analogue sensor connected to the MC14051B port 3:

### With the library

```
#include <MC14051B.h>
#include "Wire.h"

int ABCpins[] = {8, 9, 10};
MC14051B expander(7, ABCpins, A0);

void setup ()
{
  Serial.begin(9600);
}

void loop ()
{
  Serial.println(expander.mcAnalogRead(3));
  expander.reset();
}
```

### Without the library

```
#include "Wire.h"

int controlPin=7;
int A=8;
int B=9;
int C=10;
int X=A0;

void setup ()
{

  pinMode(controlPin, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(X, INPUT);
  
  Serial.begin(9600);
}

void loop ()
{
  digitalWrite(A, 1);
  digitalWrite(B, 1);
  digitalWrite(C, 0);

  Serial.println(analogRead(X));
  
  reset();
}


void reset()
{
  digitalWrite(controlPin, HIGH);
  delay(10);
  digitalWrite(controlPin, LOW);
}
```