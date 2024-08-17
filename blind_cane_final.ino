  #include <Servo.h>

Servo myServo;
int delay1;
float distance;
float time;
int servoPin = 9;
const int triggerPIN = 10;
const int echoPIN = 11;
void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
  myServo.attach(servoPin);  // Attach the servo to pin 9
 pinMode(triggerPIN,OUTPUT);
 pinMode(echoPIN,INPUT);
}

void loop() {
  digitalWrite(triggerPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPIN,LOW);
  delayMicroseconds(2);

  time = pulseIn(echoPIN,HIGH);
  distance = 0.01715 * time;
  if(distance<=50){
  delay1 = map(distance, 0, 50, 100, 1000);  // Map distance to delay value

      myServo.write(0);  // Move the servo to 0 degrees
      delay(delay1);  // Wait for the mapped delay time

      myServo.write(90);  // Move the servo to 90 degrees
      delay(delay1);  // Wait for the mapped delay time

      myServo.write(180);  // Move the servo to 180 degrees
      delay(1000);  }
      else{pinMode(9,LOW);}
      Serial.println(distance);
}