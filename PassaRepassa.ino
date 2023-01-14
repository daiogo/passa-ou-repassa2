/*
  Diogo Freitas
*/

// constants won't change. They're used here to set pin numbers:
const int button1Pin = 25;    // the number of the pushbutton pin
const int button2Pin = 27;    // the number of the pushbutton pin
const int resetPin = 29;  // the number of the pushbutton pin
const int led1Pin = 47;   // the number of the LED pin
const int led2Pin = 43;   // the number of the LED pin
const int buzzerPin = 39;   // the number of the buzzer pin
const int freq = 1000;   // the number of the buzzer pin

// variables will change:
int player1State = 0;  // variable for reading the pushbutton status
int player2State = 0;  // variable for reading the pushbutton status
int resetState = 0;  // variable for reading the pushbutton status
int hold = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(resetPin, INPUT);
  noTone(buzzerPin);
}

void loop() {
  
  // read the state of the buttons
  player1State = !digitalRead(button1Pin);
  player2State = !digitalRead(button2Pin);
  resetState = digitalRead(resetPin);
  
  if (resetState) {
    player1State = 0;
    player2State = 0;
    resetState = 0;
    hold = 0;
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(buzzerPin, LOW);
    noTone(buzzerPin);
    
  } else if (player1State && !hold) {
    hold = 1;
    digitalWrite(led1Pin, HIGH);
    tone(buzzerPin, freq);
    
  } else if (player2State && !hold) {
    hold = 1;
    digitalWrite(led2Pin, HIGH);
    tone(buzzerPin, freq);
  }

  // For relay test
  // digitalWrite(led1Pin, HIGH);
  // delay(1000);
  // digitalWrite(led1Pin, LOW);
  // delay(1000);
  // digitalWrite(led2Pin, HIGH);
  // delay(1000);
  // digitalWrite(led2Pin, LOW);
  // delay(1000);
  
}