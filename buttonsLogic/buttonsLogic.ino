String finalMessage;
int sensorValue;

int digitalPins[6]={2, 3, 4, 5, 6, 7}; // will always be 6 pins -> buttons
void setup() {
  // initialize all the pins
  for(int i=0;i<6;i++){
    pinMode(digitalPins[i],INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  finalMessage="";
  sensorValue=0;

  // reading from all the pins at the same time
  for(int i=0;i<6;i++){
    sensorValue=digitalRead(digitalPins[i]);

    // uncomment to debug
    // Serial.print("Button "); Serial.print(i);
    // Serial.print(": "); Serial.println(sensorValue);
    
    if(sensorValue==LOW){
      // button is pressed
      finalMessage+=true;
    }else{
      finalMessage+=false;
    }

    if(i<5){
      finalMessage+=",";
    }
  }

  // send msg to touchdesigner
  Serial.print(finalMessage);
  Serial.print('\n');
  delay(100);
}
