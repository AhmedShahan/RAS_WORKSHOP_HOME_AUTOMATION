#define SS_PIN 4  //D2
#define RST_PIN 5 //D1
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance/object.

int LED=16;
int LDR=A0;


int variable = 0;
void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Show your card:");

}
void loop()
{
  int value=analogRead(LDR);

  if(value<1024)
{
  digitalWrite(LED,HIGH);
}

else
{
  digitalWrite(LED, LOW);
}
  // Look for new cards
if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }


//Show UID on serial monitor
Serial.println();
Serial.print(" UID tag :");
String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++) 
{
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
content.toUpperCase();
delay(1000);
}