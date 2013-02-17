
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int green  = 8;
const int red  = 7;
const int gameTime = 4; // change this to decide game time
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int p1 = 0;
int p2 = 0;
int bVal = 0;
void setup() {
  // initialize the LED pin as an output:
  if (buttonPin == HIGH){
     bVal = 1; 
  }
  else{
    bVal = 0;
  }
  pinMode(ledPin, OUTPUT); 
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);   
  pinMode(red, HIGH);
  pinMode(green, HIGH);   
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  Serial.begin(9600);
}
void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  while(digitalRead(buttonPin) == 1) {     
    digitalWrite(ledPin, HIGH);
    p1up();
  if (p1 >= gameTime){
     }  
  } 
  while(digitalRead(buttonPin) == 0){
     digitalWrite(ledPin, LOW);
     p2up(); 
     if (p2 >= gameTime){
       gameOver("Player Two");
     }
  }
  if (p1 >= gameTime){
    digitalWrite(ledPin, LOW); 
    Serial.print("player one is out of time!");
  }
  else if (p2 >= gameTime){
    digitalWrite(ledPin, LOW); 
    Serial.print("player two is out of time!");
    while (1){
      Serial.print("Game Over!");
      delay(3000);
    }

  }
}

void p1up(){
   p1 += 1;
  delay(1000);
  Serial.print("player 1 has: ");
  int tmp = 100 - p1;
  Serial.print(tmp);
  Serial.println(" seconds left");
  return;
}
void p2up(){
  p2 += 1;
  delay(1000);
  Serial.print("player 2 has: ");
  int tmp = 100 - p2;
  Serial.print(tmp);
  Serial.println(" seconds left");
  return;
}
void gameOver(String p){
    digitalWrite(ledPin, HIGH); 
    Serial.println();
    Serial.print("player ");
    Serial.print(p);
    Serial.println(" is out of time!");
    while (1){
      Serial.println("Game Over!");
      lightParty();
  }
}


void lightParty(){
 for(int i = 30; i < 400; i+= 20){
  pinMode(ledPin, HIGH);  
  delay(400 - i);
  pinMode(ledPin, LOW);  
  delay(400 - i);
  pinMode(ledPin, HIGH);  
  delay(400 - i);
 }  
}
