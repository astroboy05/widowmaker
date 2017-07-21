// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
int gun=13;
// Variables for the duration and the distance
long duration;
int distance;
int pirPin=8;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(gun,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(38400);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}
void loop() {
 // int pass;
 // while(Serial.available());
  //pass=Serial.read()-'0';
 // if(pass==1234){
  
  // rotates the servo motor from 15 to 165 degrees
  for(int i=5;i<=175;i++){ 
     distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    digitalWrite(gun,LOW);
     if(distance<=10){
      digitalWrite(gun,HIGH);
      i--;
      continue; 
     }
  myServo.write(i);
  delay(35);
  //distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=175;i>=5;i--){  
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
     digitalWrite(gun,LOW); 
     if(distance<=10){
      digitalWrite(gun,HIGH);
      i++;
      continue; 
     }
  myServo.write(i);
  delay(35);
 // distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  //}
}
//else 
//{
  //Serial.println(" auto pilot terminated");
  //while (Serial.available());
//}
 
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
