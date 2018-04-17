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

// Test

#define TRESHOLD 100

// Callibration

int callibration[][3] = {
	{0, 0, 0}, // ORANGE
	{0, 0, 0}, // BLACK
	{0, 0, 0}, // GREEN
	{0, 0, 0}, // YELLOW
	{0, 0, 0}, // BLUE
};

// Setup

void setup(){
	pinMode(RED_LED_IN, INPUT);
	pinMode(GREEN_LED_IN, INPUT);
	pinMode(BLUE_LED_IN, INPUT);

	pinMode(PHOTO_TRANSISTOR_OUT, OUTPUT);

	Serial.begin(9600);

	randomSeed(analogRead(0));
}

int color = 0;

// Loop

void loop(){
	if (Serial.available() > 0) {
		color = Serial.parseInt();
	}

	float output = 0;
	
	int red = digitalRead(RED_LED_IN);
	int green = digitalRead(GREEN_LED_IN);
	int blue = digitalRead(BLUE_LED_IN);

	
}

