// Define the analog pin connected to the TMP36 sensor
const int sensorPin = A0;

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the raw analog value from the sensor (0 to 1023)
  int rawValue = analogRead(sensorPin);
  
  // Convert the raw reading to voltage (0V - 5V)
  float voltage = rawValue * (5.0 / 1023.0);
  
  // Convert voltage to temperature in Celsius
  // TMP36 has a 500mV offset and 10mV per degree C scale
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  // Print the results to the Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Temp: ");
  Serial.print(temperatureC);
  Serial.print(" °C | ");
  Serial.print(temperatureF);
  Serial.println(" °F");
  
  // Wait 1 second before the next reading
  delay(1000);
}
