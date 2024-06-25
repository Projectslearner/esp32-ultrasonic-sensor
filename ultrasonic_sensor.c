/*
   Project name: ESP32 Ultrasonic Sensor
   Modified Date: 25-06-2024
   Code by: Projectslearner
   Website: https://projectslearner.com/learn/esp32-ultrasonic-sensor
*/

// Define the GPIO pins connected to the ultrasonic sensor
const int trigPin = 13; // GPIO pin connected to the TRIG pin of the ultrasonic sensor
const int echoPin = 12; // GPIO pin connected to the ECHO pin of the ultrasonic sensor

// Speed of sound in air in cm/s (340 m/s)
const float speedOfSound = 340.0; 

void setup() {
  Serial.begin(9600); // Initialize serial communication

  pinMode(trigPin, OUTPUT); // TRIG pin as output
  pinMode(echoPin, INPUT); // ECHO pin as input
}

void loop() {
  long duration;
  float distance;

  // Generate a short pulse to TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of ECHO pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = (duration / 2.0) * (speedOfSound / 10000.0); 

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait before next measurement
}
