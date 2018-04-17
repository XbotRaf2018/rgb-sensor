/*
This library is for detecting color of objectu using photo transistor and RGB LED.
*/

// Stuff for circuit simullation

#define DEBUG 1

#if DEBUG == 1
int currentPointer = 0;
#endif

// Color definitions

#define ORANGE 0
#define BLACK 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4

int colors[] = {ORANGE, BLACK, GREEN, YELLOW, BLUE};

int callibration[][3] = {
	{0, 0, 0}, // ORANGE
	{0, 0, 0}, // BLACK
	{0, 0, 0}, // GREEN
	{0, 0, 0}, // YELLOW
	{0, 0, 0}, // BLUE
};

char colorNames[][15] = {
	"ORANGE",
	"BLACK",
	"GREEN", 
	"YELLOW", 
	"BLUE"
};

// Leds (indicators for virtual sensor)

#define RED_LED A2
#define GREEN_LED A3
#define BLUE_LED A4

#define ANALOG_IN A1

// Sensor settings

#define DELAY 100
#define TRESHOLD 100

// Setup

void rgbSensorInit(int analogIn, int redLed, int greenLed, int blueLed) {
	pinMode(analogIn, INPUT);

	pinMode(redLed, OUTPUT);
	pinMode(blueLed, OUTPUT);
	pinMode(greenLed, OUTPUT);
}

#if DEBUG == 1
void setup() { 
	Serial.begin(115200);

	rgbSensorInit(ANALOG_IN, RED_LED, GREEN_LED, BLUE_LED); // Init rgb sensor on A1
}
#endif

// Loop

void setLedColor(bool red, int green, int blue, int redLed, int greenLed, blueLed){
	digitalWrite(redLed, red);
	digitalWrite(blueLed, green);
	digitalWrite(blueLed, blue);
}

void rgbSensorLoop(int analogIn, int redLed, int greenLed, int blueLed) {
	#if DEBUG == 1
		currentPointer++;
		currentPointer %= 5;

		Serial.println(colors[currentPointer]);
	#endif

	int red;
	int green;
	int blue;

	// RED

	setLedColor(1, 0, 0, redLed, greenLed, blueLed);

	delay(DELAY);

	red = analogRead(analogIn);

	delay(DELAY);

	// GREEN

	setLedColor(0, 1, 0, redLed, greenLed, blueLed);

	delay(DELAY);

	green = analogRead(analogIn);

	delay(DELAY);

	// BLUE

	setLedColor(0, 0, 1, redLed, greenLed, blueLed);

	delay(DELAY);

	blue = analogRead(analogIn);

	delay(DELAY);

	// Turn all of, to save energy
	setLedColor(0, 0, 0, redLed, greenLed, blueLed);
}

#if DEBUG == 1
void loop() {
	rgbSensorLoop(ANALOG_IN, RED_LED, GREEN_LED, BLUE_LED);
}
#endif

