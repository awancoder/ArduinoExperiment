int sensorValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(0); // read analog input pin 0
  Serial.print("Air Quality: ");
  Serial.print(sensorValue, DEC);  // prints the value read
  Serial.println(" ppm");
  delay(1000);
}
