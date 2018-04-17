/* 
This is simple sketch that simulates RGB LED and photo transistor. 
*/

void setup(){
	pinMode(13, OUTPUT);
}

void loop(){
	digitalWrite(13, HIGH);
	delay(1000); // Wait for 1000 millisecond(s)
	digitalWrite(13, LOW);
	delay(1000); // Wait for 1000 millisecond(s)
}
