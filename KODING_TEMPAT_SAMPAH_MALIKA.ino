#include <Servo.h>
Servo myservo;
const int redled = 13;
const int greenled = 12;
const int irobspin = 2;
int obstacle = HIGH;
int angle=0;
int angleStop=50;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
pinMode(irobspin, INPUT);
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
obstacle = digitalRead(irobspin);
if (obstacle == LOW)
{
  myservo.write(270);
  digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
  Serial.println("Terdeteksi");
}
else
{
  myservo.write(0);
  digitalWrite(greenled, LOW);
  digitalWrite(redled, HIGH);
  Serial.println("Tidak Terdeteksi");
}
}
