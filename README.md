
# Hand Gesture Controlled Car

This project allows you to control a car using hand gestures detected through a webcam. The gestures are detected using OpenCV and the `cvzone` library, and the detected gestures are sent to an ESP32 module to control the car.

## Prerequisites

Before you can run the script, you need to install Python, several Python libraries, and set up the hardware and software for the ESP32.

### Step 1: Install Python

1. **Download Python:**
   - Visit the official [Python website](https://www.python.org/downloads/).
   - Download and install Python for your operating system.

2. **Add Python to PATH:**
   - During installation, ensure that you check the box that says "Add Python to PATH."

### Step 2: Install Required Python Libraries

1. **Open a terminal or command prompt.**

2. **Install the required libraries:**
   - Run the following command to install the necessary Python libraries:

   ```bash
   pip install opencv-python cvzone
   ```

## Step 3: ESP32 Setup

### Step 3.1: Hardware Connections

1. **Connect the ESP32 to your Computer:**
   - Use a USB cable to connect the ESP32 module to your computer.

2. **Wire the ESP32 to the Motor Driver:**
   - Connect the **IN1**, **IN2**, **IN3**, and **IN4** pins of the motor driver to the appropriate GPIO pins on the ESP32.
   - Connect the **ENA** and **ENB** pins on the motor driver to PWM-capable GPIO pins on the ESP32 (e.g., GPIO 13 and GPIO 14).
   - Connect the power supply to the motor driver, and ensure that the ESP32 shares a common ground with the motor driver.

3. **Connect the Motors:**
   - Attach the motor terminals to the output pins on the motor driver.

### Step 3.2: Setting Up Arduino IDE for ESP32

1. **Install Arduino IDE:**
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software) if you don't already have it.

2. **Add ESP32 Board Manager URL:**
   - Open the Arduino IDE.
   - Go to `File` > `Preferences`.
   - In the "Additional Board Manager URLs" field, add the following URL:
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Click "OK."

3. **Install the ESP32 Board Package:**
   - Go to `Tools` > `Board` > `Boards Manager`.
   - Search for "ESP32" and install the `esp32` by Espressif Systems package.

4. **Select the ESP32 Board:**
   - Go to `Tools` > `Board` and select your specific ESP32 model (e.g., `ESP32 Dev Module`).

5. **Choose the Correct Port:**
   - Go to `Tools` > `Port` and select the port to which your ESP32 is connected.

### Step 3.3: Uploading the Code to ESP32

1. **Open the Arduino IDE:**
   - Open the Arduino IDE and create a new sketch.

2. **Write or Paste the Code:**
   - Write or paste your ESP32 code into the Arduino IDE. Ensure that the code includes your Wi-Fi credentials and socket setup(IP and port) correctly.

3. **Compile and Upload the Code:**
   - Click the "Upload" button (right arrow) to compile and upload the code to your ESP32. Ensure that the upload is successful by monitoring the status in the IDE.

4. **Monitor Serial Output:**
   - Open the Serial Monitor (`Tools` > `Serial Monitor`) to view the output from the ESP32. This can help in debugging and confirming that the ESP is functioning correctly.

## Step 4: Run the Python Script

1. **Connect a webcam to your computer.(if you dont have any)**

2. **Run the Python script:**

   ```bash
   python hand_control.py
   ```

   This script will:
   - Open a webcam feed.
   - Detect hand gestures.
   - Send the detected number of fingers up to the ESP32 module over a socket connection.

3. **Press `ESC` to exit.**

## Troubleshooting

- **No hands detected:** Ensure that your webcam is properly positioned and that the `cvzone` detection confidence (`detectionCon`) is set appropriately.
- **Connection issues:** Verify that your ESP32 is on the same network as your computer, and that the IP and port settings are correct.

