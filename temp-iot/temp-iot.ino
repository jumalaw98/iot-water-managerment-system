#include <Servo.h>  // Include the Servo library

const int temperaturePin = A0;  // Analog pin for temperature sensor
const int motorPin = 9;        // Digital pin for motor control

// Temperature thresholds
const int lowTemperature = 150;  // Low temperature threshold in degrees Celsius
const int highTemperature = 98; // High temperature threshold in degrees Celsius

Servo servo;  // Create a Servo object

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Configure motor pin as an output
  pinMode(motorPin, OUTPUT);

  // Attach the servo to the motor pin
  servo.attach(motorPin);
}

void loop() {
  // Read the temperature from the sensor
  int temperature = readTemperature();

  // Print the temperature for debugging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Check if the temperature is below the low threshold
  if (temperature < lowTemperature) {
    // Move the servo to a specific position (e.g., fully clockwise)
    servo.write(0);  // Adjust the value (0-180) according to your servo's range
  }
  // Check if the temperature is above the high threshold
  else if (temperature > highTemperature) {
    // Move the servo to a specific position (e.g., fully counterclockwise)
    servo.write(180);  // Adjust the value (0-180) according to your servo's range
  }

  // Add a delay to avoid rapid motor switching
  delay(500);
}

// Function to read the temperature from the sensor
int readTemperature() {
  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(temperaturePin);

  // Convert the analog value to temperature in degrees Celsius
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert the analog value to voltage
  float temperature = (voltage - 0.5) * 100.0;   // Calculate temperature based on sensor characteristics

  
  return int(temperature);
}

