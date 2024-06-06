# Flammable Gas Leakage Detection using MQ-5 Sensor and Arduino Uno microcontroller.

This project involves the design and implementation of a sensor system to detect flammable gases. The project includes a circuit schematic created using Proteus ISIS, a `main.c` code programmed into an Arduino Uno (ATmega328p), and a detailed report explaining the circuit schematic, code, and other relevant details.

## Table of Contents
- [Description](#description)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)
- [Acknowledgments](#acknowledgments)

## Description
The flammable gas detection sensor project was created as part of a university course, CSE 324 Embedded Systems. The project was done in collaboration with [@bodaqwef] (https://github.com/bodaqwef) and aims to detect the presence of flammable gases and provide an alert through LEDs, a buzzer, and an LCD screen.

## Installation
To set up the project locally, follow these steps:

1. **Clone the Repository:**
    ```bash
    git clone [https://github.com/yourusername/flammable-gas-sensor.git](https://github.com/unearthlyzal/MQ5-Sensor-with-LCD-Display.git)
    cd MQ5-Sensor-with-LCD-Display
    ```

2. **Open the Circuit Schematic:**
    - Open the `circuit_schematic.dsn` file using Proteus ISIS.exe.

3. **Program the Microcontroller:**
    - Upload the `main.c` code to the Arduino Uno (ATmega328p) using the Arduino IDE or any compatible programmer (original code was written on Microchip Studio).

## Usage
1. **Setting Up the Circuit:**
    - Assemble the circuit as per the schematic in `circuit_schematic.dsn`.

2. **Running the Sensor:**
    - Power up the circuit. A green LED should light up
    - The sensor will begin detecting flammable gases and alert you if a gas is detected, through red LED lighting up, buzzer sounding, and LCD screen displaying a warning message.

## Features
- Detection of flammable gases.
- Real-time alert system.

## Contributing
Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
Maintainers:
- [Salma Noureddin](mailto:salmaamin2011@gmail.com)
- [AbdulRahman Amr](mailto:colleague-email@example.com)

## Acknowledgments
- University course instructor, Dr Rami Zewail.
- AbdulRahman Amr for his much appreciated due diligence.
- Resources and libraries used in the project, specifically The Engineering Projects for most of the components used.
