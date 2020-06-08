#include <RTClib.h>
#include <Wire.h> // for i2c between register and arduino
 
//define pins for register on arduino
const int dataPin = 4;  // blue wire to 74HC595 pin 14
const int latchPin = 5; // green to 74HC595 pin 12
const int clockPin = 6; // yellow to 74HC595 pin 11

byte segCode1(int th) {
  switch (th) {
    case 0:
      return B1111110;
      break;
    case 1:
      return B0110000;
      break;
    case 2:
      return B1101101;
      break;
    case 3:
      return B1111001;
      break;
    case 4:
      return B0110011;
      break;
    case 5:
      return B1011011;
      break;
    case 6:
      return B1011111;
      break;
    case 7:
      return B1110000;
      break;
    case 8:
      return B1111111;
      break;
    case 9:
      return B1111011;

  }
}

byte segCode2(int hun) {
  switch (hun) {
    case 0:
      return B1111110;
      break;
    case 1:
      return B0110000;
      break;
    case 2:
      return B1101101;
      break;
    case 3:
      return B1111001;
      break;
    case 4:
      return B0110011;
      break;
    case 5:
      return B1011011;
      break;
    case 6:
      return B1011111;
      break;
    case 7:
      return B1110000;
      break;
    case 8:
      return B1111111;
      break;
    case 9:
      return B1111011;

  }
}

byte segCode3(int t) {
  switch (t) {
    case 0:
      return B1111110;
      break;
    case 1:
      return B0110000;
      break;
    case 2:
      return B1101101;
      break;
    case 3:
      return B1111001;
      break;
    case 4:
      return B0110011;
      break;
    case 5:
      return B1011011;
      break;
    case 6:
      return B1011111;
      break;
    case 7:
      return B1110000;
      break;
    case 8:
      return B1111111;
      break;
    case 9:
      return B1111011;

  }
}

byte segCode4(int u) {
  switch (u) {
    case 0:
      return B1111110;
      break;
    case 1:
      return B0110000;
      break;
    case 2:
      return B1101101;
      break;
    case 3:
      return B1111001;
      break;
    case 4:
      return B0110011;
      break;
    case 5:
      return B1011011;
      break;
    case 6:
      return B1011111;
      break;
    case 7:
      return B1110000;
      break;
    case 8:
      return B1111111;
      break;
    case 9:
      return B1111011;

  }
}


//variables to store the converted/raw result taken from RTC
int h; //for hours
int m; //for minutes
int thousands;
int hundreds;
int tens;
int unit;

//7 seg pins to arduino
int thous_d4 =8;
int hun_d3 = 7;
int tens_d2 = 13;
int unit_d1 = 12;


RTC_DS1307 rtc;

void setup() {
Serial.begin(57600); 
Wire.begin(); //begin 12c communication
pinMode(thous_d4, OUTPUT);
pinMode(hun_d3, OUTPUT);
pinMode(tens_d2, OUTPUT);
pinMode(unit_d1, OUTPUT);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
 
}

void loop() {
Serial.println();
DateTime now =rtc.now();
h = now.hour();
m = now.minute();
Serial.print(h);
Serial.print(":");
Serial.print(m);
//combining h and m gotten from rtc to numbers  
int number = h*100+m;
//Serial.print(number);

int thousands = number/1000%10;
int hundreds = number/100%10;
//Serial.print(hundreds);
int tens = number/10%10;
int unit = number%10;
int u = unit;
int t = tens;
int hun = hundreds;
int th = thousands;
//Serial.print(th);


digitalWrite(thous_d4, LOW);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin,LSBFIRST,segCode4(u));
shiftOut(dataPin, clockPin,LSBFIRST,segCode3(t));
shiftOut(dataPin, clockPin,LSBFIRST,segCode2(hun));
shiftOut(dataPin, clockPin,LSBFIRST,segCode1(th));
digitalWrite(thous_d4, HIGH);
digitalWrite(hun_d3, HIGH);
digitalWrite(tens_d2, HIGH);
digitalWrite(unit_d1, HIGH);
digitalWrite(latchPin, HIGH); //this is sent cuz is used to update the output pins(store)
//Serial.print(thous_d4);
delay(1000);
}
