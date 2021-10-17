#include<Servo.h>
   
int servopin1 =5 ;
int servopin2 = 3;
const int cpin = 2;
const int metal_pin = 12;
Servo servo1;
Servo servo2;
void setup() {
   Serial.begin(9600);// Starting Serial Terminal
   pinMode(cpin,INPUT);
   servo1.attach(servopin1);
   servo2.attach(servopin2);
}


int distance_1()
{  
  const int trigPin = 9;
  const int echoPin = 10;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration / 2) * 0.0343;
 return distance;
  }
long distance_2()
{  
  const int trigPin = 7;
  const int echoPin = 6;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) * 0.0343;
 return distance;
  }
int distance_3()
{
    const int trigPin = 13;
  const int echoPin =11;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) * 0.0343;
 return distance;
  
  
  }
void loop() {
 int on = digitalRead(cpin);
 if(on)
 {
 Serial.println("Waste detect Device turning on....");
 int is_metal = digitalRead(metal_pin);
  float moisture = analogRead(A0);
  if(is_metal)
  {
    Serial.println("The Waste has Metal");
    servo1.write(60);
    Serial.println("Moving to Metal Pin");
    servo2.write(180);
    int on = digitalRead(cpin);
    while(on){
      int on = digitalRead(cpin);
      if(on==0)
      {
        break;}
      delay(500);
      }
      Serial.println("Waste Dumped");
    Serial.println("Moving back to Original Position");
  delay(1000);
      servo2.write(0);
    
    
    
    }
  else if(moisture>200)
  { Serial.println("The Waste is Wet");
    servo1.write(120);
    Serial.println("Moving to Wet Bin");
    delay(1000);
    servo2.write(180);
    int on = digitalRead(cpin);
    while(on){
      
      int on = digitalRead(cpin);
        if(on==0)
      {
        break;}
      delay(500);
      }
      Serial.println("Waste Dumped");
    Serial.println("Moving back to Normal position");
  delay(1000);
      servo2.write(0);
    
    }else{
  Serial.println("The Waste is Dry");
    servo1.write(180);
    Serial.println("Moving to Dry Bin");
    delay(1000);
    servo2.write(180);
    int on = digitalRead(cpin);
    while(on){
      int on = digitalRead(cpin);
        if(on==0)
      {
        break;}
      delay(500);
      }
      Serial.println("Waste Dumped");
    Serial.println("Moving back to Normal position");
  delay(1000);
      servo2.write(0);
    
      
      }
  }
  
 
 
}
