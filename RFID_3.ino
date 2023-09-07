#define SS_PIN 16  //D0
#define RST_PIN 5 //D1
#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance/object.

int LED=0;//D3
int LASER=2;//D4
int LDR=A0;


void setup() 
{
  pinMode(LED,OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(LASER,OUTPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}
void loop() 
{
  // Look for new cards
  if ( mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  {
      String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  String rfid=content.substring(1);
  Serial.println(rfid);
  Serial.println("LED OFF, LASER OFF");
  digitalWrite(LED,LOW);
  digitalWrite(LASER,LOW);
  delay (5000);
  }
  else{
    // Serial.println("There is no RFID");
    int value=analogRead(LDR);
    Serial.println(value);
    digitalWrite(LASER,HIGH);
    // digitalWrite(LED,HIGH);

    Serial.println("Laser HIGH");
    if (value<1024)
    {
    digitalWrite(LED,HIGH);
    }
    else
    {
    digitalWrite(LED,LOW);

    }
  }
}