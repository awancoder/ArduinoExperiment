const int ldrPin = A0;
const int ldrPin2 = A1;

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  int ldrStatus2 = analogRead(ldrPin2);
 
  Serial.print("LDR 1: ");
  Serial.println(ldrStatus);
  Serial.print("LDR 2: ");
  Serial.println(ldrStatus2);  
  delay(250); 
}
