# Stick For Blind

## Overview
The Stick For Blind is an assistive mobility device project that uses an Arduino to detect obstacles in three directions: forward, left, and right. When an obstacle is detected within a certain threshold (30 cm), the device provides auditory feedback by playing distinct tones corresponding to the direction of the obstacle. This portable stick is powered by two 18650 lithium-ion batteries and features custom 3D-printed mounts for all components.

## Features
- **Multi-Directional Obstacle Detection**: Utilizes three HC-SR04 ultrasonic sensors to detect obstacles forward, left, and right.
- **Directional Auditory Feedback**: Emits specific frequencies (262 Hz, 523 Hz, 784 Hz) based on which sensor detects an obstacle closest to the user.
- **Startup Sequence**: Plays a welcoming four-tone melody upon powering on to confirm the system is active.
- **Custom 3D Printed Hardware**: Includes custom mounts for the electronics, sensors, and wire routing clips, ensuring a tidy and secure build on a standard cane or stick.
- **Portable Power**: Runs on a 7.4V power supply (using two 18650 lithium batteries) with an integrated slide switch.

## Components Needed
- 1x Arduino (Uno or Nano compatible)
- 3x HC-SR04 Ultrasonic Distance Sensors
- 1x Piezo Buzzer
- 2x 18650 Lithium-Ion Batteries
- 1x 18650 Dual Battery Holder
- 1x Slide Switch
- Connecting jumper wires
- A walking stick or cane
- 3D Printed Mounts (files provided in the `3d models/` folder)

## Repository Contents

### 1. Arduino Code (`arduino code/`)
The `source code` folder contains the `source code.ino` file.
- **Pins Used**: 
  - Ultrasonic Triggers: Pins 2, 4, 6
  - Ultrasonic Echoes: Pins 7, 8, 9
  - Buzzer: Pin 11
- **Logic**: The code triggers all three sensors sequentially and calculates the distances. If the closest obstacle is within the 30 cm threshold, it sounds the buzzer with a frequency corresponding to that sensor's direction.

### 2. 3D Models (`3d models/`)
The project includes several STL files for 3D printing custom mounts to attach the electronics to the stick:
- `ultrasonic_sensor_mount.stl`: Base mount for the 3 HC-SR04 sensors at the bottom of the stick, angling them appropriately.
- `electronics_mount_bottom.stl` & `electronics_mount_top_cap.stl`: An enclosure box for the Arduino and wiring. The enclosure features the embossed text "Stick For Blind" and a slot for the slide switch.
- `clip.stl`, `stick_mount.stl`, & `wedge.stl`: Assorted clips and mounts used to secure components, including wire channeling, to the cylindrical stick.
- `blind_stick_incomplete.stl`: A reference or work-in-progress model.

### 3. Photos & Diagrams (`photos/`)
- `Circuit Diagram Picture.png`: A clear Fritzing wiring diagram showing the connections between the Arduino Uno, the 3 HC-SR04 sensors, the buzzer, and the power supply.
- `image1.jpg` & `image2.jpg`: Actual photos of the fully assembled project, showcasing the 3D-printed sensor array at the base, white wire channeling, the main electronics enclosure, the external buzzer, and the dual battery pack mounted securely to the stick.

## Assembly & Wiring Instructions

1. **3D Printing**: Print all required STL files from the `3d models` folder.
2. **Mounting**: Attach the sensor mount to the bottom of the stick and insert the three HC-SR04 sensors. Secure the electronics enclosure and battery holder further up the stick using the provided clips.
3. **Wiring**: Follow the `Circuit Diagram Picture.png`. 
   - Connect the Trig pins to Arduino D2, D4, and D6.
   - Connect the Echo pins to Arduino D7, D8, and D9.
   - Connect the Buzzer positive terminal to Arduino D11.
   - Connect all component GNDs to Arduino GND and VCCs to Arduino 5V.
   - Wire the slide switch in series with the battery's positive terminal before connecting it to the Arduino's Vin pin.
4. **Code Upload**: Open `arduino code/source code/source code.ino` in the Arduino IDE and upload it to your board. Ensure your baud rate is set to 115200 if you want to view the serial monitor output.
5. **Usage**: Flip the slide switch to turn it on. You will hear a startup melody. As you move the stick near objects, the buzzer will emit tones indicating the direction of the closest obstacle.

## License
This project is open for personal and educational use. Feel free to modify the code and 3D models to fit your specific needs!
