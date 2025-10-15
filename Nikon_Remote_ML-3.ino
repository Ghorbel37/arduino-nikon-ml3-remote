#define IR_LED_PIN 3

void setup() {
  pinMode(IR_LED_PIN, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
    pinMode(2, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor

  doTheSequence();
}

void doTheSequence() {
  doTheBurst(76);
  delay(27);
  delayMicroseconds(810);
  doTheBurst(16);
  delayMicroseconds(1540);
  doTheBurst(16);
  delayMicroseconds(3545);
  doTheBurst(16);
}

void doTheBurst(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(IR_LED_PIN, HIGH);
    delayMicroseconds(7);
    digitalWrite(IR_LED_PIN, LOW);
    delayMicroseconds(7);
  }
}

void loop() {
  if (digitalRead(2) == LOW) { // Check if button is pressed
    Serial.println("Button pressed. Sending IR signal...");
    doTheSequence();
    delay(50);}
}