long duration, cm, inches;
 
void setup() {
  Serial.begin (9600);
  pinMode(9,OUTPUT);
}
 
void loop()
{
 
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delayMicroseconds(5);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
 
  // Read the signal from the sensor:
  pinMode(11, INPUT);
  duration = pulseIn(11, HIGH);
  Serial.println(duration);
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  if(inches > 57){      //tank size 5 feet = 60 inch,
    digitalWrite(9, HIGH);  // start if 57 inch empty
  }else if(inches < 5)    // stop if 5 inch to fill
    digitalWrite(9, LOW);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
