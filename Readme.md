# IoT Based Smart Waste Segregator

![Waste Segregator](https://sakthiram17.github.io/WasteSegregator/images/waste_segregator.png)

## Overview

This project is an IoT-based Smart Waste Segregator designed to efficiently manage waste segregation by incorporating ultrasonic sensors, ESP32 module, Arduino, and a rotating platform. The system provides real-time waste bin level updates on a website hosted on [GitHub Pages](https://sakthiram17.github.io/WasteSegregator/). It includes the following components:

1. **Ultrasonic Sensors:**
   - Measure the real-time waste level in the bins and send the data to Firebase through the ESP32 module.

2. **Digital Capacitive Touch Sensor:**
   - Detects movements and signals the Arduino when waste is placed on the segregator.

3. **Arduino:**
   - Determines if the waste is wet or dry based on the touch sensor signal.
   - Controls the rotating platform to place the appropriate bin under the flap.

4. **Rotating Platform:**
   - Moves bins based on waste type, ensuring proper segregation.

5. **Firebase:**
   - Stores and updates waste level data sent by the ESP32 module.

6. **Website:**
   - Displays real-time waste bin levels, providing a user-friendly interface.

## Usage

Visit the hosted website [here](https://sakthiram17.github.io/WasteSegregator/) to check the real-time status of waste bin levels. The website offers insights into waste segregation efficiency and promotes a sustainable waste management approach.

## Repository Structure

- **Arduino Code:**
  - Find the Arduino code for waste segregation in the `arduino_code` directory.

- **Circuit Diagram:**
  - View the circuit diagram in the `circuit_diagram` directory.

- **ESP32 Code:**
  - Access the code for the ESP32 module in the `esp32_code` directory.

- **Website Code:**
  - Explore the code for the website in the `website` directory.

- **Report:**
  - Read the detailed report on the project in the `report` directory.

## Installation

If you want to contribute or explore the project locally:

1. Clone the repository:
   ```bash
   git clone https://github.com/sakthiram17/WasteSegregator.git
   ```

2. Navigate to the project directory:
   ```bash
   cd WasteSegregator
   ```

3. Explore different directories for Arduino code, circuit diagram, ESP32 code, website code, and the project report.

## Features

- **Real-time Waste Bin Levels:** Ultrasonic sensors measure and update the waste bin levels on the website.

- **Automatic Waste Segregation:** The Arduino analyzes data from the touch sensor and controls the rotating platform to segregate waste into appropriate bins.

- **Firebase Integration:** Waste level data is sent to Firebase via the ESP32 module, ensuring centralized and accessible storage.

## Contributing

Feel free to contribute by opening issues or submitting pull requests. Your feedback and contributions are highly appreciated.

## Author

- [Sakthi Ram](https://github.com/sakthiram17)

## Contact

For any inquiries, you can reach out to the author at sakthiram@example.com.

---

**Note:** The IoT-based Smart Waste Segregator is hosted at [https://sakthiram17.github.io/WasteSegregator/](https://sakthiram17.github.io/WasteSegregator/). Explore the real-time waste bin levels and witness efficient waste segregation in action!
