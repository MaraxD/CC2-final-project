/*
read from all the pins at the same time..?
DDRA=0;
uint8_t data=PINA;
*/

const int sensorPin=2;
int digitalPins[6]={2, 3, 4, 5, 6, 7}; // will always be 6 pins -> buttons
void setup() {
  // initialize all the pins
  //pinMode(2,INPUT_PULLUP);
  for(int i=0;i<6;i++){
    pinMode(digitalPins[i],INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  bool isBtnActive=false; //not needed ?
  String finalMessage;
  int sensorValue;

  //Serial.println(digitalRead(2));

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

  Serial.print(finalMessage);
  Serial.print('\n');
  delay(100);
}
