int led = 13;
int buzzer = 8;

//ping
int trig= 11;            // membuat varibel trig yang di set ke-pin 3
int echo= 12;            // membuat variabel echo yang di set ke-pin 2 
long durasi, jarak;     // membuat variabel durasi dan jarak

//pir
int inputPin = 2;                                         // Memilih input PIR Sensor
int pirState = LOW;                                 // Pada saat mulai, Matikan sensor
int val = 0;   

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //led dan buzzer
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  //pir
  pinMode(inputPin, INPUT);
  //ping
  pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo, INPUT);     // set pin echo menjadi INPUT
  
}

void loop() {
  // put your main code here, to run repeatedly:

  val = digitalRead(inputPin);

  if (val == HIGH) {
    if (pirState == LOW) {
      Serial.println("Terdeteksi suatu pergerakan!");
      pirState = HIGH;

      digitalWrite(trig, LOW);
      delayMicroseconds(8);
      digitalWrite(trig, HIGH);
      delayMicroseconds(8);
      digitalWrite(trig, LOW);
      delayMicroseconds(8);
    
      durasi= pulseIn(echo, HIGH);  // menerima suara ultrasonic
      jarak= (durasi/2) / 29.1;     // mengubah durasi menjadi jarak (cm)
      Serial.println(jarak);        // menampilkan jarak pada Serial Monitor
      if(jarak > 30){
        digitalWrite(buzzer, HIGH);
      }else if(jarak > 10 && jarak < 30){
        digitalWrite(buzzer, HIGH);
        digitalWrite(led, HIGH);
      }else{
        digitalWrite(led, HIGH);
      }
      delay(2000);

      
    }
  } else {
      if (pirState == HIGH){
      Serial.println("Motion ended!");
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
      pirState = LOW;
    }
  }
}
