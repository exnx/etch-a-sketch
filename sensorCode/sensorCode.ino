//TODO: define other sensor inputs
#define SENSORPIN0 A0 // x axis
#define SENSORPIN1 A1 // x axis
#define BUTTONPIN 2
#define FSR A2  // force sensing resistor

  // potentiometer code
int sensorValue0 = 0;  // variable to store the value coming from the sensor
int outputValue0 = 0;

int sensorValue1 = 0;  // variable to store the value coming from the sensor
int outputValue1 = 0;

// FSR code
int fsrValue3 = 0;
int fsrSensorValue3 = 0;
int fsrOutputValue3 = 0;

//const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

String x_pos = "";
String y_pos = "";
String new_pos = "";

unsigned long targetTime=0;
const unsigned long interval=100; //TODO: How fast should we read


void setup(){
// TODO: begin the serial connection with a baudrate of 115200
  Serial.begin(115200);

  // initialize the pushbutton pin as an input:
  pinMode(BUTTONPIN, INPUT);

  // initialize potentiometer 
  pinMode(SENSORPIN0, INPUT);
  pinMode(SENSORPIN1, INPUT); 

  // initialize FSR
  pinMode(FSR, INPUT);
}


void loop(){

  buttonState = digitalRead(BUTTONPIN);
  fsrSensorValue3 = analogRead(FSR);
  fsrOutputValue3 = map(fsrSensorValue3,0,1023,0,20);

//  Serial.println(fsrSensorValue3);

	if(millis()>=targetTime){
		targetTime= millis()+interval;

       // check if the pushbutton is pressed. If it is, the buttonState is LOW, the reset
      if (buttonState == LOW) {
        Serial.println("rst\r\n");
      }

      if (fsrOutputValue3 > 3) {
//        Serial.println(fsrOutputValue3);
        Serial.println("colorChange\r\n");
      }

      sensorValue0 = analogRead(SENSORPIN0); // read value
      outputValue0 = map(sensorValue0, 0, 1023, 0, 500);  // map values

      sensorValue1 = analogRead(SENSORPIN1); // read value
      outputValue1 = map(sensorValue1, 0, 1023, 0, 500);  // map values

      x_pos = String(outputValue0);
      y_pos = String(outputValue1);
      new_pos = x_pos + "," + y_pos;

      Serial.println(new_pos);
    
		 //TODO: Add other sensor read outs
     //TODO: convert values into a string https://www.arduino.cc/en/Tutorial/StringConstructors
		 //TODO: combine them into a string that can be understood by server.js
		 //TODO: send the string over serial


	}
	// TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
  // TODO: write the reset message(see server.js) to the serial port

}
