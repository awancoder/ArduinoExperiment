#include <SPI.h>
#include <Ethernet.h>

String txData="";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,99);
EthernetClient client;

void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; //wait for serial port to connect. Needed for Leonardo only
  }
  Ethernet.begin(mac, ip);
  delay(1000);
  Serial.println("connecting...");
}

void loop()
{
  kirim ();
}


void kirim (){
  EthernetClient client;
  if (client.connect("192.168.1.111", 80)){ 
    Serial.println("connected");
    client.print( "GET /airena/sensor/tambahdata/");
    client.print(4);
    client.print("/");
    client.print(5);
    client.print("/");
    client.print(6);
    client.print("/");
    client.print(7);
    client.println();
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    delay (1000);
  }else{
    Serial.println("Connection Failed.");  
    Serial.println();
    delay (1000);
  }
}
