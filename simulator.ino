/* 
This is simple sketch that simulates RGB LED and photo transistor. 
*/

// IO

#define RED_LED_IN D13
#define GREEN_LED_IN D12
#define BLUE_LED_IN D11

#define PHOTO_TRANSISTOR_OUT D7

// Colors

#define ORANGE 0
#define BLACK 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4

void setup(){
	pinMode(RED_LED_IN, INPUT);
	pinMode(GREEN_LED_IN, INPUT);
	pinMode(BLUE_LED_IN, INPUT);

	pinMode(PHOTO_TRANSISTOR_OUT, OUTPUT);

	Serial.begin(9600);

	randomSeed(analogRead(0));
}

void loop(){
}

