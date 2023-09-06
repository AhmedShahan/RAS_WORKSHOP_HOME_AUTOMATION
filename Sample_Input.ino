int LDR=A0;

void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(9600);

}

void loop() {
  int value= analogRead(LDR);
  Serial.println(value);
}
