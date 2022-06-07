# Parkinson's Stabilizer

# Description
A personal project to develop a hardware device that helps to stabilize Parkinson's tremor while eating. The goal is to create a spoon that counteracts the movements made by the tremor in a patient's hand.

### Proof of concept
This project started with the creation of a simple proof-of-concept using an Ardiuno Nano, an MPU-6050 and two DC motors. View a short clip below of the results:

<a href="https://youtu.be/xThYBTOFQqI"><img href="https://youtu.be/xThYBTOFQqI" src="https://github.com/foprel/parkinsons-stabilizer/blob/main/assets/screenshot-proof-of-concept.png" alt="poc" width="400" height="200"/></a>

### BLDC control experimentation
Although the proof-of-concept shows that such a device can be made, the DC motors are in now way fast and accurate enough. Therefore, I'm currently experimenting with BLDC motors using field-oriented control. For this, a simple brace has been made in Fusion360 to ensure that the motors can turn across opposite axes. View a short clip below of the experiment:

<a href="https://youtube.com/shorts/653Y602Z9RQ"><img src="https://github.com/foprel/parkinsons-stabilizer/blob/main/assets/screenshot-bldc-motor.png" alt="bldc" width="400" height="200"/></a>

# Getting started

### Prerequisites
- [Arduino Uno Rev3](https://store.arduino.cc/products/arduino-uno-rev3)
- [MPU-6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)
- [AS5600](https://ams.com/as5600) (2x)
- [BLDC motor](#) (2x)
- [SimpleFOC shield V2.0.3](https://simplefoc.com/simplefoc_shield_product_v2) (2x)

### Wiring
TBD

### Installation
TBD

# Contributing
If you have a suggestion that would make this project better, please fork the repo and create a pull request:

1. Fork the project
2. Create your feature branch: `git checkout -b feature/amazing-feature`
3. Commit your changes: `git commit -m "Added some amazing feature"`
4. Push to the branch: `git push origin feature/amazing-feature`
5. Open a pull Request
