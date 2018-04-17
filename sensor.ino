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

void setup() { 
	Serial.begin(115200);

	rgbSensorInit(ANALOG_IN, RED_LED, GREEN_LED, BLUE_LED); // Init rgb sensor on A1
}

// Loop

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

	digitalWrite(redLed, 1);
	digitalWrite(blueLed, 0);
	digitalWrite(blueLed, 0);

	delay(DELAY);

	red = analogRead(analogIn);

	delay(DELAY);

	// GREEN

	digitalWrite(redLed, 0);
	digitalWrite(blueLed, 1);
	digitalWrite(blueLed, 0);

	delay(DELAY);

	green = analogRead(analogIn);

	delay(DELAY);

	// BLUE

	digitalWrite(redLed, 0);
	digitalWrite(blueLed, 0);
	digitalWrite(blueLed, 1);

	delay(DELAY);

	blue = analogRead(analogIn);

	delay(DELAY);

	// Turn all of, to save energy
	digitalWrite(redLed, 0);
	digitalWrite(blueLed, 0);
	digitalWrite(blueLed, 0);
}

void loop() {
	rgbSensorLoop(ANALOG_IN, RED_LED, GREEN_LED, BLUE_LED);
}

