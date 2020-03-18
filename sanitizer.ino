#include <Servo.h>    //servo library
Servo servo;
int trigPin = 5;
int echoPin = 6;
int servoPin = 7;
long duration, dist, average;
long avg[3]; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);
  delay(100);
  servo.detach();

}


void measure(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) / 29.1;

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<=2; i++){
    measure();
    avg[i]=dist;
    delay(10);
  }
  dist = (avg[0]+avg[1]+avg[2])/3;

  if(dist<2 0){
    servo.attach(servoPin);
    delay(1);
    servo.write(0);
    delay(2000);
    servo.write(150);
    delay(1000);
    servo.detach();
  }
  Serial.print(dist);
}
