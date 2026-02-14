// Declare the led pins:
const int r = 23;
const int g = 22;
const int b = 21;

void setup(){
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
}

void loop(){
    // Flash Red, then Blue, then Green
    digitalWrite(r, HIGH);
    delay(300);
    digitalWrite(r, LOW);
    delay(300);

    digitalWrite(g, HIGH);
    delay(300);
    digitalWrite(g, LOW);
    delay(300);

    digitalWrite(b, HIGH);
    delay(300);
    digitalWrite(b, LOW);
    delay(300);
}