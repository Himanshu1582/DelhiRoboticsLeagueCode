#include<Servo.h>
Servo first;
Servo second;
int pos1=90;
int pos2=90;
int motorA1=12;
int motorA2=11;
int motorB1 = 9; // Pin 10 of L293
int motorB2 = 8; // Pin 14 of L293

char state = '0';  // Initialise Motors

void setup() { 
Serial.begin(9600); 
first.attach(4);
second.attach(5);
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);  
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
} 

void loop() { 

if(Serial.available()>0){ // Reads from bluetooth and stores its value
state = Serial.read();
}
if(state=='F'){ // Forward
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
 

}
if(state=='B'){ // Reverse
    Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}
if(state=='R'){ // Right
    Serial.println(state);
  
    if(pos1<=179)
    {
      pos1 = pos1+1;
      first.write(pos1); 
    }
    if(pos2 >=1)
    {
      pos2 = pos2-1;
      second.write(pos2);
    }
  Serial.println(pos1);
    Serial.println(pos2);
}
if(state=='L'){ // Left
    Serial.println(state);
  
    if(pos1>=91)
    {
      pos1 = pos1-1;
      first.write(pos1); 
    }
    if(pos2 <=89)
    {
      pos2 = pos2+1;
      second.write(pos2);
    }
      Serial.println(pos1);
        Serial.println(pos2);

} 
if(state=='S'){ // Stop
    Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW); 

}


}
