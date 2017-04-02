#include <Servo.h> 
Servo myservo;
int pos = 0;            
void setup() 
{
  myservo.attach(9);
}
void loop() 
{
  
// // start dari 0 derajar sampai 180 derajat 
// for(pos = 0; pos < 180; pos += 1)  
// {
//  // pada posisi 1 derajat
//  // memberitahu servo untuk pergi ke posisi  'pos'
//  myservo.write(pos);
//  // tunggu 15ms untuk pencapaian  posisi servo    
//  delay(15);                  
// }
// 
// // start dari 180 derajat ke 0 derajat 
// for(pos = 180; pos>=1; pos-=1)  
// {
//  // memberitahu servo untuk pergi ke posisi  'pos'                                
//  myservo.write(pos);                 
//  // tunggu 15ms untuk pencapaian  posisi servo    
//  delay(15);                        
// }
myservo.write(15); 
}
