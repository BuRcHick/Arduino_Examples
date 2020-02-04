#define BUFFER_SIZE 	0x100		//Size of the buffer
#define ANALOG_INPUT	A0		//Analog pin

static char s_buffer[BUFFER_SIZE] = {0};	//Buffer for output


void setup(){
	Serial.begin(115200);		//Set sretial port baud rate speed
}

void loop(){
	sprintf(s_buffer, "Value: %d", analogRead(ANALOG_INPUT));	//Read value from analog pin
	Serial.println(s_buffer);	//Write the buffer to the serial port
	delay(1000);	          	//Wait 1 second
}
