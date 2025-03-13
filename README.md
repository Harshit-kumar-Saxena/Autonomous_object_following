# Object Tracking and ESP8266 Control

## Overview
This project involves real-time object tracking using OpenCV and controlling an ESP8266-based system via HTTP requests. The system captures video from a webcam, processes frames to detect objects of specific colors, and sends movement commands to the ESP8266 based on object position.

## Features
- **Real-time object tracking** using OpenCV and HSV color filtering.
- **Multi-threaded webcam stream processing** for efficient frame handling.
- **Multi-threaded ESP8266 communication** using a queue system to avoid blocking operations.
- **Automatic movement control** based on object position within the frame.
- **Adjustable color selection** via trackbars in OpenCV.

## Requirements

### **Hardware**
- Computer with a webcam
- ESP8266 board
- Wi-Fi network for ESP8266 communication

### **Software & Libraries**
```sh
Python 3.x
OpenCV (cv2)
NumPy (numpy)
Requests (requests)
Threading (threading)
Queue (queue)

```

### **Installation**

### 1️⃣ **Install Dependencies**
Ensure Python and required libraries are installed:
```sh
pip install opencv-python numpy requests
```

### 2️⃣ **Connect ESP8266 to Wi-Fi**
Upload an ESP8266 firmware that listens for HTTP requests on an IP (e.g., `http://192.168.4.1`).

### 3️⃣ **Run the Script**
```sh
python object_tracking.py
```

---

## ⚙️ How It Works

1. The webcam captures live frames.  
2. The system detects objects based on selected **HSV color ranges**.  
3. The position of the detected object determines the movement command:  
   - **Left (`L`)**: Object is on the left side.
   - **Right (`R`)**: Object is on the right side.
   - **Forward (`F`)**: Object is centered but above a threshold.
   - **Stop (`S`)**: Object is below a certain area.
4. Commands are sent asynchronously to the **ESP8266**.  
5. The ESP8266 executes the movement instructions accordingly.  

---



## 🎮 Usage

- Adjust the **color detection** using the **Trackbar** in OpenCV.  
- Press **'q'** to stop the program and send a **stop command** to ESP8266.  

---

## 🔧 Potential Improvements
- Implement a **PID controller** for smoother motion control.  
- Enhance color detection accuracy with **adaptive thresholding**.  
- Integrate **deep learning** for **object classification**.  

---

## 📜 License
This project is **open-source** and free to use.  
