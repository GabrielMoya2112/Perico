// Blind and vision impared device assistance written by Gabriel Moya

// Define constants
const int pinTrigger = 2;
const int pinEcho = 3;
const int pinVibrator = 13;

float time = 0;
float distance = 0;

void setup()
{
  // Setup pins 
  pinMode(pinTrigger, OUTPUT);  // Trigger is Output
  pinMode(pinEcho, INPUT);    // Echo receives a signal
  pinMode(pinVibrator, OUTPUT); // Vibrator is Output
  pinMode(LED_BUILTIN, OUTPUT); // Internal LED
  Serial.begin(9600);     // Init monitor @ 9600 bauds
}

void loop()
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(4);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  
  // Distance measure code
  time = pulseIn(pinEcho, HIGH);    // Feed echo the pong time in ms
  distance = 0.01715 * time;       // Formula to calculate distance
  Serial.println("Distancia (cm)");   
  Serial.println(distance);
  
  if (distance >= 400)
  {
    // Ignore distances of 4 meters (400 cm) or more
    digitalWrite(pinVibrator, LOW); // No vibration
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (distance <= 35)
  {
    // Formula-based vibration logic for distances up to 35 cm
    delay(distance * 10);
    digitalWrite(pinVibrator, HIGH);
    delay(distance * 10);
    digitalWrite(pinVibrator, LOW);
  }
  else if (distance <= 55)
  {
    // Heartbeat patterns: these mimic a heartbeat. This is heartbeat at 55 cm
    digitalWrite(pinVibrator, HIGH);
    delay(25); // 25 ms on
    digitalWrite(pinVibrator, LOW);
    delay(12); // 12 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(25); // 25 ms on
    digitalWrite(pinVibrator, LOW);
    delay(250); // 250 ms off
  }
  else if (distance <= 75)
  {
    // Heartbeat pattern at 75 cm
    digitalWrite(pinVibrator, HIGH);
    delay(30); // 30 ms on
    digitalWrite(pinVibrator, LOW);
    delay(15); // 15 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(30); // 30 ms on
    digitalWrite(pinVibrator, LOW);
    delay(300); // 300 ms off
  }
  else if (distance <= 95)
  {
    // Heartbeat pattern at 95 cm
    digitalWrite(pinVibrator, HIGH);
    delay(35); // 35 ms on
    digitalWrite(pinVibrator, LOW);
    delay(17); // 17 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(35); // 35 ms on
    digitalWrite(pinVibrator, LOW);
    delay(350); // 350 ms off
  }
  else if (distance <= 115)
  {
    // Heartbeat pattern at 115 cm
    digitalWrite(pinVibrator, HIGH);
    delay(40); // 40 ms on
    digitalWrite(pinVibrator, LOW);
    delay(20); // 20 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(40); // 40 ms on
    digitalWrite(pinVibrator, LOW);
    delay(400); // 400 ms off
  }
  else if (distance <= 135)
  {
    // Heartbeat pattern at 135 cm
    digitalWrite(pinVibrator, HIGH);
    delay(45); // 45 ms on
    digitalWrite(pinVibrator, LOW);
    delay(22); // 22 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(45); // 45 ms on
    digitalWrite(pinVibrator, LOW);
    delay(450); // 450 ms off
  }
  else if (distance <= 155)
  {
    // Heartbeat pattern at 155 cm
    digitalWrite(pinVibrator, HIGH);
    delay(50); // 50 ms on
    digitalWrite(pinVibrator, LOW);
    delay(25); // 25 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(50); // 50 ms on
    digitalWrite(pinVibrator, LOW);
    delay(500); // 500 ms off
  }
  else if (distance <= 175)
  {
    // Heartbeat pattern at 175 cm
    digitalWrite(pinVibrator, HIGH);
    delay(55); // 55 ms on
    digitalWrite(pinVibrator, LOW);
    delay(27); // 27 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(55); // 55 ms on
    digitalWrite(pinVibrator, LOW);
    delay(550); // 550 ms off
  }
  else if (distance <= 195)
  {
    // Heartbeat pattern at 195 cm
    digitalWrite(pinVibrator, HIGH);
    delay(60); // 60 ms on
    digitalWrite(pinVibrator, LOW);
    delay(30); // 30 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(60); // 60 ms on
    digitalWrite(pinVibrator, LOW);
    delay(600); // 600 ms off
  }
  else if (distance <= 215)
  {
    // Heartbeat pattern at 215 cm
    digitalWrite(pinVibrator, HIGH);
    delay(65); // 65 ms on
    digitalWrite(pinVibrator, LOW);
    delay(32); // 32 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(65); // 65 ms on
    digitalWrite(pinVibrator, LOW);
    delay(650); // 650 ms off
  }
  else if (distance <= 235)
  {
    // Heartbeat pattern at 235 cm
    digitalWrite(pinVibrator, HIGH);
    delay(70); // 70 ms on
    digitalWrite(pinVibrator, LOW);
    delay(35); // 35 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(70); // 70 ms on
    digitalWrite(pinVibrator, LOW);
    delay(700); // 700 ms off
  }
  else if (distance <= 255)
  {
    // Heartbeat pattern at 255 cm
    digitalWrite(pinVibrator, HIGH);
    delay(75); // 75 ms on
    digitalWrite(pinVibrator, LOW);
    delay(37); // 37 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(75); // 75 ms on
    digitalWrite(pinVibrator, LOW);
    delay(750); // 750 ms off
  }
  else if (distance <= 275)
  {
    // Heartbeat pattern at 275 cm
    digitalWrite(pinVibrator, HIGH);
    delay(80); // 80 ms on
    digitalWrite(pinVibrator, LOW);
    delay(40); // 40 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(80); // 80 ms on
    digitalWrite(pinVibrator, LOW);
    delay(800); // 800 ms off
 }
  else if (distance <= 295)
  {
    // Heartbeat pattern at 295 cm
    digitalWrite(pinVibrator, HIGH);
    delay(85); // 85 ms on
    digitalWrite(pinVibrator, LOW);
    delay(42); // 42 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(85); // 85 ms on
    digitalWrite(pinVibrator, LOW);
    delay(850); // 850 ms off
  }
  else if (distance <= 300)
  {
    // Heartbeat pattern at 300 cm
    digitalWrite(pinVibrator, HIGH);
    delay(90); // 90 ms on
    digitalWrite(pinVibrator, LOW);
    delay(45); // 45 ms off
    digitalWrite(pinVibrator, HIGH);
    delay(90); // 90 ms on
    digitalWrite(pinVibrator, LOW);
    delay(900); // 900 ms off
  }
  else if (distance <= 400)
  {
    // Steady vibration pattern for distances between 300 cm and 400 cm
    int vibrationDuration = 700 + (distance - 300) * 5;
    digitalWrite(pinVibrator, HIGH);
    delay(vibrationDuration);
    digitalWrite(pinVibrator, LOW);
    delay(vibrationDuration);
  }
}
