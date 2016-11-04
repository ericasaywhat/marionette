int sensorOneValue= 0;

const int sens_oneIn = A0;



void setup() {
  Serial.begin(9600);
}


void loop() {
  sensorOneValue = analogRead(sens_oneIn);
  if(sensorOneValue > 230) {
    Serial.println("Hello there!");
    Serial.println(sensorOneValue);
  }
}
