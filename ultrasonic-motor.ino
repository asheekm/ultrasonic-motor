void setup() {
  
  Serial.begin(9600);
  
  // initialize pin for motors as outputs
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  // initialize pins for ultrasonic sensor
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  
}



// the loop function runs over and over again forever
void loop() {
  
  //For Ultrasonic sensor
  long dur_pulse, dist;
  
  //sending out pulse
  digitalWrite(3, LOW); //set low
  delayMicroseconds(1); //wait for 1 microsecond
  digitalWrite(3, HIGH); //sending out pulse
  delayMicroseconds(10); //wait for 10 microseconds
  digitalWrite(3, LOW); //set low

  //reading pulse
  dur_pulse = pulseIn(2, HIGH);
  dist = (dur_pulse*0.034)/2;
  Serial.println(dist, DEC); 


  
  //For Motor Motion
  if (dist > 10 && dist < 25){
    
    analogWrite(13, 0);
    delay(2);
    
    analogWrite(12, 150);
    delay(500);

  }
  
  else if (dist <= 10){
    
    analogWrite(12, 0);
    delay(2);
    
    analogWrite(13, 150);
    delay(500);
    
  }

  else if (dist > 25){
    
    analogWrite(13, 0);
    delay(5);
    
    analogWrite(12, 0);
    delay(5);
    
  }

}
