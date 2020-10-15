#include<SoftwareSerial.h>
SoftwareSerial BT(10,11);   //TX and RX to display on Serial Monitor
String cmd;

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
while(BT.available())
{
  delay(10);
  char c=BT.read();
  cmd+=c;
}
if(cmd.length()>0)
{
//  Serial.print("The given command is: ");
//Serial.println(cmd);

if(cmd=="turn on light one" || cmd=="turn on light 1" || cmd=="turn on light one." || cmd=="Turn on light one." || cmd=="switch on light one")
{
digitalWrite(13,HIGH);
if(digitalRead(13)==1 && digitalRead(7)==1)
Serial.println("BOTH LIGHTS ARE SWITCHED ON");
else if(digitalRead(13)==1)
Serial.println("LIGHT-1 IS ON");
else if(digitalRead(7)==1)
Serial.println("LIGHT-2 IS ON");
else
Serial.println("BOTH LIGHTS ARE SWITCHED OFF");
}
else if(cmd=="turn off light one" || cmd=="turn off light 1" || cmd=="Turn off flight 1" || cmd=="turn off flight one" || cmd=="turn off light one" || cmd=="Turn off light one")
{
  digitalWrite(13,LOW);
  if(digitalRead(13)==1 && digitalRead(7)==1)
  Serial.println("BOTH LIGHTS ARE SWITCHED ON");
  else if(digitalRead(13)==1)
  Serial.println("LIGHT-1 IS ON");
  else if(digitalRead(7)==1)
  Serial.println("LIGHT-2 IS ON");
  else
  Serial.println("BOTH LIGHTS ARE SWITCHED OFF");
  
}

else if(cmd=="turn on light two" || cmd=="turn on light 2" || cmd=="turn on light two." || cmd=="Turn on light two." ||cmd=="Turn on light 2." || cmd=="turn on light to")
{
  digitalWrite(7,HIGH);
  if(digitalRead(13)==1 && digitalRead(7)==1)
  Serial.println("BOTH LIGHTS ARE SWITCHED ON");
  else if(digitalRead(13)==1)
  Serial.println("LIGHT-1 IS ON");
  else if(digitalRead(7)==1)
  Serial.println("LIGHT-2 IS ON");
  else
  Serial.println("BOTH LIGHTS ARE SWITCHED OFF");
}

else if(cmd=="Turn off light two" || cmd=="turn off light 2" || cmd=="Turn off flight 2" || cmd=="turn off flight two" || cmd=="turn off light two" || cmd=="turn off light two" || cmd=="turn off light to"|| cmd=="turn off light Tu")
{
  digitalWrite(7,LOW);
  if(digitalRead(13)==1 && digitalRead(7)==1)
  Serial.println("BOTH LIGHTS ARE SWITCHED ON");
  else if(digitalRead(13)==1)
  Serial.println("LIGHT-1 IS ON");
  else if(digitalRead(7)==1)
  Serial.println("LIGHT-2 IS ON");
  else
  Serial.println("BOTH LIGHTS ARE SWITCHED OFF");
}

else if(cmd=="Turn on all lights" || cmd=="turn on all lights" || cmd=="switch on all lights" || cmd=="turn on all light")
{
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  if(digitalRead(13)==1 && digitalRead(7)==1)
  Serial.println("BOTH LIGHTS ARE SWITCHED ON");
  else if(digitalRead(13)==1)
  Serial.println("LIGHT-1 IS ON");
  else if(digitalRead(7)==1)
  Serial.println("LIGHT-2 IS ON");
  else
  Serial.println("BOTH LIGHTS ARE SWITCHED OFF");
}

else if(cmd=="Turn off all lights" || cmd=="turn off all lights" || cmd=="switch off all lights")
{
  digitalWrite(13,LOW);
  digitalWrite(7,LOW);
  if(digitalRead(13)==1 && digitalRead(7)==1)
  Serial.println("BOTH LIGHTS ARE SWITCHED ON");
  else if(digitalRead(13)==1)
  Serial.println("LIGHT-1 IS ON");
  else if(digitalRead(7)==1)
  Serial.println("LIGHT-2 IS ON");
  else
  Serial.println("BOTH LIGHTS ARE SWITCHED OFF");
}

else if(cmd=="make lights blink")
{
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  digitalWrite(7,LOW);
  delay(1000);
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  digitalWrite(7,LOW);
  delay(1000);
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  digitalWrite(7,LOW);
}

cmd="";
}
}
