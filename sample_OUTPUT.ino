
// Version 1
// void setup() {
//   pinMode(13, OUTPUT);
// }

// void loop() {
//   digitalWrite(13,HIGH);
//   delay(1000);
//   digitalWrite(13,HIGH);
//   delay(1000);

// }



/// Version 2

int LED=13; 
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,HIGH);
  delay(1000);
}
