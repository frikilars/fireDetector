# fireDetector
![image](https://github.com/user-attachments/assets/d9502922-e774-40de-8351-8a50f72e2575)
<h3> Embedded System Fire Detector</h3> without waterpumo & flamesensor


![image](https://github.com/user-attachments/assets/2d0a81a0-534c-4eff-872d-155c4b2e985f)
<h3> IOT Fire Detector</h3> without waterpumo & flamesensor
<h3>Tambahkan datastream di blink dengan</h3>
🟢 1. Datastream untuk Suhu (Temperature)
Name: Temperature
Type: Virtual Pin
Virtual Pin: V0
Data type: Double
Units: °C
Min/Max: Misalnya 0 - 100
Widget / Display: Gauge, Value Display, atau Chart

🟡 2. Datastream untuk Gas (MQ2 Sensor)
Name: Gas Sensor
Type: Virtual Pin
Virtual Pin: V1
Data type: Integer
Units: Misalnya: ppm (jika dikalibrasi) atau Analog
Min/Max: 0 - 4095 (karena ADC ESP32 12-bit)
Widget / Display: Gauge, Value Display, atau Chart

🔴 3. Datastream untuk Flame (Sensor Api)
Name: Flame
Type: Virtual Pin
Virtual Pin: V2
Data type: Integer (gunakan 0 atau 1)
Min/Max: 0 - 1
Widget / Display: LED, Value Display, atau Notification trigger
