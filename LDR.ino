/*Program for Laser Light Security System
 * Ring buzzer when someone crosses the laser 
 * ~~~ R. S. Electronics ~~~
 * https://www.youtube.com/channel/UC_Jm37Vgb58krva8AG1ByMg
 */

 // Define
int ldr;
int led = 13, buzzer = 10;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  ldr = analogRead(A0);         // reading input from LDR
  Serial.println(ldr);
  if(ldr < 600)             //someone blocks the laser light
  {
    Serial.println("Someone crosses the laser");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(10000);               // turn ON the LED and ring the BUZZER for 10 seconds
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }  
  delay(100);               // repeat the process with gap of 100 miliseconds
}
