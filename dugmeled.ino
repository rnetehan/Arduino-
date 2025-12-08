// Pin tanımları
const int buttonPin = 2;     
const int ledPin  = 13;      
const int ledPin1 = 12; 
const int ledPin2 = 11;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(ledPin, OUTPUT);          
  pinMode(ledPin1, OUTPUT);  
    pinMode(ledPin2, OUTPUT);    
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {      
    digitalWrite(ledPin, HIGH);  
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  } 
  else {                          
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
  }
}
