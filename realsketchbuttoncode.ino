const int SwOneVNAIN = 40;
const int SwOneNIN = 41;  

const int SwTwoVNAIN = 44;
const int SwTwoNIN = 46;
const int SwOneVNAO = 22;
const int SwOneNO = 24;
const int SwTwoVNAO = 26;
const int SwTwoNO = 28;
const int BackLED = 30;

int incomingByte;

bool StateVNA1 = false;
bool StateN1 = false;
bool StateVNA2 = false;
bool StateN2 = false;

unsigned long lastDebounceTimeV1 = 0;
unsigned long lastDebounceTimeN1 = 0;
unsigned long lastDebounceTimeV2 = 0;
unsigned long lastDebounceTimeN2 = 0;
unsigned long debounceDelay = 500; // Debounce delay in milliseconds


void setup() {
  Serial.begin(9600);
  pinMode(BackLED, OUTPUT); 
  pinMode(SwOneVNAIN, INPUT_PULLUP);
  pinMode(SwOneNIN, INPUT_PULLUP);
  pinMode(SwTwoVNAIN, INPUT_PULLUP); 
  pinMode(SwTwoNIN, INPUT_PULLUP); 
  pinMode(SwOneVNAO, OUTPUT);
  pinMode(SwOneNO, OUTPUT);
  pinMode(SwTwoVNAO, OUTPUT);
  pinMode(SwTwoNO, OUTPUT);

}

void loop() {
  
  digitalWrite(BackLED, HIGH);  //LED turns on when plugged into power
    
    
   if (digitalRead(SwOneVNAIN) == LOW){   //If buttons pressed
    if (digitalRead(SwOneNO) == LOW){     //Checks if other switch mode is pressed
  
      while(!digitalRead(SwOneVNAIN)){ //Debounce code
      }
      if (millis() - lastDebounceTimeV1 > debounceDelay){   //If current run minus the last run is greater than the debounce delay then it is table and the code can continue
        StateVNA1 = !StateVNA1;         //Switch state
        digitalWrite(SwOneVNAO, StateVNA1);       
        lastDebounceTimeV1 = millis();      //Have the time be saved for the next time
        Serial.println("VNA1");
      }
    }
  }
  
  if (digitalRead(SwOneNIN) == LOW){
    if (digitalRead(SwOneVNAO) == LOW){
    
    
      while(!digitalRead(SwOneNIN)){
      }
      if (millis() - lastDebounceTimeN1 > debounceDelay){
        StateN1 = !StateN1;
        digitalWrite(SwOneNO, StateN1);
        lastDebounceTimeN1 = millis();
        Serial.println("N1");
      }
    }
  }
  if (digitalRead(SwTwoVNAIN) == LOW){
    if (digitalRead(SwTwoNO) == LOW){
    
      while(!digitalRead(SwTwoVNAIN)){
      }
      if (millis() - lastDebounceTimeV2 > debounceDelay){
        StateVNA2 = !StateVNA2;
        digitalWrite(SwTwoVNAO, StateVNA2);
        lastDebounceTimeV2 = millis();
        Serial.println("VNA2");
      }
    }
  }
  
  if (digitalRead(SwTwoNIN) == LOW){
   
    if (digitalRead(SwTwoVNAO) == LOW){
    
    
      while(!digitalRead(SwTwoNIN)){
      }
      if (millis() - lastDebounceTimeN2 > debounceDelay){
        StateN2 = !StateN2;
        digitalWrite(SwTwoNO, StateN2);
        lastDebounceTimeN2 = millis();
        Serial.println("N2");
      }
    }
  }


//MatLAB commands
if (Serial.available() > 0) {
   
    incomingByte = Serial.read();
  
    if (digitalRead(SwOneNO) == LOW){
      if (incomingByte == 'A') {
        digitalWrite(SwOneVNAO, HIGH);
      }
      if (incomingByte == 'B') {
        digitalWrite(SwOneVNAO, LOW);
      }
    } 
    if (digitalRead(SwOneVNAO) == LOW){
      if (incomingByte == 'C') {
        digitalWrite(SwOneNO, HIGH);
      }
    
      if (incomingByte == 'D') {
        digitalWrite(SwOneNO, LOW);
      }
    }
    if (digitalRead(SwTwoNO) == LOW){
      if (incomingByte == 'E') {
        digitalWrite(SwTwoVNAO, HIGH);
      }
   
      if (incomingByte == 'F') {
        digitalWrite(SwTwoVNAO, LOW);
      }
    }
    if (digitalRead(SwTwoVNAO) == LOW){}
      if (incomingByte == 'G') {
        digitalWrite(SwTwoNO, HIGH);
      }
   
      if (incomingByte == 'H') {
        digitalWrite(SwTwoNO, LOW);
      }
    }


}


 
