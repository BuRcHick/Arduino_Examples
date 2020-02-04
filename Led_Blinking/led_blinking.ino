#define LED	13	//Led on 13th pin

void setup(){
	pinMode(LED, OUTPUT);	//Configure LED as GPIO output
}

void loop(){
	digitalWrite(LED, HIGH);  //Set at the LED HIGH level
	delay(1000);		  //Wait 1 second
	digitalWrite(LED, LOW);	  //Set at the LED LOW level
	delay(1000);	          //Wait 1 second
}
