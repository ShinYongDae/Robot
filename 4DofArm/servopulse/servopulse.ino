int servopin = A0;							            // Define digital interface A0 to connect servo steering gear signal line
int myangle;								                // Define angle variables
int pulsewidth;								              // Define pulse width variables

void setup()
{
	pinMode(servopin, OUTPUT);				        // Set steering gear interface as Output
}

void servopulse(int servopin, int myangle)	// Define Function
{
	pulsewidth = (myangle * 11) + 500;		      // Converts the Angle to a pulse width value of 500 - 2480
	digitalWrite(servopin, HIGH);			        // The steering gear interface level is high
	delayMicroseconds(pulsewidth);			      // The microsecond number of the delay pulse width value
	digitalWrite(servopin, LOW);			        // Turn the steering gear interface level to low
	delay(20 - pulsewidth / 1000);
}

void loop()
{
	servopulse(servopin, 80);				          // Set steering gear Angle
	delay(3000);
	servopulse(servopin, 0);				          // Set steering gear Angle
	delay(3000);
}

// 0 Degree code:
//					servopulse(servopin, 0);
// 80 Degree code:
//					servopulse(servopin, 80);
// 180 Degree code:
//					servopulse(servopin, 180);
