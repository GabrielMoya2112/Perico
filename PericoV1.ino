// Blind and vision impared device assistance written by Gabriel Moya Written 2024-09-16 at 18:16

// Define constants
const int pinTrigger = 2;       // HC-SR04 pinTrigger programmed as pin 2 (digital)
const int pinEcho = 3;          // HC-SR04 pinEcho programmed as pin 3 (digital)
const int pinVibrator = 13;     // pinVibrator programmed as pin 13
float time = 0;
float distance = 0;

// Define distance thresholds in centimeters
const float close_Threshold = 30.0;         // Close range: <30 cm
const float medium_Threshold = 100.0;       // Medium range: 30-100 cm
const float long_Threshold = 200.0;         // Long range: 100-200 cm

void setup()                     // Setup pins
{                 
  pinMode(pinTrigger, OUTPUT);  // Trigger is Output
  pinMode(pinEcho, INPUT);      // Echo receives a signal
  pinMode(pinVibrator, OUTPUT); // Vibrator is Output
  pinMode(LED_BUILTIN, OUTPUT); // Internal LED
  Serial.begin(9600);          // Init monitor @ 9600 bauds
}

void loop()                   // Loop; continuous code
{
  // Trigger the sensor
  digitalWrite(pinTrigger, LOW);      
  delayMicroseconds(2);            // Send a 5V pulse at 40 KHz
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);          
  digitalWrite(pinTrigger, LOW);

  // Calculate distance
  time = pulseIn(pinEcho, HIGH);  // Feed echo the pong time in microseconds
  distance = 0.01715 * time;     // Formula to calculate distance. 343 m/s (speed of sound) divided by 2 is 171.5 m/s

  // Print distance to Serial Monitor
  Serial.print("Distancia (cm): ");
  Serial.println(distance);

  // Handle vibration feedback based on distance
  handleDistance(distance);

  // Delay 100 microseconds
  delay(100);
}

// Function to handle distance-based feedback. Three thresholds are defined here
void handleDistance(float distance) 
{
  if (distance < close_Threshold) 
  {
    // Very close range: Rapid vibration; imminent danger
    rapidVibration(100); // Vibrate rapidly, 100 is adjustable
  } 
  else if (distance >= close_Threshold && distance < medium_Threshold) 
  {
    // Medium range: Moderate feedback; Be aware
    pulseVibration(100, 200); // 100 ms pulse with 200 ms interval
  } 
  else if (distance >= medium_Threshold && distance < long_Threshold) 
  {
    // Long range: Slower feedback; No real danger
    pulseVibration(200, 400); // 200 ms pulse with 400 ms interval
  } 
  else 
  {
    // Beyond long range: No feedback
    digitalWrite(pinVibrator, LOW);  // Turn vibrator off. Effective distance is 4 meters.
  }
}

// Function for rapid vibration for very close range
void rapidVibration(unsigned int duration) 
{
  unsigned long start = millis();
  while (millis() - start < duration) 
  {
    digitalWrite(pinVibrator, HIGH);
    delay(50); // Short on-time
    digitalWrite(pinVibrator, LOW);
    delay(50); // Short off-time
  }
}

// Function for pulsed vibration
void pulseVibration(unsigned int onTime, unsigned int offTime) 
{
  digitalWrite(pinVibrator, HIGH);
  delay(onTime);  // Vibrate for onTime
  digitalWrite(pinVibrator, LOW);
  delay(offTime); // Delay for offTime
}
