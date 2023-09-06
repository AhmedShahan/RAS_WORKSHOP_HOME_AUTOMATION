int LED=16;
int LDR=A0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value=analogRead(LDR);

  Serial.println(value);
  if(value==1024)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }
}
