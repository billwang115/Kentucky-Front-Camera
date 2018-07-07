#include <math.h>
#include <SPI.h>

// Declaring pins
const int trigPin = 9;
const int echoPin = 8;
const int buzzer = 7;
const int redLed = 6;

int inputPin=11;
int pirState = LOW;   
int motionVal = 0;
long duration;
int distance = 21;
int previousAnswer = -99; 

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(inputPin, INPUT);     
  pinMode(redLed,OUTPUT);
  pinMode(buzzer, OUTPUT); 
}

void loop() 
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (round(distance/50.0)<=1 ){
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Watch out");
      tone(buzzer, 2000, 100);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=2){
    if(previousAnswer != round(distance/50.0)){
        Serial.println("Object is within 1 m");
        tone(buzzer, 1800, 200);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=3){
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Object is within 1.5 m");
      tone(buzzer, 1600, 300);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=4){
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Object is within 2 m");
      tone(buzzer, 1400, 400);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=5){
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Object is within 2.5 m");
      tone(buzzer, 1200, 500);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=6){
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Object is within 3 m");
      tone(buzzer, 1000, 600);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=7){
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Object is within 3.5 m");
      tone(buzzer, 800, 700);
    }
    previousAnswer = round(distance/50.0);
  }
  else if(round (distance/50.0)<=8){    
    if(previousAnswer != round(distance/50.0)){
      Serial.println("Object is within 4 m");
      tone(buzzer, 600, 1000);
    }
    previousAnswer = round(distance/50.0);
  }
  
  motionVal = digitalRead(inputPin); 
  
  if (motionVal==HIGH){
    if (pirState == LOW){
      Serial.println("Person ahead"); 
      pirState = HIGH;
      digitalWrite(redLed, HIGH);
      tone(buzzer,261,500);
      tone(buzzer,261,500);
      tone(buzzer,329,500);
    }
  }
  else{
    if (pirState == HIGH){
      Serial.println("Person has stopped");
      pirState = LOW;  
    }
  }               
  digitalWrite(redLed, LOW);
  delay(100);
}
