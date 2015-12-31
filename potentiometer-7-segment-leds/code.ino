/*

Potentiometer with 7 Segment LED and 3 individual LEDs

===== References =====
Funtions for display number in 7 Segment LED  -> By: Riley Porter

digitalWrite(A, LOW) = turn off the "A" segment in the LED display
digitalWrite(B, HIGH)  = turn on the "B" segment in the LED display

*/

#define A 12
#define B 13
#define C 4
#define D 5
#define E 6
#define G 7
#define H 8

void one()
{
  //Displays 1
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(H, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void two()
{
  //Displays 2
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void three()
{
  //Displays 3
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(H, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void four()
{
  //Displays 4
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void five()
{
  //Displays 5
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void six()
{
  //Displays 6
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void seven()
{
  //Displays 7
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(H, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void eight()
{
  //Displays 8
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void nine()
{
  //Displays 9
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void zero()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

int lBrightness = 0;
int lSpeed = 0;

void displayLeds(int brightness) {
  if(brightness != lBrightness) {
    int lPin = brightness/255 + 9;
    analogWrite(lPin, brightness % 255);
    if (lPin < 11)
      analogWrite(lPin + 1, 0);
    lBrightness = brightness;
  }
}

void displaySpeed(int speed) {
  if (speed != lSpeed) {
    switch(speed) {
      case 0:
        zero();
        break;
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
      case 10:
        nine();
        break;
      default:
        break;
    }
    lSpeed = speed;
  }
}

void setup()
{
  //Setup our pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600);  //Begin serial communcation
}

void loop()
{
  int sensorValue = analogRead(A0);
  //Serial.println(sensorValue);
  int brightness = map(sensorValue, 0, 1023, 0, 765);
  displayLeds(brightness);

  int speed = map(sensorValue, 0, 1023, 0, 10);
  displaySpeed(speed);
}



