// cskm public school
// robo car
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int motorA1 = 9; // Pin  2 of L293
int motorA2 = 10; // Pin  7 of L293
int motorB1 = 11; // Pin 10 of L293
int motorB2 = 12; // Pin 14 of L293
char state = '0';  // Initialise Motors

void setup() { 
Serial.begin(9600); // Initialize serial communication at 9600 bits per second
   // Set pins as outputs
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
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 

}
if(state=='B'){ // Reverse
    Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}
if(state=='R'){ // Right
    Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);  
}
if(state=='L'){ // Left
    Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 
} 
if(state=='S'){ // Stop
    Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW); 

}


}
