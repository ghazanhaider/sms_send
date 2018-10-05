void setup() {
  Serial.begin(115200); //initialize Serial(i.e. USB port)
  Serial1.begin(115200); //initialize Serial1
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
delay(10000);

Serial1.println("AT+CMGF=1"); // enable SMS
delay(400);
Serial1.println("AT+CMGS=\"+905XXXXXXX\""); // send to this number
delay(400);
Serial1.println("Hello World");
delay(400);
Serial1.write(0x1A); // end of SMS
digitalWrite(13,HIGH);
}

void loop() {
  //If Serial1 receive data, print out to Serial
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  //If Serial receive data, print out to Serial1
  while (Serial.available()) {
    Serial1.write(Serial.read());
  }
  delay(1);  //delay for a short time to
  // avoid unstable USB communication
}
