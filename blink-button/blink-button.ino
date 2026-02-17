// Declare the pins:
const int ledPin = 12;
const int pushButton = 14;

void setup(){
  // Set the pin modes
  pinMode(ledPin, OUTPUT);

  // It is important that you set pushButton to INPUT_PULLDOWN
  // This is to avoid any undefined states
  pinMode(pushButton, INPUT_PULLDOWN);
}

void loop(){
  // Read value from the button and switch on light
  if(digitalRead(pushButton) == HIGH){
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
  }
}
