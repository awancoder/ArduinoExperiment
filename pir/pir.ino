int ledPin = 13;                                           // Memilih pin indikator LED
int inputPin = 2;                                         // Memilih input PIR Sensor
int pirState = LOW;                                 // Pada saat mulai, Matikan sensor
int val = 0;                                               // Variable pembaca status pin
void setup() {
  pinMode(ledPin, OUTPUT);                // jadikan LED sebagai Output
  pinMode(inputPin, INPUT);               // jadikan Sensor sebagai Input
  Serial.begin(9600);
}
void loop(){
  val = digitalRead(inputPin);
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(150);
  
    if (pirState == LOW) {
      Serial.println("Terdeteksi suatu pergerakan!");
      pirState = HIGH;
    }
  } else {
      digitalWrite(ledPin, LOW);
      delay(300);   
      if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}

