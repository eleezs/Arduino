#define latchPin 5
#define clockPin 6
#define dataPin 4

const char common = 'c';
bool decPt = true;

void setup() {
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);  
Serial.begin(9600);
}

void loop() {
  decPt = !decPt
for (int i= 0; i<=8; i++){
  byte bits = numToBits(i);
if (decPt)(
bits = bits | B00000001;
  )

}
}
byte numToBits(int th){
switch (th)
  {
    case 0:
    return B11111100;
    break;
    case 1:
    return B01100000;
    break;
    case 2:
    return B11011010;
    break;
    case 3:
    return B11110010;
    break;
    case 4:
    return B01100110;
    break;
    case 5:
    return B10110110;
    break;
    case 6:
    return B10111110;
    break;
    case 7:
    return B11100000;
    break;
    case 8:
    return B11111110;
    break;
    case 9:
    return B11110110;
    break;
  }
}
