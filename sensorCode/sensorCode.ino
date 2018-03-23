#define SENSORPINA A0 // x axis
 //TODO: define other sensor inputs

#define BUTTONPIN 2

  // potentiometer code
int sensorPin0 = A0;    // select the input pin for the potentiometer
int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorPin1 = A1;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor

//const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status


unsigned long targetTime=0;
const unsigned long interval=100; //TODO: How fast should we read
void setup(){
// TODO: begin the serial connection with a baudrate of 115200
  Serial.begin(115200);

  // initialize the pushbutton pin as an input:
  pinMode(BUTTONPIN, INPUT);

  // initialize potentiometer 
  pinMode(sensorPin0, INPUT);
  pinMode(sensorPin1, INPUT); 
}


void loop(){

  buttonState = digitalRead(BUTTONPIN);

    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    
    Serial.println("not");
  }

  else {
    Serial.println("rst\r\n");
//    Serial.println("");
//    Serial.println("sending the reset message");
  }

  
	if(millis()>=targetTime){
		targetTime= millis()+interval;
		Serial.println(analogRead(SENSORPINA));

		 //TODO: Add other sensor read outs
     //TODO: convert values into a string https://www.arduino.cc/en/Tutorial/StringConstructors
		 //TODO: combine them into a string that can be understood by server.js
		 //TODO: send the string over serial


	}
	// TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
  // TODO: write the reset message(see server.js) to the serial port

}
