#include <Arduino.h>

// Constants for humidity and tank sensor calibration
#define UMID_0 4095
#define UMID_100 1870
#define RANGE UMID_0-UMID_100

// Pin definitions
#define PIN_TERRENO 36         // Soil humidity sensor pin
#define PIN_SERBATOIO 15       // Water tank sensor pin
#define PIN_POMPA 16           // Water pump pin
#define PIN_LED_SERBATOIO 19   // LED for water tank status

// Function declarations
int checkTankStatus();                        // Check if water tank is full
int checkSoilHumidity(float targetHumidity);  // Check if soil humidity is below target
void wateringCycle(float targetHumidity);     // Start the watering process

void setup(){
  pinMode(PIN_POMPA, OUTPUT);               // Set pump pin as output
  pinMode(PIN_SERBATOIO, INPUT);            // Set water tank sensor pin as input
  pinMode(PIN_TERRENO, INPUT);              // Set soil humidity sensor pin as input
  pinMode(PIN_LED_SERBATOIO, OUTPUT);       // Set LED pin as output
}

void loop(){
  float targetHumidity = 0.5;  // Target humidity level (can be modified)

  // Check if water tank is empty and blink LED while waiting for refill
  while (!checkTankStatus()){
    digitalWrite(PIN_LED_SERBATOIO, HIGH);  // LED ON if tank is empty
    delay(5000);                            // Wait for 5 second
  }

  digitalWrite(PIN_LED_SERBATOIO, LOW);     // LED OFF when tank is refilled
  
  // If soil humidity is below target and water tank has enough water, start watering
  if (checkSoilHumidity(targetHumidity) && checkTankStatus()){
    wateringCycle(targetHumidity);          // Start watering cycle
  }

  delay(600000);  // Wait 10 minutes before the next loop iteration
}

// Function to check if the water tank is full
int checkTankStatus(){
  int signal = analogRead(PIN_SERBATOIO);  // Read the tank sensor value
  return (signal == 0) ? 1 : 0;            // Return 0 if tank is empty
}

// Function to check if soil moisture is below target
int checkSoilHumidity(float targetHumidity){
  int calculatedHumidity = UMID_0-(targetHumidity * RANGE);     // Calculate the target humidity value
  int soilHumidity = analogRead(PIN_TERRENO);                   // Read the soil humidity sensor value

  return (calculatedHumidity < soilHumidity) ? 1 : 0;           // Return 1 if tank is full or 0 if empty
}

// Function to water the plant
void wateringCycle(float targetHumidity){

  // Continue watering as long as soil humidity is below target and water tank is not empty
  while (checkSoilHumidity(targetHumidity) && checkTankStatus()){
    digitalWrite(PIN_POMPA, HIGH);  // Turn on the pump
  }

  digitalWrite(PIN_POMPA, LOW);  // Turn off the pump
}