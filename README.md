# Automatic Plant Watering System

This project uses an **ESP32** and **soil humidity sensors** to create an automated system that waters plants when the soil is dry. The system reads the humidity level in the soil and activates a water pump to irrigate the plant. It also checks the water tank level and ensures there is enough water before starting the irrigation.

## Technologies Used:
- **Platform**: ESP32
- **Programming Language**: C
- **Sensors**: Soil humidity sensor, water tank sensor
- **Actuators**: Water pump, LED indicator
- **Tools**: PlatformIO, VS Code, Arduino framework

## File Structure:
- `main.cpp`: The Arduino code for the ESP32, written in C.
- `circuit-diagram.png`: A diagram showing the wiring of the components.
- `README.md`: This file with project description and instructions.

## How to Set Up:
1. **Hardware Components**:
   - **ESP32** development board
   - **Soil humidity sensor**
   - **Water tank sensor**
   - **Water pump** 3.3V
   - **LED** (optional, to indicate the status of the water tank)
   - **Relay module** (to control the water pump)

2. **Wiring**:
   - Connect the **soil humidity sensor** to the designated pin (e.g., GPIO 36).
   - Connect the **water tank sensor** to the designated pin (e.g., GPIO 15).
   - Connect the **water pump** to the relay module and wire it to the ESP32 GPIO (e.g., GPIO 16).
   - Optionally, connect an **LED** to show the water tank status (GPIO 19).

   Check the `circuit-diagram.png` for a visual representation of the wiring.

3. **Software**:
   - Open the `main.cpp` file in PlatformIO.
   - Select the correct board and port in PlatformIO.
   - Upload the code to the ESP32.

4. **Adjusting Parameters**:
   - You can modify the target soil humidity level (`targetHumidity`) to suit your plant's needs. It is currently set to 0.5 (50% humidity).
   - Ensure your water tank is properly filled, as the system will not water the plant if the tank is empty.

5. **Testing**:
   - Once the system is set up, it will automatically start checking the soil humidity and activate the water pump when necessary.
   - The LED will turn on when the water tank is empty, and the system will stop watering.

## Features:
- Automatic soil humidity monitoring.
- Water tank level checking before watering.
- Water pump control to automatically water the plant.
- LED indicator for water tank status.

## Notes:
- This project was designed to work with the ESP32 development board. If you're using a different board, pin assignments may need to be adjusted.
- The system is designed to be powered by a power supply  **3.3V** , make sure the pump is suitable

╔════════════════════════════════════════════════════════════╗
║                      COMPONENT CONNECTIONS                 ║
╚════════════════════════════════════════════════════════════╝

**Microcontroller**: ESP32 DEVKIT V1 (30 pins)

**Pin connections**:

[1] Soil Humidity Sensor (AZDelivery V1.2 – Capacitive)
    - VCC  ➜  3.3V on ESP32
    - GND  ➜  GND
    - AOUT ➜  GPIO 36 (VP / Analog input)

[2] Water Level Sensor (XKC-Y25-NPN – Non-contact)
    - VCC  ➜  3.3V maby 5V if implemented
    - GND  ➜  GND
    - DOUT ➜  GPIO 15 (Digital input)

[3] Relay Module (SRD-05VDC-SL-C)
    - VCC  ➜  3.3V or 5V
    - GND  ➜  GND
    - IN   ➜  GPIO 16 (Digital output – to control pump)

[4] Submersible Pump (RUNCCI-YUN 3–5V DC)
    - +    ➜  COM of the Relay
    - –    ➜  GND

 **Relay Wiring**:
    - NC  ➜  Not used
    - NO  ➜  +5V from external power supply
    - COM ➜  + of the pump
    - Pump GND ➜  GND

 **Optional LED Indicator** (Water tank empty)
    - Anode (long leg) ➜  GPIO 19
    - Cathode ➜  220Ω Resistor ➜ GND

 **Relay Protection** (often built-in on relay boards):
    - 1N4007 Diode across pump terminals (cathode to +)
    - Optional 100μF 10V capacitor across pump terminals to reduce noise (recommended)

 **Power Supply**:
    - ESP32 powered via USB or 5V regulator
    - Pump + Relay ideally powered from external 5V source (recommended)


