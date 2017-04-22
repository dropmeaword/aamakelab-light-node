int calibrationTime = 3;
int pirPin = D2;    //the digital pin connected to the PIR sensor's output

int event = 0;

int sampleRate = 100;
float waitms = 1000/sampleRate;

void init_pir(){
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

bool read_pir() {
    bool retval = false;
     if(digitalRead(pirPin) == HIGH) {
      retval = true;
     } else {
      retval = false;
     }

     return retval;
}

